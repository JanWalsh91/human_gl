#include "HeadMesh.hpp"

HeadMesh::HeadMesh() : HeadMesh::HeadMesh(Vector(0, 0, 0)) {}

HeadMesh::HeadMesh( Vector rotationAngles ) : Mesh::Mesh (
	rotationAngles,
	Vector(0.0f, 0.0f, 0.0f), // rotation origin
	Vector(1.0f, 1.1f, 0.9f), // scale
	Vector(0.0f, 0.0f, 0.0f), // scale origin
	Vector(0.0f, 4.1f, 0.0f), // translation
	Vector(0.1f, 0.5f, 1.0f), // color,
	"Head"
) {}