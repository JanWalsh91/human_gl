#include "LegMesh.hpp"

LegMesh::LegMesh( Side side ) : Mesh::Mesh (
		Vector(0, 0, 0),
		Vector(0.2, 1.5, 1),
		(side == Side::LEFT) ? Vector(-0.2, 0, 0) : Vector(0.2, 0, 0),
		Vector(0, 1, 0)
) {}
