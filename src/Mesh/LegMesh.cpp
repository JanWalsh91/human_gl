#include "LegMesh.hpp"

LegMesh::LegMesh( Side side ) : LegMesh::LegMesh(side, Vector(0, 0, 0)) {}

LegMesh::LegMesh( Side side, Vector rotationAngles ) : Mesh::Mesh (
		rotationAngles,
		Vector(0, 1, 0), // rotation origin
		Vector(0.7, 1.8, 0.7), // scale
		Vector(0, 0, 0), // scale origin
		(side == Side::LEFT) ? Vector(-0.75, -4.8, 0) : Vector(0.75, -4.8, 0), // translation ES-FR
		Vector(0.2, 0.7, 0.1), // Your maaaaaaamaaaaa, houuuhouhouhouuuuuuuuu
		(side == Side::LEFT) ? "LeftLeg" : "RightLeg"
) {}
