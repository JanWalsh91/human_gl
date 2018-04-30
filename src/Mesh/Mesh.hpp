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
	Mesh( Vector rotationAngles,
		Vector rotationOrigin,
		Vector scale,
		Vector scaleOrigin,
		Vector translation,
		Vector color );
	Mesh( Vector rotationAngles, Vector rotationOrigin, Vector scale, Vector scaleOrigin, Vector translation, Vector color, std::string const & name );
	Mesh( Mesh const & );

	virtual ~Mesh();

	Mesh &	operator=( Mesh const & rhs );

	void render( Shader & s );
	void recursivelyRender( Shader & s );
	void recursivelyUpdateMatrices( Matrix & parentMatrix, Vector parentPos );
	Matrix calculateRotationMatrix( Vector & absRotCtr );
	Matrix calculateScalingMatrix( Vector & absSclCtr );

	// void updateModelMatrix( Matrix & modelMatrix, Matrix & translateMatrix );
	// void updateModelMatrix(Matrix & parentModelMatrix);
	// void updateInheritedModelMatrix();
	
	// void recursivelyUpdateModelMatrix( Matrix & modelMatrix, Matrix & translateMatrix );
	
	// Matrix& recursivelyUpdateModelMatrix(Matrix & parentModelMatrix);

	// Setters
	// not needed until we set variables outside of constructors.
	Matrix &	getModelMatrix();
	void append( Mesh* mesh );

	void setRotationAngles(Vector  newAngle) { 
		this->rotationAngles = newAngle;
		std::cout << this->rotationAngles << std::endl;
	}
	Vector rotationAngles;

private:
	std::vector<Mesh*> meshes;
	Mesh* parentMesh;
	Matrix modelMatrix;
	Matrix inheritedModelMatrix;
	Matrix scaleMatrix;
	Matrix rotateMatrix;
	Matrix translateMatrix;


	Vector rotationOrigin;
	Vector translation;
	Vector scale;
	Vector scaleOrigin;
	Vector color;

	std::string name;

	// void updateRotationMatrix();
	// Vector getScaleCenter();
	// Vector getRotationCenter();
	// change to actual VBO
	unsigned VBOPosition;
};

std::ostream &	operator<<( std::ostream & o, Mesh const & rhs );

enum Side {RIGHT, LEFT};

#endif