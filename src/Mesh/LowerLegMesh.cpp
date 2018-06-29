#include "LowerLegMesh.hpp"

LowerLegMesh::LowerLegMesh( Side side ) : LowerLegMesh::LowerLegMesh(side, Vector(0.0f, 0.0f, 0.0f)) {}

LowerLegMesh::LowerLegMesh( Side side, Vector rotationAngles ) : Mesh::Mesh (
		rotationAngles,
		Vector(0.0f, 1.0f, 0.0f), // rotation origin
		Vector(0.7f, 1.8f, 0.7f), // scale
		Vector(0.0f, 0.0f, 0.0f), // scale origin
		(side == Side::LEFT) ? Vector(0.0f, -3.7f, 0.0f) : Vector(0.0f, -3.7f, 0.0f), // translation
		(side == Side::LEFT) ? Vector(0.2f, 0.8f, 0.1f) : Vector(0.17f, 0.78f, 0.1f), // color
		(side == Side::LEFT) ? "LeftLowerLeg" : "RightLowerLeg"
) {}
