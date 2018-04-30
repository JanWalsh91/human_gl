#include "TorsoMesh.hpp"

TorsoMesh::TorsoMesh( void ) : Mesh::Mesh(
	Vector(0, 0, 0), // rotation angle
	Vector(0, 0, 0), // rotation origin
	Vector(1.5, 3, 0.6), // scale
	Vector(0, 0, 0), // scale origin
	Vector(0, 3, 15), // translation
	Vector(0.9, 0.5, 0.5) // color
) {}
