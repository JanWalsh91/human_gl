#ifndef ARM_MESH_HPP
# define ARM_MESH_HPP

# include "Mesh.hpp"

class ArmMesh : public Mesh {

public:
	ArmMesh( Side side );
	ArmMesh( Side side, Vector rotationAngles );

};

#endif
