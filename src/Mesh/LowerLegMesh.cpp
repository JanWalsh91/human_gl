#include "LowerLegMesh.hpp"

LowerLegMesh::LowerLegMesh( Side side ) : LowerLegMesh::LowerLegMesh(side, Vector(0, 0, 0)) {}

LowerLegMesh::LowerLegMesh( Side side, Vector rotationAngles ) : Mesh::Mesh (
		rotationAngles,
		Vector(0, 1, 0), // rotation origin
		Vector(0.7, 1.8, 0.7), // scale
		Vector(0, 0, 0), // scale origin
		(side == Side::LEFT) ? Vector(0, -3.7, 0) : Vector(0, -3.7, 0), // translation
		(side == Side::LEFT) ? Vector(0.2, 0.8, 0.1) : Vector(0.17, 0.78, 0.1), // color
		(side == Side::LEFT) ? "LeftLowerLeg" : "RightLowerLeg"
) {}
