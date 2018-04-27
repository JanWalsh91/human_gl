#include "KeyFrame.hpp"

KeyFrame::KeyFrame( void ) {
}

KeyFrame::KeyFrame( KeyFrame const & KeyFrame ) {
	*this = KeyFrame;
}

KeyFrame::~KeyFrame( void ) {
}

KeyFrame & KeyFrame::operator=( KeyFrame const & rhs ) {
	return *this;
}

Frame* KetFrame::interpolate( KeyFrame const & other, unsigned maxFramesPerCycle, int & size ) {
	// calculate and set size (number of frames generated)
	//		include first keyFrame, exclude last
	size = abs(other.index - this->index);
	// calculate 
}