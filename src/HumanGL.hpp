#ifndef HUMAN_GL
# define HUMAN_GL

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

private:
	vector<Cycle>	cycles;
	// Window			*window;
};

#endif