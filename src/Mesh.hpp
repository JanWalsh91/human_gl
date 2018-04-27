#ifndef MESH_HPP
# define MESH_HPP

# include "Matrix.hpp"
# include "Vector.hpp"

# include <iostream>
# include <vector>

class Mesh {

public:
	Mesh();
	Mesh( Mesh const & );

	virtual ~Mesh();

	Mesh &	operator=( Mesh const & rhs );

	void render();
	void setModelMatrix();
	// Setters
private:
	std::vector<Mesh> meshes;
	Matrix modelMatrix;
	Vector rotationAngles;
	Vector translation;
	Vector scale;
	Vector color;

	unsigned VBOPosition;
};

std::ostream &	operator<<( std::ostream & o, Mesh const & rhs );

#endif