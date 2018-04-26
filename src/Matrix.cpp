#include "Matrix.hpp"

Matrix::Matrix( void ) {}

Matrix::Matrix( unsigned size ) {
	this->m = new float[size * size];
	m[0] = 1;
	m[5] = 1;
	m[10] = 1;
	m[15] = 1;
}

Matrix::Matrix( Matrix const & matrix ) {
	*this = matrix;
}

Matrix::~Matrix( void ) {
}

Matrix & Matrix::operator=( Matrix const & rhs ) {
	// memcpy(this->m, rhs.m, sizeof(float) * 16);
	(void)rhs.m;
	(void)rhs;
	return *this;
}