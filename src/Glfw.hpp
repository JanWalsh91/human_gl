#ifndef GLFW_H
# define GLFW_H

# include <glad/glad.h>
# include <glfw/glfw3.h>

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