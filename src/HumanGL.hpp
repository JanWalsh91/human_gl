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

	GLuint getVBO() const { return this->VBO; }
	GLuint getVAO() const { return this->VAO; }

	const std::vector<Cycle*>& getCycles() { return this->cycles; }

private:

	std::vector<Cycle*>	cycles;
	GLuint		VAO;
	GLuint		VBO;
};

#endif
