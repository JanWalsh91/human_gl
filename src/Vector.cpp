#include "Vector.hpp"

Vector::Vector( void ) : Vector::Vector( 0, 0, 0 ) {
}

Vector::Vector( float x, float y, float z ) {
	this->v = std::vector<float>(3, 0);
	this->v[0] = x;
	this->v[1] = y;
	this->v[2] = z;
}

Vector::Vector( Vector const & Vector ) {
	*this = Vector;
}

Vector::~Vector( void ) {
}

Vector & Vector::operator=( Vector const & rhs ) {
	this->v = rhs.v;
	return *this;
}

Vector  Vector::operator+( Vector const & rhs ) const {
	Vector v;

	v[0] = this->v[0] + rhs.v[0];
	v[1] = this->v[1] + rhs.v[1];
	v[2] = this->v[2] + rhs.v[2];
	return v;
}

Vector  Vector::operator-( Vector const & rhs ) const {
	Vector v;

	v[0] = this->v[0] - rhs.v[0];
	v[1] = this->v[1] - rhs.v[1];
	v[2] = this->v[2] - rhs.v[2];
	return v;
}

Vector  Vector::operator*( Vector const & rhs ) {
	Vector v;

	v[0] = this->v[0] * rhs.v[0];
	v[1] = this->v[1] * rhs.v[1];
	v[2] = this->v[2] * rhs.v[2];
	return v;
}

Vector  Vector::operator*( Matrix const & rhs ) {
	Vector v;

	v[0] = this->v[0] * rhs[0] + this->v[1] * rhs[1] + this->v[2] * rhs[2];
	v[1] = this->v[0] * rhs[4] + this->v[1] * rhs[5] + this->v[2] * rhs[6];
	v[2] = this->v[0] * rhs[8] + this->v[1] * rhs[9] + this->v[2] * rhs[10];
	return v;
}

Vector  Vector::operator*( float rhs ) {
	Vector v;

	v[0] = this->v[0] * rhs;
	v[1] = this->v[1] * rhs;
	v[2] = this->v[2] * rhs;
	return v;
}

Vector  Vector::operator/( Vector const & rhs ) {
	Vector v;

	v[0] = this->v[0] / rhs.v[0];
	v[1] = this->v[1] / rhs.v[1];
	v[2] = this->v[2] / rhs.v[2];
	return v;
}

bool	Vector::operator==(Vector const & rhs) {
	return fabs(this->v[0] - rhs[0]) < 0.001 && fabs(this->v[1] - rhs[1]) < 0.001 && fabs(this->v[2] - rhs[2]) < 0.001;
}

float	& Vector::operator[]( int i ) {
	return this->v[i];
}

float const	& Vector::operator[]( int i ) const {
	return this->v[i];
}

float *	Vector::toArray( void ) {
	return this->v.data();
}

std::ostream &    operator<<( std::ostream & o, Vector const & rhs ) {
	o << rhs[0] << ", " << rhs[1] << ", " << rhs[2];
	return o;
}