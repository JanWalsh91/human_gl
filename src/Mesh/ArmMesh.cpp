#include "ArmMesh.hpp"

ArmMesh::ArmMesh( Side side ) : ArmMesh::ArmMesh(side, Vector(0, 0, 0)) {}

ArmMesh::ArmMesh( Side side, Vector rotationAngles ) : Mesh::Mesh (
		rotationAngles,
		Vector(0.5, 0.5, 0.5),
		(side == Side::LEFT) ? Vector(-1, 0.45, 0) : Vector(1, 0.45, 0),
		Vector(0, 1, 0),
		Vector(0, 1, 0)
) {}
