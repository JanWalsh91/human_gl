#ifndef HUMAN_GL
# define HUMAN_GL

# include <glad/glad.h>
# include <GLFW/glfw3.h>
# include <vector>

# include "Cycle.hpp"
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
private:
	std::vector<Cycle>	cycles;

	GLuint		VAO;
	GLuint		VBO;
//	unsigned VAO;

	// Window			*window;
};

#endif