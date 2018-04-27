#ifndef TORSO_MESH_HPP
# define TORSO_MESH_HPP

# include "Mesh.hpp"

class TorsoMesh : public Mesh {

public:
	TorsoMesh();
	TorsoMesh( Vector rotationAngles );
	TorsoMesh( TorsoMesh const & );
	~TorsoMesh();

	TorsoMesh & operator=( TorsoMesh const & rhs );

private:

};

#endif