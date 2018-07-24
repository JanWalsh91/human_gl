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
	Mesh(Vector rotationAngles,
		Vector rotationOrigin,
		Vector scale,
		Vector scaleOrigin,
		Vector translation,
		Vector color);
	Mesh(Vector rotationAngles,
		Vector rotationOrigin,
		Vector scale,
		Vector scaleOrigin,
		Vector translation,
		Vector color,
		std::string const & name);
	Mesh(Mesh const &);

	virtual ~Mesh();

	Mesh &	operator=(Mesh const & rhs);

	void render(Shader & s);
	void recursivelyRender(Shader & s);
	void recursivelyUpdateMatrices(Matrix & parentMatrix, Vector parentPos);
	Matrix calculateRotationMatrix(Vector & absRotCtr);
	Matrix calculateScalingMatrix(Vector & absSclCtr);
	void append(Mesh* mesh);
	
	void setRotationAngles(Vector  newAngle);
	void setTranslation(Vector  translation);
	void setScale(Vector  scale);
	void setColor(Vector  color);
	
	Matrix &		getModelMatrix();
	const Vector&	getRotationAngles();
	const Vector&	getTranslation();
	const Vector&	getScale();
	const Vector&	getColor();
	std::string&	getName();
	Mesh*			getByColor(Vector color);


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
	Vector rotationAngles;

	std::string name;

	unsigned VBOPosition;
};

enum Side {RIGHT, LEFT};

#endif
