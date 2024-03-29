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
}

HumanGL::HumanGL( HumanGL const & HumanGL ) {
	*this = HumanGL;
}

HumanGL::~HumanGL( void ) {
	for (auto c: this->cycles) {
		delete c;
	}
}

HumanGL & HumanGL::operator=( HumanGL const & rhs ) {
	return *this;
}

void HumanGL::initCycles() {
	this->cycles.push_back( new Cycle(Cycle::Type::STAND) );
	this->cycles.push_back( new Cycle(Cycle::Type::WALK) );
	this->cycles.push_back( new Cycle(Cycle::Type::JUMP) );
	this->cycles.push_back( new Cycle(Cycle::Type::MOON_WALK) );
	this->cycles.push_back( new Cycle(Cycle::Type::WAVE) );
	this->cycles.push_back( new Cycle(Cycle::Type::PUSH_UP) );
}

GLuint HumanGL::getVBO() const {
	return this->VBO;
}

GLuint HumanGL::getVAO() const {
	return this->VAO;
}

const std::vector<Cycle*>& HumanGL::getCycles() {
	return this->cycles;
}
