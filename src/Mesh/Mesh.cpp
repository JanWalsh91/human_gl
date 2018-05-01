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

// Vector	Mesh::getRotationCenter() {
// 	Vector t = this->rotationOrigin;

// 	Mesh *m = this->parentMesh;
// 	while ( m ) {
// 		t = t + m->rotationOrigin;
// 		m = m->parentMesh;
// 	}
// 	return t;
// }

// Vector  Mesh::getScaleCenter() {
// 	Vector t = this->scaleOrigin;
	
// 	Mesh *m = this->parentMesh;
// 	while ( m ) {
// 		t = t + m->scaleOrigin;
// 		m = m->parentMesh;
// 	}
// 	return t;
// }

// void		Mesh::updateModelMatrix(Matrix & parentModelMatrix) {
// 	this->scaleMatrix = Matrix(this->scale, Matrix::TYPE::SCALE);
// 	this->translateMatrix = Matrix(this->translation, Matrix::TYPE::TRANSLATE);
// 	this->rotateMatrix = Matrix(this->rotationAngles[0], Matrix::TYPE::ROTATION_X)
// 						* Matrix(this->rotationAngles[1], Matrix::TYPE::ROTATION_Y)
// 						* Matrix(this->rotationAngles[2], Matrix::TYPE::ROTATION_Z);
						

// 	Vector rotationTrueOrigin = this->getRotationCenter();
// 	Vector scaleTrueOrigin = this->getScaleCenter();

// 	Vector rotationOriginTmp = rotationTrueOrigin * this->scaleMatrix;
// 	Matrix scaleTranslation1 = Matrix(scaleTrueOrigin * (-1), Matrix::TYPE::TRANSLATE);
// 	Matrix scaleTranslation2 = Matrix(scaleTrueOrigin, Matrix::TYPE::TRANSLATE);
	
// 	Matrix rotationTranslation1 = Matrix(rotationOriginTmp * (-1), Matrix::TYPE::TRANSLATE);
// 	Matrix rotationTranslation2 = Matrix(rotationOriginTmp, Matrix::TYPE::TRANSLATE);

// 	this->modelMatrix = ( parentModelMatrix * (scaleTranslation1 * this->scaleMatrix)) * scaleTranslation2;
// 	this->modelMatrix = ((this->modelMatrix * rotationTranslation1) * this->rotateMatrix) * rotationTranslation2;
// 	this->modelMatrix = this->modelMatrix * this->translateMatrix;

// 	rotationTranslation1 = Matrix(rotationOrigin * (-1), Matrix::TYPE::TRANSLATE);
// 	rotationTranslation2 = Matrix(rotationOrigin, Matrix::TYPE::TRANSLATE);

// 	this->inheritedModelMatrix = ( parentModelMatrix * (rotationTranslation1 * this->rotateMatrix)) * rotationTranslation2;
// 	this->inheritedModelMatrix = this->inheritedModelMatrix * this->translateMatrix;
// }

// Matrix&		Mesh::recursivelyUpdateModelMatrix(Matrix & parentModelMatrix) {
// 	this->updateModelMatrix(parentModelMatrix);
// 	// this->updateInheritedModelMatrix();
	
// 	std::cout << this->meshes.size() << std::endl;

// 	// for (Mesh* mesh : this->meshes) {
// 	// 	mesh->getModelMatrix() = mesh->recursivelyUpdateModelMatrix() * this->inheritedModelMatrix;
// 	// }
// 	// return this->inheritedModelMatrix;
// 	for (Mesh* mesh : this->meshes) {
// 		mesh->getModelMatrix() = this->inheritedModelMatrix * mesh->recursivelyUpdateModelMatrix(this->inheritedModelMatrix);
// 	}
// 	return this->inheritedModelMatrix;
// }

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

	// std::cout << "translation1: \n" << translation1 << std::endl;
	// std::cout << "translation2: \n" << translation2 << std::endl;
	Matrix finalRotation = translation1 * Matrix( this->rotationAngles[0], Matrix::TYPE::ROTATION_X );
	finalRotation = finalRotation * Matrix( this->rotationAngles[1], Matrix::TYPE::ROTATION_Y );
	finalRotation = finalRotation * Matrix( this->rotationAngles[2], Matrix::TYPE::ROTATION_Z );
	finalRotation = finalRotation * translation2;

	return finalRotation;
}

Matrix Mesh::calculateScalingMatrix( Vector & absSclCtr ) {
	Matrix translation1( absSclCtr * (-1), Matrix::TYPE::TRANSLATE );
	// std::cout << "translation1: \n" << translation1 << std::endl;
	Matrix translation2( absSclCtr, Matrix::TYPE::TRANSLATE );
	// std::cout << "translation2: \n" << translation2 << std::endl;

	Matrix finalScaling = translation1 * Matrix( this->scale, Matrix::TYPE::SCALE );
	finalScaling = finalScaling * translation2;

	return finalScaling;
}

// Matrix Mesh::scaleRotCtr() {
// 	// move 
// }
Mesh* Mesh::getByColor(Vector color) {
	Mesh* tmp = nullptr;

	if (color == this->color) {
		std::cout << "Founded: " << this->name << std::endl;
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
	// std::cout << "recursivelyUpdateMatrices " << this->name << "  parentPos: " << parentPos << std::endl;
	// std::cout << "parentMatrix: \n" << parentMatrix << std::endl;
	// Update scaling and rotation centers based on parentPos 

	Vector absSclCtr = /*parentPos + */this->scaleOrigin;
	// Vector absSclCtr = parentPos + ( parentMatrix * this->translation ) + this->scaleOrigin;
	this->scaleMatrix = this->calculateScalingMatrix( absSclCtr );
	// std::cout << "this->scaleMatrix: \n" << this->scaleMatrix << std::endl;
	// std::cout << "this->scaleMatrix * this->rotationOrigin: \n" << (this->scaleMatrix * this->rotationOrigin) << std::endl;
	Vector absRotCtr =  /*parentPos + */( this->scaleMatrix * this->rotationOrigin );
	// Vector absRotCtr = ( parentMatrix * this->translation ) + ( this->scaleMatrix * this->rotationOrigin );
	// std::cout << "( parentMatrix * this->translation ): " << ( parentMatrix * this->translation ) << std::endl;

	// std::cout << "absRotCtr: " << absRotCtr << std::endl;
	// std::cout << "absSclCtr: " << absSclCtr << std::endl;

	// Update translateMatrix
	this->translateMatrix = Matrix( this->translation, Matrix::TYPE::TRANSLATE );

	// Update rotateMatrix
	this->rotateMatrix = this->calculateRotationMatrix( absRotCtr );
	// this->rotateMatrix = this->calculateRotationMatrix( this->rotationOrigin );
	
	// Calculate newParentMatrix
	Matrix newParentMatrix = (this->rotateMatrix * this->translateMatrix) * parentMatrix;
	// this->rotateMatrix = this->calculateRotationMatrix( absRotCtr );
	// Matrix newParentMatrix = (parentMatrix * this->rotateMatrix) * this->translateMatrix;

	// Update scalingMatrix
	// this->scaleMatrix = this->calculateScalingMatrix( this->scaleOrigin );

	// Calculate modelMatrix
	// this->modelMatrix = ((parentMatrix * this->scaleMatrix) * this->rotateMatrix) * this->translateMatrix;
	this->modelMatrix = ((this->scaleMatrix * this->rotateMatrix) * this->translateMatrix) * parentMatrix;

	// std::cout << "this->modelMatrix: \n" << this->modelMatrix << std::endl;
	// std::cout << " parentMatrix: \n" << parentMatrix << std::endl;

	// Calculate newParentPos
	Vector newParentPos = parentPos + parentMatrix * /*parentPos +*/ this->translation;
	// Vector newParentPos = this->translation;
	// newParentPos = Vector(0, 0, 0);

	for ( Mesh* mesh : this->meshes ) {
		mesh->recursivelyUpdateMatrices( newParentMatrix, newParentPos );
	}
}

// Need to pass along info about parentPos which is modified by a matrix each time we go further in recursion
// Update scaling and rotation centers based on parentPos
// absSclCtr = parentPos + (ParentMatrix * this->pos) + this->slcCtr;
// this->scaleMatrix = Matrix(absSclCtr, Matrix::TYPE::SCALE);
// absRotCtr = parentPos + (ParentMatrix * this->pos) + (this->scaleMatrix * this->rotCtr);

// ParentMatrix contains all transformations of coord system having only applied rotation and translation. Not scaling.
// How to calculate the next ParentMatrix?
	// newParentMatrix = ParentMatrix * this->rotateMatrix * this->transleMatrix;

// How to calculate current mesh's Final Model Matrix?
	// this->finalModelMatrix = ParentMatrix * this->rotateMatrix * this->scaleMatrix * this->translation;

// newParentPos = parentPos + this->translation;

// for each child mesh :
	// updateMatrices( newParentMatrix, parentPos )