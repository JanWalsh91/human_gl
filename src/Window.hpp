#ifndef WINDOW_HPP
# define WINDOW_HPP

# include <glad/glad.h>
# include <GLFW/glfw3.h>
# include <string>

# include "Mesh/Mesh.hpp"
# include "Shader.hpp"
# include "Cycle.hpp"
# include "HumanGL.hpp"
# include "Vector.hpp"

class Window {

	public:
		Window( int width, int height, std::string const & title );
		Window( Window const & );
		~Window( void );

		Window & operator=( Window const & rhs );
		void loop(Cycle & cycle);

	private:
		GLFWwindow	*window;
		HumanGL		*human;
		Shader		shaderProgram;
		int			width;
		int			height;
		double		lastTimeFrame;
		Matrix		viewMatrix;
		Vector		camPos;
		Vector		camDir;
		Vector		camRight;
		Vector		camUp;
		Matrix		PMatrix;
};

#endif