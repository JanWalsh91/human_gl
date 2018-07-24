#include "OpenGLWindow.hpp"

int main () {

	try {
		OpenGLWindow::initOpenGL();
		OpenGLWindow window(1280, 720, "HumanGL");
		window.loop();
	}
	catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	return (0);
}
