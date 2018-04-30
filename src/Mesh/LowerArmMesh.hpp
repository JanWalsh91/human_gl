#ifndef LOWERARM_MESH_HPP
# define LOWERARM_MESH_HPP

# include "Mesh.hpp"

class LowerArmMesh : public Mesh {

public:

	LowerArmMesh( Side side );
	LowerArmMesh( Side side, Vector rotationAngles );

private:

};

#endif