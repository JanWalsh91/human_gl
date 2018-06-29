#include "LowerArmMesh.hpp"

LowerArmMesh::LowerArmMesh( Side side ) : LowerArmMesh::LowerArmMesh(side, Vector(0.0f, 0.0f, 0.0f)) {}

LowerArmMesh::LowerArmMesh( Side side, Vector rotationAngles ) : Mesh::Mesh (
		rotationAngles,
		Vector(0.0f, 1.0f, 0.0f), // rotation origin
		Vector(0.4f, 1.0f, 0.4f), // scale
		Vector(0.0f, 0.0f, 0.0f), // scale origin
		(side == Side::LEFT) ? Vector(0.0f, -3.0f, 0.0f) : Vector(0.0f, -3.0f, 0.0f), // translation
		(side == Side::LEFT) ? Vector(0.2f, 0.8f, 0.2f) : Vector(0.2f, 0.78f, 0.2f), // color
		(side == Side::LEFT) ? "LeftLowerArm" : "RightLowerArm"
) {}
