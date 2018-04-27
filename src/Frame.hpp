#ifndef FRAME_H
# define FRAME_H

# include "Mesh.hpp"

# include <vector>

class Frame {

public:
	Frame();
	Frame( Frame const & );

	virtual ~Frame();

	Frame &	operator=( Frame const & rhs );

	void render();
private:
	std::vector<Mesh> meshes;

	static const unsigned frameLength = 16;
};


#endif
