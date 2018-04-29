#include "Mesh.hpp"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

Mesh::Mesh( void ) : Mesh::Mesh(
	Vector(0, 0, 0), // default rotation
	Vector(1, 1, 1), // default scaling
	Vector(0, 0, 0), // default translation
	Vector(0, 0, 0), // default origin
	Vector(1, 1, 1)  // default color
) {
	this->updateModelMatrix();
}

Mesh::Mesh( Vector rotationAngles, Vector scale, Vector translation, Vector origin, Vector color ) :
	rotationAngles(rotationAngles),
	scale(scale),
	translation(translation),
	origin(origin),
	color(color) {
		std::cout << "New mesh Model Matrix: \n" << this->modelMatrix << std::endl;
		this->updateModelMatrix();
		std::cout << "New mesh Model Matrix after update: \n" << this->modelMatrix << std::endl;
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
	for ( Mesh & mesh : this->meshes ) {
		mesh.recursivelyRender( s );
	};
}

// updates Model Matrix based on rot, trans, scale vectors
void	Mesh::updateModelMatrix() {
//	std::cout << "Updatemodel matrix" << std::endl;
	// reset matrix
	this->scaleMatrix = Matrix(this->scale, Matrix::TYPE::SCALE);
	// translate
	this->translateMatrix = Matrix(this->translation, Matrix::TYPE::TRANSLATE);
	// rotate
	this->rotateMatrix = Matrix(this->rotationAngles[0], Matrix::TYPE::ROTATION_X)
						* Matrix(this->rotationAngles[1], Matrix::TYPE::ROTATION_Y)
						* Matrix(this->rotationAngles[2], Matrix::TYPE::ROTATION_Z);
	this->modelMatrix = this->scaleMatrix * this->translateMatrix * this->rotateMatrix;
//	this->modelMatrix = this->scaleMatrix * this->rotateMatrix * this->translateMatrix;
}

// updates Model Matrix based on rot, trans, scale vectors and parent Model Matrix
void	Mesh::updateModelMatrix( Matrix & scale, Matrix & translate, Matrix & rotate ) {
	this->updateModelMatrix();
	this->scaleMatrix *= scale;
	this->translateMatrix *= translate;
	this->rotateMatrix *= rotate;
	this->modelMatrix = this->scaleMatrix * this->translateMatrix * this->rotateMatrix;
//	this->modelMatrix = this->scaleMatrix * this->rotateMatrix * this->translateMatrix;
}

// recursively updates meshes' model matrices. (for parent mesh)
void	Mesh::recursivelyUpdateModelMatrix() {
	this->updateModelMatrix();
	// Mesh m = this;

	for (Mesh & mesh: this->meshes) {
		mesh.recursivelyUpdateModelMatrix( this->scaleMatrix, this->translateMatrix, this->rotateMatrix );
	}

}

// recursively updates meshes' model matrices. (for child meshes)
void	Mesh::recursivelyUpdateModelMatrix( Matrix & scale, Matrix & translate, Matrix & rotate ) {
	this->updateModelMatrix( scale, translate, rotate );

	for (Mesh & mesh: this->meshes) {
		mesh.recursivelyUpdateModelMatrix( this->scaleMatrix, this->translateMatrix, this->rotateMatrix );
	}

}

Matrix &	Mesh::getModelMatrix() {
	return this->modelMatrix;
}

void Mesh::append( Mesh & mesh ) {
	this->meshes.push_back(mesh);
}