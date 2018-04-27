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

void Cycle::interpolate() {
	
}

Frame&	Cycle::getCurrentFrame() {
	return this->frames[(int)(this->getStartTime() - glfwGetTime() / 16) % this->frames.size()];

}
