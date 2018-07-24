#ifndef KEY_FRAME_HPP
# define KEY_FRAME_HPP

# include "Frame.hpp"
# include "Mesh/ArmMesh.hpp"
# include "Mesh/TorsoMesh.hpp"
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
	~KeyFrame();
	KeyFrame &	operator=( KeyFrame const & rhs );

	std::vector<Frame>* interpolate( KeyFrame const & other );
	void copyFramesToList( std::vector<Mesh*> & list, Frame const & frame );
	void addFramesToList( std::vector<Mesh*> & list, Frame const & frame );
	void updateMeshValues( Mesh * meshFirst, Mesh * meshLast, Mesh * meshToUpdate, float fraction );

	void setIndex( int index ) { this->index = index; }
	
	int  getIndex( void ) const { return this->index; }
private:
	int index; // Dans les 60 keyframes
};

#endif
