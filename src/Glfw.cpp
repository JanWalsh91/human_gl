#include "Glfw.hpp"

Glfw::Glfw( void ) {
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
}

Glfw::Glfw( Glfw const & Glfw ) {
	*this = Glfw;
}

Glfw::~Glfw( void ) {}

Glfw & Glfw::operator=( Glfw const & rhs ) {
	this->window = rhs.window;
	this->win_h = rhs.win_h;
	this->win_w = rhs.win_w;
	return *this;
}