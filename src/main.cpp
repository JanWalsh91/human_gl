#include "OpenGLWindow.hpp"

int    main ( void ) {

	OpenGLWindow::initOpenGL();

	OpenGLWindow w(1280, 720, "Joli projet");

	w.loop();

	return (0);
}