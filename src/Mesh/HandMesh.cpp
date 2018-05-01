#include "HandMesh.hpp"

HandMesh::HandMesh( Side side ) : HandMesh::HandMesh(side, Vector(0, 0, 0)) {}

HandMesh::HandMesh( Side side, Vector rotationAngles ) : Mesh::Mesh (
		rotationAngles,
		Vector(0, 1, 0), // rotation origin
		Vector(0.4, 0.8, 0.2), // scale
		Vector(0, 0, 0), // scale origin
		(side == Side::LEFT) ? Vector(0, -1.8, 0) : Vector(0, -1.8, 0), // translation
	Vector(0, 1, 0), // color
		(side == Side::LEFT) ? "LeftHand" : "RightHand"
) {}
