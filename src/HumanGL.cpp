#include "HumanGL.hpp"

HumanGL::HumanGL( void ) {
}

HumanGL::HumanGL( HumanGL const & HumanGL ) {
	*this = HumanGL;
}

HumanGL::~HumanGL( void ) {
}

HumanGL & HumanGL::operator=( HumanGL const & rhs ) {
	return *this;
}