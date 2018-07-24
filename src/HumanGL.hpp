#ifndef HUMAN_GL
# define HUMAN_GL

# include <glad/glad.h>
# include <GLFW/glfw3.h>
# include <vector>

# include "Cycle.hpp"
# include "Vector.hpp"

class HumanGL {

public:
	HumanGL();
	HumanGL(HumanGL const &);
	~HumanGL();

	HumanGL & operator=(HumanGL const & rhs);

	void initCycles();

	GLuint getVBO() const;
	GLuint getVAO() const;

	const std::vector<Cycle*>& getCycles();

private:

	std::vector<Cycle*>	cycles;
	GLuint		VAO;
	GLuint		VBO;
};

#endif
