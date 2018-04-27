#ifndef GLFW_H
# define GLFW_H

# include <GLFW/glfw3.h>

class Glfw {

	public:
		Glfw( void );
		Glfw( Glfw const & );
		~Glfw( void );

		Glfw & operator=( Glfw const & rhs );
	
	private:
		GLFWwindow	*window;
		int			win_h;
		int			win_w;
};

#endif