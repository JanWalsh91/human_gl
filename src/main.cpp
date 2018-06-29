#include "OpenGLWindow.hpp"

int main () {

	OpenGLWindow::initOpenGL();
	OpenGLWindow window(1280, 720, "HumanGL");
	window.loop();
	return (0);
}