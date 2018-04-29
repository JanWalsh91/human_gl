#include "OpenGLWindow.hpp"
#include "Mesh/TorsoMesh.hpp"
#include "Vector.hpp"
#include "Matrix.hpp"

#include <vector>

#include "OpenGLWindow.hpp"

int    main ( void ) {
	
//	TorsoMesh m;

	OpenGLWindow::initOpenGL();

	OpenGLWindow w(1280, 720, "Joli projet");

	Cycle cycle;

	w.loop(cycle);

	return (0);
}