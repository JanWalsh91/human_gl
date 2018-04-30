#ifndef HUMAN_GL
# define HUMAN_GL

# include <glad/glad.h>
# include <GLFW/glfw3.h>
# include <vector>

# include "Cycle.hpp"
# include "Vector.hpp"
// # include "Window.hpp"

class HumanGL {

public:
	HumanGL( void );
	HumanGL( HumanGL const & );
	~HumanGL( void );

	HumanGL & operator=( HumanGL const & rhs );

	void initCycles(); // creates the cycles (walking, jumping ...)


	GLuint getVBO() { return this->VBO; }
	GLuint getVAO() { return this->VAO; }

	void setRotationSpeed(Vector speed) { this->rotationSpeed = speed; }
	void setRotationSpeedX(double x) { this->rotationSpeed[0] = x; }
	void setRotationSpeedY(double y) { this->rotationSpeed[1] = y; }
	void setRotationSpeedZ(double z) { this->rotationSpeed[2] = z; }
	Vector getRotationSpeed() { return this->rotationSpeed; }
	std::vector<Cycle*>	cycles;
private:
	

	GLuint		VAO;
	GLuint		VBO;

	Vector rotationSpeed;

//	unsigned VAO;

	// Window			*window;
};

#endif