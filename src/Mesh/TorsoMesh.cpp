#include "TorsoMesh.hpp"

TorsoMesh::TorsoMesh( void ) : Mesh::Mesh(
	Vector(0.0f, 0.0f, 0.0f), // rotation angle
	Vector(0.0f, 0.0f, 0.0f), // rotation origin
	Vector(1.5f, 3.0f, 0.6f), // scale
	Vector(0.0f, 0.0f, 0.0f), // scale origin
	Vector(0.0f, 3.0f, 15.0f), // translation
	Vector(0.9f, 0.5f, 0.5f), // color
	"Torso"
) {}
