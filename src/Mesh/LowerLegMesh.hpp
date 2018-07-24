#ifndef LOWER_LEG_MESH
# define LOWER_LEG_MESH

# include "Mesh.hpp"

class LowerLegMesh : public Mesh {

public:
	LowerLegMesh(Side side);
	LowerLegMesh(Side side, Vector rotationAngles);
};

#endif
