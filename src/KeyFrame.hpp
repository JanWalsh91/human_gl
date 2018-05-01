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

	std::vector<Frame>* interpolate( KeyFrame const & other, int & size );
	void copyFramesToList( std::vector<Mesh*> & list, Frame const & frame );
	void addFramesToList( std::vector<Mesh*> & list, Frame const & frame );
	void updateMeshValues( Mesh * meshFirst, Mesh * meshLast, Mesh * meshToUpdate, float fraction );

	void setIndex( int index ) { this->index = index; }
	
	int  getIndex( void ) { return this->index; }
private:
	int index; // Dans les 60 keyframes
};


#endif
