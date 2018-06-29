#include "FootMesh.hpp"

FootMesh::FootMesh( Side side ) : FootMesh::FootMesh(side, Vector(0, 0, 0)) {}

FootMesh::FootMesh( Side side, Vector rotationAngles ) : Mesh::Mesh (
		rotationAngles,
		Vector(0.0f, 1.0f, 0.0f), // rotation origin
		Vector(0.6f, 0.2f, 1.5f), // scale
		Vector(0.0f, 0.0f, 0.0f), // scale origin
		(side == Side::LEFT) ? Vector(0.0f, -2.0f, -0.6f) : Vector(0.0f, -2.0f, -0.6f), // translation
		(side == Side::LEFT) ? Vector(0.8f, 0.2f, 0.2f) : Vector(0.79f, 0.2f, 0.2f), // color
		(side == Side::LEFT) ? "LeftFoot" : "RightFoot"
) {}
