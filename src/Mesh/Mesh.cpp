#include "Mesh.hpp"

Mesh::Mesh( void ) : Mesh::Mesh(
	Vector(0, 0, 0), // default rotation
	Vector(0, 0, 0), // default rotation origin
	Vector(1, 1, 1), // default scaling
	Vector(0, 0, 0), // default scaling origin
	Vector(0, 0, 0), // default translation
	Vector(1, 1, 1)  // default color
) {}

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
	name("Default mesh") {}

Mesh::Mesh( Mesh const & mesh ) {
	*this = mesh;
}

Mesh::~Mesh( void ) {}

Mesh & Mesh::operator=( Mesh const & rhs ) {
	this->modelMatrix = rhs.modelMatrix;
	this->rotationOrigin = rhs.rotationOrigin;
	this->rotationAngles = rhs.rotationAngles;
	this->translation = rhs.translation;
	this->scale = rhs.scale;
	this->color = rhs.color;
	this->name = rhs.name;
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
	}
}

Matrix &	Mesh::getModelMatrix() {
	return this->modelMatrix;
}

void Mesh::append( Mesh* mesh ) {
	this->meshes.push_back(mesh);
	mesh->parentMesh = this;
}

Matrix Mesh::calculateRotationMatrix( Vector & absRotCtr ) {
	Matrix translation1( absRotCtr * (-1), Matrix::TYPE::TRANSLATE );
	Matrix translation2( absRotCtr, Matrix::TYPE::TRANSLATE );

	Matrix finalRotation = translation1 * Matrix( this->rotationAngles[0], Matrix::TYPE::ROTATION_X );
	finalRotation = finalRotation * Matrix( this->rotationAngles[1], Matrix::TYPE::ROTATION_Y );
	finalRotation = finalRotation * Matrix( this->rotationAngles[2], Matrix::TYPE::ROTATION_Z );
	finalRotation = finalRotation * translation2;

	return finalRotation;
}

Matrix Mesh::calculateScalingMatrix( Vector & absSclCtr ) {
	Matrix translation1( absSclCtr * (-1), Matrix::TYPE::TRANSLATE );
	Matrix translation2( absSclCtr, Matrix::TYPE::TRANSLATE );
	Matrix finalScaling = translation1 * Matrix( this->scale, Matrix::TYPE::SCALE );
	finalScaling = finalScaling * translation2;

	return finalScaling;
}

Mesh* Mesh::getByColor(Vector color) {
	Mesh* tmp = nullptr;

	if (color == this->color) {
		return this;
	}
	for (Mesh* mesh : this->meshes) {
		if ((tmp = mesh->getByColor(color)) != nullptr) {
			break;
		}
	}
	return tmp;
}

void Mesh::recursivelyUpdateMatrices( Matrix & parentMatrix, Vector parentPos ) {
	Vector absSclCtr = this->scaleOrigin;
	this->scaleMatrix = this->calculateScalingMatrix( absSclCtr );
	Vector absRotCtr = ( this->scaleMatrix * this->rotationOrigin );
	this->translateMatrix = Matrix( this->translation, Matrix::TYPE::TRANSLATE );
	this->rotateMatrix = this->calculateRotationMatrix( absRotCtr );
	Matrix newParentMatrix = (this->rotateMatrix * this->translateMatrix) * parentMatrix;
	this->modelMatrix = ((this->scaleMatrix * this->rotateMatrix) * this->translateMatrix) * parentMatrix;
	Vector newParentPos = parentPos + parentMatrix * this->translation;
	
	for ( Mesh* mesh : this->meshes ) {
		mesh->recursivelyUpdateMatrices( newParentMatrix, newParentPos );
	}
}

void Mesh::setRotationAngles(Vector  newAngle) {
	this->rotationAngles = newAngle;
}

void Mesh::setTranslation(Vector  translation) {
	this->translation = translation;
}

void Mesh::setScale(Vector  scale) {
	this->scale = scale;
}

void Mesh::setColor(Vector  color) {
		this->color = color;
}

Vector const & Mesh::getRotationAngles() {
	return this->rotationAngles;
}

Vector const & Mesh::getTranslation() {
	return this->translation;
}

Vector const & Mesh::getScale() {
	return this->scale;
}

Vector const & Mesh::getColor() {
	return this->color;
}

std::string  & Mesh::getName() {
	return this->name;
}
