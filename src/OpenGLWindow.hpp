#ifndef OPENGL_WINDOW_HPP
# define OPENGL_WINDOW_HPP

# include <glad/glad.h>
# include <GLFW/glfw3.h>
# include <string>
# include <nanogui/nanogui.h>

# include "Mesh/Mesh.hpp"
# include "Shader.hpp"
# include "Cycle.hpp"
# include "HumanGL.hpp"
# include "Vector.hpp"

class OpenGLWindow: public nanogui::Screen {

public:
	OpenGLWindow( int width, int height, std::string const & title );
	OpenGLWindow( OpenGLWindow const & );
	~OpenGLWindow( void );

	OpenGLWindow & operator=( OpenGLWindow const & rhs );
	void loop(Cycle & cycle);
	void createWidget();

	HumanGL* getHuman() { return this->human; }

	static void initOpenGL();

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

	double poubelle;
};

#endif