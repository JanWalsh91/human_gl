#include "ArmMesh.hpp"

ArmMesh::ArmMesh( Side side ) : ArmMesh::ArmMesh(side, Vector(0, 0, 0)) {}

ArmMesh::ArmMesh( Side side, Vector rotationAngles ) : Mesh::Mesh (
		rotationAngles,
		Vector(0, 1, 0), // rotation origin
		Vector(0.5, 2, 0.5), // scale
		Vector(0, 0, 0), // scale origin
		(side == Side::LEFT) ? Vector(-2.1f, 0.8f, 0.0f) : Vector(2.1f, 0.8f, 0.0f), // translation
		(side == Side::LEFT) ? Vector(0.0f, 1.0f, 0.0f) : Vector(0.0f, 0.97f, 0.08f), // color
		(side == Side::LEFT) ? "LeftArm" : "RightArm"
) {}
