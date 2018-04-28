#ifndef MESH_HPP
# define MESH_HPP

# include "../Matrix.hpp"
# include "../Vector.hpp"
# include "../Shader.hpp"

# include <iostream>
# include <vector>

class Mesh {

public:
	Mesh();
	Mesh( Vector rotationAngles, Vector scale, Vector translation, Vector origin, Vector color );
	Mesh( Mesh const & );

	virtual ~Mesh();

	Mesh &	operator=( Mesh const & rhs );

	void render( Shader & s );
	void recursivelyRender( Shader & s );
	void updateModelMatrix( Matrix & scale, Matrix & translate, Matrix & rotate );
	void updateModelMatrix();
	void recursivelyUpdateModelMatrix( Matrix & scale, Matrix & translate, Matrix & rotate );
	void recursivelyUpdateModelMatrix();

	// Setters
	// not needed until we set variables outside of constructors.
	Matrix &	getModelMatrix();
	void append( Mesh & mesh );

	void setRotationAngles(Vector  newAngle) { this->rotationAngles = newAngle; }

private:
	std::vector<Mesh> meshes;
	Matrix modelMatrix;
	Matrix scaleMatrix;
	Matrix rotateMatrix;
	Matrix translateMatrix;


	Vector origin;
	Vector rotationAngles;
	Vector translation;
	Vector scale;
	Vector color;

	// change to actual VBO
	unsigned VBOPosition;
};

std::ostream &	operator<<( std::ostream & o, Mesh const & rhs );

enum Side {RIGHT, LEFT};

#endif