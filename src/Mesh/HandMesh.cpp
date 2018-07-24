#include "HandMesh.hpp"

HandMesh::HandMesh( Side side ) : HandMesh::HandMesh(side, Vector(0, 0, 0)) {}

HandMesh::HandMesh( Side side, Vector rotationAngles ) : Mesh::Mesh (
		rotationAngles,
		Vector(0.0f, 1.0f, 0.0f), // rotation origin
		Vector(0.45f, 0.6f, 0.2f), // scale
		Vector(0.0f, 0.0f, 0.0f), // scale origin
		(side == Side::LEFT) ? Vector(0.0f, -1.8f, 0.0f) : Vector(0.0f, -1.8f, 0.0f), // translation
		(side == Side::LEFT) ? Vector(0.0f, 0.96f, 0.0f) : Vector(0.0f, 0.99f, 0.0f),
		(side == Side::LEFT) ? "LeftHand" : "RightHand"
) {}
