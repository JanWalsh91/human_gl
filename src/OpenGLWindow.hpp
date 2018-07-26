#ifndef OPENGL_WINDOW_HPP
# define OPENGL_WINDOW_HPP

# include <glad/glad.h>
# include <GLFW/glfw3.h>
# include <string>
# include <nanogui/nanogui.h>

# include "Mesh/Mesh.hpp"
# include "Mesh/TorsoMesh.hpp"
# include "Mesh/ArmMesh.hpp"
# include "Mesh/LowerArmMesh.hpp"
# include "Mesh/LegMesh.hpp"
# include "Mesh/LowerLegMesh.hpp"
# include "Mesh/HeadMesh.hpp"
# include "Mesh/HandMesh.hpp"
# include "Mesh/FootMesh.hpp"
# include "Shader.hpp"
# include "Cycle.hpp"
# include "HumanGL.hpp"
# include "Vector.hpp"
# include "Camera.hpp"

class GUI;

class OpenGLWindow: public nanogui::Screen {

public:
	OpenGLWindow(int width, int height, std::string const & title);
	OpenGLWindow(OpenGLWindow const &);
	~OpenGLWindow();

	OpenGLWindow & operator=(OpenGLWindow const & rhs);
	void loop();
	void resize(int widht, int height);

	HumanGL* getHuman();

	static void initOpenGL();

private:
	GLFWwindow	*window;
	HumanGL		*human;
	GUI*		gui;
	Shader		shaderProgram;
	int			width;
	int			height;
	double		lastTimeFrame;

	Camera		camera;

	Matrix		viewMatrix;
	Vector		camPos;
	Vector		camDir;
	Vector		camRight;
	Vector		camUp;
	Matrix		PMatrix;
};

# include "GUI.hpp"

#endif
