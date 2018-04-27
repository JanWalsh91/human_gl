#include "Mesh.hpp"

Mesh::Mesh( void ) : Mesh::Mesh(
	Vector(0, 0, 0), // default rotation
	Vector(1, 1, 1), // default scaling
	Vector(0, 0, 0), // default translation
	Vector(1, 1, 1)  // defualt color
) {}

Mesh::Mesh( Vector rotationAngles, Vector scale, Vector translation, Vector color ) :
	rotationAngles(rotationAngles),
	scale(scale),
	translation(translation),
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
void Mesh::render() {
	// set matrix: need unform matrix reference
	// glUniformMatrix4fv(matrixRef, 1, GL_FALSE, this->modelMatrix);
	// switch vbo
	// glBindVertexArray(this->VBO/VAO);
	// draw arrays
	// glDrawArrays(GL_TRIANGLES, 0, 8); // 8 vertices per mesh
}

// renders mesh and child meshes
void Mesh::recursivelyRender() {
	this->render();
	for_each(meshes.begin(), meshes.end(), []( Mesh &mesh ) {
		mesh.recursivelyRender();
	});
}

// updates Model Matrix based on rot, trans, scale vectors
void	Mesh::updateModelMatrix() {
	std::cout << "Updatemodel matrix" << std::endl;
	// reset matrix
	this->modelMatrix = Matrix();
	// scale
	this->modelMatrix *= Matrix(this->scale, Matrix::TYPE::SCALE);
	// rotate
	this->modelMatrix *= Matrix(this->rotationAngles[0], Matrix::TYPE::ROTATION_X);
	this->modelMatrix *= Matrix(this->rotationAngles[1], Matrix::TYPE::ROTATION_Y);
	this->modelMatrix *= Matrix(this->rotationAngles[2], Matrix::TYPE::ROTATION_Z);
	// translate
	this->modelMatrix *= Matrix(this->translation, Matrix::TYPE::TRANSLATE);
}

// updates Model Matrix based on rot, trans, scale vectors and parent Model Matrix
void	Mesh::updateModelMatrix( Matrix & parentModelMatrix ) {
	this->updateModelMatrix();
	this->modelMatrix *= parentModelMatrix;
}

// recursively updates meshes' model matrices. (for parent mesh)
void	Mesh::recursivelyUpdateModelMatrix() {
	this->updateModelMatrix();
	// Mesh m = this;
	for_each(meshes.begin(), meshes.end(), [ this ]( Mesh &mesh ) {
		mesh.recursivelyUpdateModelMatrix( this->modelMatrix );
	});
}

// recursively updates meshes' model matrices. (for child meshes)
void	Mesh::recursivelyUpdateModelMatrix( Matrix & parentModelMatrix ) {
	this->updateModelMatrix( parentModelMatrix );
	for_each(meshes.begin(), meshes.end(), [ this ]( Mesh &mesh ) {
		mesh.recursivelyUpdateModelMatrix( this->modelMatrix );
	});
}