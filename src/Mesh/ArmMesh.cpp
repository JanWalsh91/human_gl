#include "ArmMesh.hpp"

ArmMesh::ArmMesh( Side side ) : ArmMesh::ArmMesh(side, Vector(0, 0, 0)) {}

ArmMesh::ArmMesh( Side side, Vector rotationAngles ) : Mesh::Mesh (
		rotationAngles,
		Vector(0, 1, 0), // rotation origin
		Vector(0.5, 2, 0.5), // scale
		Vector(0, 0, 0), // scale origin
		(side == Side::LEFT) ? Vector(-2.1, 0.8, 0) : Vector(2.1, 0.8, 0), // translation ES-FR
		Vector(0, 1, 0), // Your maaaaaaamaaaaa, houuuhouhouhouuuuuuuuu
		(side == Side::LEFT) ? "LeftArm" : "RightArm"
) {}
