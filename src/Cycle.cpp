#include "Cycle.hpp"

Cycle::Cycle( void ) {
}

Cycle::Cycle( Cycle const & Cycle ) {
	*this = Cycle;
}

Cycle::~Cycle( void ) {}

Cycle & Cycle::operator=( Cycle const & rhs ) {
	return *this;
}