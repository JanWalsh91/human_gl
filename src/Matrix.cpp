#include "Matrix.hpp"

Matrix::Matrix( void ) {
	// this->m = {
	// 	1, 0, 0, 0,
	// 	0, 1, 0, 0, 
	// 	0, 0, 1, 0,
	// 	0, 0, 0, 1
	// };
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