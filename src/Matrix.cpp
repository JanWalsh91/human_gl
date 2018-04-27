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

Matrix::Matrix( float angle, Matrix::TYPE type ) : Matrix::Matrix(4) {
	angle *= M_PI / 180;

	if ( type == Matrix::TYPE::ROTATION_X )
		this->rot_x( angle );
	else if ( type == Matrix::TYPE::ROTATION_Y )
		this->rot_y( angle );
	else if ( type == Matrix::TYPE::ROTATION_Z )
		this->rot_z( angle );
	this->rot_x( angle );
}

void	Matrix::rot_x( float angle ) {
	this->m[0] = 1;
	this->m[5] = cos( angle );
	this->m[6] = -sin( angle );
	this->m[9] = sin( angle );
	this->m[10] = cos( angle );
}

void	Matrix::rot_y( float angle ) {
	this->m[0] = cos( angle );
	this->m[2] = sin( angle );
	this->m[5] = 1;
	this->m[8] = -sin( angle );
	this->m[10] = cos( angle );
}

void	Matrix::rot_z( float angle ) {
	this->m[0] = cos( angle );
	this->m[1] = -sin( angle );
	this->m[4] = sin( angle );
	this->m[5] = cos( angle );
	this->m[10] = 1;
}

Matrix::Matrix( Vector const & v, Matrix::TYPE type ) : Matrix::Matrix(4) {
	if ( type == Matrix::TYPE::TRANSLATE ) {
		this->m[12] = v[0];
		this->m[13] = v[1];
		this->m[14] = v[2];
	}
	if ( type == Matrix::TYPE::SCALE ) {
		this->m[0] = v[0];
		this->m[5] = v[1];
		this->m[10] = v[2];
	}
}

Matrix::Matrix( Matrix const & matrix ) {
	*this = matrix;
}

Matrix::~Matrix( void ) {}

Matrix & Matrix::operator=( Matrix const & rhs ) {
	this->size = rhs.getSize();
	this->m = rhs.m;
	return *this;
}

float	& Matrix::operator[]( int i ) {
	return this->m[i];
}

float const	& Matrix::operator[]( int i ) const {
	return this->m[i];
}

unsigned			Matrix::getSize( void ) const {
	return this->size;
}

float *	Matrix::toArray( void ) {
	return this->m.data();
}

Matrix	Matrix::operator*( Matrix const & rhs ) {
	Matrix	m;
	int		size = this->getSize();
	
	if ( this->getSize() != rhs.getSize() ) {
		throw (Matrix::OperationImpossible());
	}
	for (int y = 0; y < size; ++y) {
		for (int x = 0; x < size; ++x) {
			m.m[y * size + x] = this->m[y * size] * rhs.m[x] +
				this->m[y * size + 1] * rhs.m[size + x] +
				this->m[y * size + 2] * rhs.m[size * 2 + x] +
				this->m[y * size + 3] * rhs.m[size * 3 + x];
		}
	}
	return m;
}

const char* Matrix::OperationImpossible::what() const throw() {
	return "Operation Impossible";
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

