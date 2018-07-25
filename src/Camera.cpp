#include "Camera.hpp"

Camera::Camera() {
	this->camPos = Vector(0, 0, -10);
	this->camRight = Vector(1, 0, 0);
	this->camUp = Vector(0, 1, 0);
	this->camDir = Vector(0, 0, 1);
	this->viewMatrix = Matrix(this->camPos * -1 , Matrix::TYPE::TRANSLATE);
	this->viewMatrix[0] = this->camRight[0];
	this->viewMatrix[1] = this->camRight[1];
	this->viewMatrix[2] = this->camRight[2];
	this->viewMatrix[4] = this->camUp[0];
	this->viewMatrix[5] = this->camUp[1];
	this->viewMatrix[6] = this->camUp[2];
	this->viewMatrix[8] = this->camDir[0];
	this->viewMatrix[9] = this->camDir[1];
	this->viewMatrix[10] = this->camDir[2];
}

Camera::~Camera() {}

Matrix const & Camera::getViewMatrix() {
	return this->viewMatrix;
}

void Camera::setCameraDirection(Vector newDirection) {
	this->camDir = newDirection;
	this->viewMatrix[8] = this->camDir[0];
	this->viewMatrix[9] = this->camDir[1];
	this->viewMatrix[10] = this->camDir[2];
}

Vector const & Camera::getCameraDirection() {
	return this->camDir;
}
