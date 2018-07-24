#ifndef FOOT_MESH_HPP
# define FOOT_MESH_HPP

# include "Mesh.hpp"

class FootMesh : public Mesh {

public:
	FootMesh(Side side);
	FootMesh( Side side, Vector rotationAngles );
};

#endif
