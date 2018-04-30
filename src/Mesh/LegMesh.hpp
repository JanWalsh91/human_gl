#ifndef LEG_MESH_HPP
# define LEG_MESH_HPP

# include "Mesh.hpp"

class LegMesh : public Mesh {

public:
	LegMesh();
	LegMesh( Side side );
	LegMesh( Side side, Vector );
	~LegMesh() {}
private:

};

#endif