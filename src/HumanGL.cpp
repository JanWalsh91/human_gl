#include "HumanGL.hpp"

HumanGL::HumanGL( void ) {
	float cubeArray[] = {
		-1.f, -1.f, 1.f,
		1.f, -1.f, 1.f,
		-1.f, 1.f, 1.f,

		-1.f, 1.f, 1.f,
		1.f, -1.f, 1.f,
		1.f, 1.f, 1.f,

		-1.f, 1.f, 1.f,
		1.f, 1.f, 1.f,
		-1.f, 1.f, -1.f,

		-1.f, 1.f, -1.f,
		1.f, 1.f, 1.f,
		1.f, 1.f, -1.f,

		-1.f, 1.f, -1.f,
		1.f, 1.f, -1.f,
		-1.f, -1.f, -1.f,

		-1.f, -1.f, -1.f,
		1.f, 1.f, -1.f,
		1.f, -1.f, -1.f,

		-1.f, -1.f, -1.f,
		1.f, -1.f, -1.f,
		-1.f, -1.f, 1.f,

		-1.f, -1.f, 1.f,
		1.f, -1.f, -1.f,
		1.f, -1.f, 1.f,

		1.f, -1.f, 1.f,
		1.f, -1.f, -1.f,
		1.f, 1.f, 1.f,

		1.f, 1.f, 1.f,
		1.f, -1.f, -1.f,
		1.f, 1.f, -1.f,

		-1.f, -1.f, -1.f,
		-1.f, -1.f, 1.f,
		-1.f, 1.f, -1.f,

		-1.f, 1.f, -1.f,
		-1.f, -1.f, 1.f,
		-1.f, 1.f, 1.f
	};


	glGenVertexArrays(1, &this->VAO);
	glGenBuffers(1, &this->VBO);
	glBindVertexArray(this->VAO);
	glBindBuffer(GL_ARRAY_BUFFER, this->VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(cubeArray), cubeArray, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);


	this->rotationSpeed[0] = 1.0f;
	this->rotationSpeed[1] = 0.0f;
	this->rotationSpeed[2] = 0.0f;
	// delete cubes
}

HumanGL::HumanGL( HumanGL const & HumanGL ) {
	*this = HumanGL;
}

HumanGL::~HumanGL( void ) {
}

HumanGL & HumanGL::operator=( HumanGL const & rhs ) {
	return *this;
}











