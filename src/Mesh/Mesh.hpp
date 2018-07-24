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
	Mesh( Vector rotationAngles,
		Vector rotationOrigin,
		Vector scale,
		Vector scaleOrigin,
		Vector translation,
		Vector color,
		std::string const & name );
	Mesh( Mesh const & );

	virtual ~Mesh();

	Mesh &	operator=( Mesh const & rhs );

	void render( Shader & s );
	void recursivelyRender( Shader & s );
	void recursivelyUpdateMatrices( Matrix & parentMatrix, Vector parentPos );
	Matrix calculateRotationMatrix( Vector & absRotCtr );
	Matrix calculateScalingMatrix( Vector & absSclCtr );
	void append( Mesh* mesh );
	
	void setRotationAngles(Vector  newAngle) { this->rotationAngles = newAngle; }
	void setTranslation(Vector  translation) { this->translation = translation; }
	void setScale(Vector  scale) { this->scale = scale; }
	void setColor(Vector  color) { this->color = color; }
	
	Matrix &	getModelMatrix();
	Vector const & getRotationAngles() { return this->rotationAngles;  }
	Vector const & getTranslation() { return this->translation;  }
	Vector const & getScale() { return this->scale;  }
	Vector const & getColor() { return this->color;  }
	std::string  & getName() { return this->name; }

	Mesh* getByColor(Vector color);

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

	unsigned VBOPosition;
};

std::ostream &	operator<<( std::ostream & o, Mesh const & rhs );

enum Side {RIGHT, LEFT};

#endif
