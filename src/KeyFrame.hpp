#ifndef KEY_FRAME_H
# define KEY_FRAME_H

# include "Frame.hpp"

# include <vector>

class KeyFrame: public Frame {

public:
	KeyFrame();
	KeyFrame( KeyFrame const & );
	virtual ~KeyFrame();
	KeyFrame &	operator=( KeyFrame const & rhs );


	Frame* interpolate(KeyFrame const & other, unsigned maxFramesPerCycle, int & size);

	// Setters
private:
	unsigned index; // Dans les 60 keyframes
};


#endif
