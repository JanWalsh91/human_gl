#ifndef HAND_MESH_HPP
# define HAND_MESH_HPP

# include "Mesh.hpp"

class HandMesh : public Mesh {

public:
	HandMesh(Side side);
	HandMesh(Side side, Vector rotationAngles);
};

#endif
