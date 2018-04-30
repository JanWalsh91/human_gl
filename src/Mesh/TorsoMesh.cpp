#include "TorsoMesh.hpp"

TorsoMesh::TorsoMesh( void ) : Mesh::Mesh(
	Vector(0, 45, 0), // rotation angle
	Vector(0, 0, 0), // rotation origin
	Vector(1, 2.5, 0.4), // scale
	Vector(0, 0, 0), // scale origin
	Vector(0, 0, 5), // translation
	Vector(0.9, 0.5, 0.5) // color
) {}
