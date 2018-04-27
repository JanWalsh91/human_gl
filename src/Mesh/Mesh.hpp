#ifndef MESH_HPP
# define MESH_HPP

# include "../Matrix.hpp"
# include "../Vector.hpp"

# include <iostream>
# include <vector>

class Mesh {

public:
	Mesh();
	Mesh( Vector rotationAngles, Vector scale, Vector translation, Vector color );
	Mesh( Mesh const & );

	virtual ~Mesh();

	Mesh &	operator=( Mesh const & rhs );

	void render();
	void recursivelyRender();
	// void setModelMatrix();
	void updateModelMatrix( Matrix & parentModelMatrix );
	void updateModelMatrix();
	void recursivelyUpdateModelMatrix( Matrix & parentModelMatrix );
	void recursivelyUpdateModelMatrix();
	// Setters
	// not needed until we set variables outside of constructors.
private:
	std::vector<Mesh> meshes;
	Matrix modelMatrix;
	Vector rotationAngles;
	Vector translation;
	Vector scale;
	Vector color;

	// change to actual VBO
	unsigned VBOPosition;
};

std::ostream &	operator<<( std::ostream & o, Mesh const & rhs );

#endif