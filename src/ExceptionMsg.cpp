#include "ExceptionMsg.hpp"

ExceptionMsg::ExceptionMsg( void ) {}

ExceptionMsg::ExceptionMsg( std::string msg ) : msg(msg) {}

ExceptionMsg::ExceptionMsg( ExceptionMsg const & e ) {
	*this = e;
}

ExceptionMsg::~ExceptionMsg( void ) throw() {}

ExceptionMsg &    ExceptionMsg::operator=( ExceptionMsg const & rhs ) {
	this->msg = rhs.msg;
	return *this;
}

const char* ExceptionMsg::what() const throw() {
	return this->msg.c_str();
}
