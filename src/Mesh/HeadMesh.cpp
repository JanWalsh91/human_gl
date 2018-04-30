#include "HeadMesh.hpp"

HeadMesh::HeadMesh() : HeadMesh::HeadMesh(Vector(0, 0, 0)) {}

HeadMesh::HeadMesh( Vector rotationAngles ) : Mesh::Mesh (
	rotationAngles,
	Vector(0, 0, 0), // rotation origin
	Vector(0.9, 0.9, 0.9), // scale
	Vector(0, 0, 0), // scale origin
	Vector(0, 3.5, 0), // translation ES-FR
	Vector(0.1, 0.5, 1) // Your maaaaaaamaaaaa, houuuhouhouhouuuuuuuuu
) {}