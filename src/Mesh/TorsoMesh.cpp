#include "TorsoMesh.hpp"

TorsoMesh::TorsoMesh( void ) : Mesh::Mesh(
	Vector(0, 0, 0),
	Vector(1, 1.5, 0.5),
	Vector(0, 0, 0),
	Vector(0, 1, 0),
	Vector(1, 0, 0)
) {}
