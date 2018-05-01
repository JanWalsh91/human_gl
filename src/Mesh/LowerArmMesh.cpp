#include "LowerArmMesh.hpp"

LowerArmMesh::LowerArmMesh( Side side ) : LowerArmMesh::LowerArmMesh(side, Vector(0, 0, 0)) {}

LowerArmMesh::LowerArmMesh( Side side, Vector rotationAngles ) : Mesh::Mesh (
		rotationAngles,
		Vector(0, 1, 0), // rotation origin
		Vector(0.4, 1, 0.4), // scale
		Vector(0, 0, 0), // scale origin
		(side == Side::LEFT) ? Vector(0, -3, 0) : Vector(0, -3, 0), // translation
		Vector(0.2, 0.8, 0.2), // color
		(side == Side::LEFT) ? "LeftLowerArm" : "RightLowerArm"
) {}
