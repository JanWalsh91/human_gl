#ifndef HUMAN_GL
# define HUMAN_GL

# include <glad/glad.h>
# include <GLFW/glfw3.h>
# include <vector>

# include "Cycle.hpp"
# include "Vector.hpp"

class HumanGL {

public:
	HumanGL( void );
	HumanGL( HumanGL const & );
	~HumanGL( void );

	HumanGL & operator=( HumanGL const & rhs );

	void initCycles();

	GLuint getVBO() { return this->VBO; }
	GLuint getVAO() { return this->VAO; }

	std::vector<Cycle*> const & getCycles() { return this->cycles; }

private:

	std::vector<Cycle*>	cycles;
	GLuint		VAO;
	GLuint		VBO;
};

#endif