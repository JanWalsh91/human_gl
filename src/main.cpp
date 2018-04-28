#include "Window.hpp"
#include "Mesh/TorsoMesh.hpp"
#include "Vector.hpp"
#include "Matrix.hpp"

#include <vector>

#include "Window.hpp"

int    main ( void ) {
	
//	TorsoMesh m;
	Window w(800, 600, "Joli projet");

	Cycle cycle;

	w.loop(cycle);

	return (0);
}