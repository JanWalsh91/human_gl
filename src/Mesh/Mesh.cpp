#include "Mesh.hpp"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

Mesh::Mesh( void ) : Mesh::Mesh(
	Vector(0, 0, 0), // default rotation
	Vector(0, 0, 0), // default rotation origin
	Vector(1, 1, 1), // default scaling
	Vector(0, 0, 0), // default scaling origin
	Vector(0, 0, 0), // default translation
	Vector(1, 1, 1)  // default color
) {
	// this->updateModelMatrix();
}

Mesh::Mesh( Vector rotationAngles, Vector rotationOrigin, Vector scale, Vector scaleOrigin, Vector translation, Vector color, std::string const & name ) :
parentMesh(nullptr),
rotationAngles(rotationAngles),
rotationOrigin(rotationOrigin),
scale(scale),
scaleOrigin(scaleOrigin),
translation(translation),
color(color),
name(name) {}

Mesh::Mesh( Vector rotationAngles, Vector rotationOrigin, Vector scale, Vector scaleOrigin, Vector translation, Vector color ) :
	parentMesh(nullptr),
	rotationAngles(rotationAngles),
	rotationOrigin(rotationOrigin),
	scale(scale),
	scaleOrigin(scaleOrigin),
	translation(translation),
	color(color), 
	name("Default mesh") {

		// std::cout << "New mesh Model Matrix: \n" << this->modelMatrix << std::endl;
		// this->updateModelMatrix();
		// std::cout << "New mesh Model Matrix after update: \n" << this->modelMatrix << std::endl;
}

Mesh::Mesh( Mesh const & mesh ) {
	*this = mesh;
}

Mesh::~Mesh( void ) {}

Mesh & Mesh::operator=( Mesh const & rhs ) {
	this->meshes = rhs.meshes;
	this->modelMatrix = rhs.modelMatrix;
	this->rotationAngles = rhs.rotationAngles;
	this->translation = rhs.translation;
	this->scale = rhs.scale;
	this->color = rhs.color;
	return *this;
}

// renders mesh
void Mesh::render( Shader & s ) {
	s.setMatrix("modelMatrix",  this->modelMatrix);
	s.setVector("color", this->color);
	glDrawArrays(GL_TRIANGLES, 0, 36);
}

// renders mesh and child meshes
void Mesh::recursivelyRender( Shader & s ) {
	this->render( s );
	for ( Mesh* mesh : this->meshes ) {
		mesh->recursivelyRender( s );
	};
}

Vector	Mesh::getRotationCenter() {
	Vector t = this->rotationOrigin;

	Mesh *m = this->parentMesh;
	while ( m ) {
		t = t + m->rotationOrigin;
		m = m->parentMesh;
	}
	return t;
}

Vector  Mesh::getScaleCenter() {
	Vector t = this->scaleOrigin;
	
	Mesh *m = this->parentMesh;
	while ( m ) {
		t = t + m->scaleOrigin;
		m = m->parentMesh;
	}
	return t;
}

void		Mesh::updateModelMatrix(Matrix & parentModelMatrix) {
	this->scaleMatrix = Matrix(this->scale, Matrix::TYPE::SCALE);
	this->translateMatrix = Matrix(this->translation, Matrix::TYPE::TRANSLATE);
	this->rotateMatrix = Matrix(this->rotationAngles[0], Matrix::TYPE::ROTATION_X)
						* Matrix(this->rotationAngles[1], Matrix::TYPE::ROTATION_Y)
						* Matrix(this->rotationAngles[2], Matrix::TYPE::ROTATION_Z);
						

	Vector rotationTrueOrigin = this->getRotationCenter();
	Vector scaleTrueOrigin = this->getScaleCenter();

	Vector rotationOriginTmp = rotationTrueOrigin * this->scaleMatrix;
	Matrix scaleTranslation1 = Matrix(scaleTrueOrigin * (-1), Matrix::TYPE::TRANSLATE);
	Matrix scaleTranslation2 = Matrix(scaleTrueOrigin, Matrix::TYPE::TRANSLATE);
	
	Matrix rotationTranslation1 = Matrix(rotationOriginTmp * (-1), Matrix::TYPE::TRANSLATE);
	Matrix rotationTranslation2 = Matrix(rotationOriginTmp, Matrix::TYPE::TRANSLATE);

	this->modelMatrix = ( parentModelMatrix * (scaleTranslation1 * this->scaleMatrix)) * scaleTranslation2;
	this->modelMatrix = ((this->modelMatrix * rotationTranslation1) * this->rotateMatrix) * rotationTranslation2;
	this->modelMatrix = this->modelMatrix * this->translateMatrix;

	rotationTranslation1 = Matrix(rotationOrigin * (-1), Matrix::TYPE::TRANSLATE);
	rotationTranslation2 = Matrix(rotationOrigin, Matrix::TYPE::TRANSLATE);

	this->inheritedModelMatrix = ( parentModelMatrix * (rotationTranslation1 * this->rotateMatrix)) * rotationTranslation2;
	this->inheritedModelMatrix = this->inheritedModelMatrix * this->translateMatrix;
}

Matrix&		Mesh::recursivelyUpdateModelMatrix(Matrix & parentModelMatrix) {
	this->updateModelMatrix(parentModelMatrix);
	// this->updateInheritedModelMatrix();
	
	std::cout << this->meshes.size() << std::endl;

	// for (Mesh* mesh : this->meshes) {
	// 	mesh->getModelMatrix() = mesh->recursivelyUpdateModelMatrix() * this->inheritedModelMatrix;
	// }
	// return this->inheritedModelMatrix;
	for (Mesh* mesh : this->meshes) {
		mesh->getModelMatrix() = this->inheritedModelMatrix * mesh->recursivelyUpdateModelMatrix(this->inheritedModelMatrix);
	}
	return this->inheritedModelMatrix;
}

Matrix &	Mesh::getModelMatrix() {
	return this->modelMatrix;
}

void Mesh::append( Mesh* mesh ) {
	this->meshes.push_back(mesh);
	mesh->parentMesh = this;
}
