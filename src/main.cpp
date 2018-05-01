#include "OpenGLWindow.hpp"
#include "Mesh/TorsoMesh.hpp"
#include "Vector.hpp"
#include "Matrix.hpp"
#include "ExceptionMsg.hpp"

#include <vector>

#include "OpenGLWindow.hpp"

int    main ( void ) {
	
//	TorsoMesh m;

	// throw ExceptionMsg("error");

	OpenGLWindow::initOpenGL();

	OpenGLWindow w(1280, 720, "Joli projet");

	// Cycle cycle;

	w.loop();

	return (0);
}