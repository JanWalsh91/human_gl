#include "LegMesh.hpp"

LegMesh::LegMesh( Side side ) : LegMesh::LegMesh(side, Vector(0, 0, 0)) {}

LegMesh::LegMesh( Side side, Vector rotationAngles ) : Mesh::Mesh (
		rotationAngles,
		Vector(0, 1, 0), // rotation origin
		Vector(0.7, 1.8, 0.7), // scale
		Vector(0, 0, 0), // scale origin
		(side == Side::LEFT) ? Vector(-0.75, -4.8, 0) : Vector(0.75, -4.8, 0), // translation
		(side == Side::LEFT) ? Vector(0.2, 0.68, 0.1) : Vector(0.2, 0.69, 0.1), // color
		(side == Side::LEFT) ? "LeftLeg" : "RightLeg"
) {}
