#ifndef KEY_FRAME_H
# define KEY_FRAME_H

# include "Frame.hpp"
# include "Mesh/TorsoMesh.hpp"
# include "Mesh/ArmMesh.hpp"
# include "Mesh/LowerArmMesh.hpp"
# include "Mesh/LegMesh.hpp"
# include "Mesh/LowerLegMesh.hpp"
# include "Mesh/HeadMesh.hpp"
# include "Mesh/HandMesh.hpp"
# include "Mesh/FootMesh.hpp"

# include <cmath>
# include <vector>

class KeyFrame: public Frame {

public:
	KeyFrame();
	virtual ~KeyFrame();
	KeyFrame &	operator=( KeyFrame const & rhs );


	Frame* interpolate( KeyFrame const & other, unsigned maxFramesPerCycle, int & size );

	// Setters
private:
	int index; // Dans les 60 keyframes
};


#endif
