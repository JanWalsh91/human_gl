#ifndef EXCEPTION_MSG_HPP
# define EXCEPTION_MSG_HPP

# include <exception>
# include <string>
# include <iostream>

class ExceptionMsg : public std::exception {

public:
	ExceptionMsg(std::string msg);
	ExceptionMsg(ExceptionMsg const &);
	~ExceptionMsg(void) throw();
	
	ExceptionMsg & operator=(ExceptionMsg const & rhs);
private:
	ExceptionMsg();
	std::string msg;
	virtual const char* what() const throw();
};

#endif
