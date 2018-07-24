#ifndef HEAD_MESH_HPP
# define HEAD_MESH_HPP

# include "Mesh.hpp"

class HeadMesh : public Mesh {

public:
	HeadMesh();
	HeadMesh(Vector rotationAngles);
};

#endif
