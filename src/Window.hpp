#ifndef WINDOW_HPP
# define WINDOW_HPP

# include <GLFW/glfw3.h>
# include <string>

# include "Mesh/Mesh.hpp"
# include "Shader.hpp"
# include "Cycle.hpp"

class Window {

	public:
		Window( int width, int height, std::string const & title );
		Window( Window const & );
		~Window( void );

		Window & operator=( Window const & rhs );
		void loop(Cycle & cycle);
	private:
		GLFWwindow	*window;
		Shader		shaderProgram;
		int			win_h;
		int			win_w;
		unsigned	lastTimeFrame;
};

#endif