#include "FootMesh.hpp"

FootMesh::FootMesh( Side side ) : FootMesh::FootMesh(side, Vector(0, 0, 0)) {}

FootMesh::FootMesh( Side side, Vector rotationAngles ) : Mesh::Mesh (
		rotationAngles,
		Vector(0, 1, 0), // rotation origin
		Vector(0.6, 0.2, 1.5), // scale
		Vector(0, 0, 0), // scale origin
		(side == Side::LEFT) ? Vector(0, -2, -0.6) : Vector(0, -2, -0.6), // translation ES-FR
		Vector(0.8, 0.2, 0.2), // Your maaaaaaamaaaaa, houuuhouhouhouuuuuuuuu
		(side == Side::LEFT) ? "LeftFoot" : "RightFoot"
) {}
