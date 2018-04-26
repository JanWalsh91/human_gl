#include "Matrix.hpp"

Matrix::Matrix( void ) : Matrix::Matrix(4) {
	std::cout << "Matrix default constructor" << std::endl;
}

Matrix::Matrix( unsigned size ) {
	std::cout << "Matrix constructor, size: " << size << std::endl;
	if (size < 1) {
		size = 4;
	}
	this->size = size;
	this->m = std::vector<float>(size * size, 0);
	for (unsigned i = 0; i < size * size; i += size + 1) {
		this->m[i] = 1;
	}
}

Matrix::Matrix( Matrix const & matrix ) {
	*this = matrix;
}

Matrix::~Matrix( void ) {}

Matrix & Matrix::operator=( Matrix const & rhs ) {
	this->size = rhs.getSize();
	// if (this->m) delete this->m;
	this->m = rhs.m;
	// memcpy(this->m, rhs.m, sizeof(float) * this->size * this->size);
	return *this;
}

float	Matrix::operator[]( int i ) {
	// std::cout << "Not const" << std::endl;
	return this->m[i];
}

const float	& Matrix::operator[]( int i ) const {
	// std::cout << "const" << std::endl;
	return this->m[i];
}

unsigned			Matrix::getSize( void ) const {
	return this->size;
}


std::ostream &    operator<<( std::ostream & o, Matrix const & rhs ) {
	unsigned int size = rhs.getSize();

	for ( unsigned i = 0; i < size * size; ++i ) {
		o << rhs[i];
		if ( i != size * size - 1 ) {
			o << ", ";
		}
		if ( i % size == size - 1 ) {
			o << "\n";
		}
	}
	return o;
}