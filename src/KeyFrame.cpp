#include "KeyFrame.hpp"

KeyFrame::KeyFrame() {
	// build mesh hierarchy
	this->torso = new TorsoMesh();
	this->head = new HeadMesh();
	this->rightArm = new ArmMesh(Side::RIGHT);
	this->rightLowerArm = new LowerArmMesh(Side::RIGHT);
	this->rightHand = new HandMesh(Side::RIGHT);
	this->leftArm = new ArmMesh(Side::LEFT);
	this->leftLowerArm = new LowerArmMesh(Side::LEFT);
	this->leftHand = new HandMesh(Side::LEFT);
	this->leftLeg = new LegMesh(Side::LEFT);
	this->leftLowerLeg = new LowerLegMesh(Side::LEFT);
	this->rightLeg = new LegMesh(Side::RIGHT);
	this->rightLowerLeg = new LowerLegMesh(Side::RIGHT);
	this->rightFoot = new FootMesh(Side::RIGHT);
	this->leftFoot = new FootMesh(Side::LEFT);

	torso->append( head );
	rightLowerArm->append( rightHand );
	rightArm->append( rightLowerArm );

	leftLowerArm->append( leftHand );
	leftArm->append( leftLowerArm );
	
	torso->append( leftArm );
	torso->append( rightArm );

	rightLowerLeg->append( rightFoot );
	rightLeg->append( rightLowerLeg );

	leftLowerLeg->append( leftFoot );
	leftLeg->append( leftLowerLeg );
	
	torso->append( leftLeg );
	torso->append( rightLeg );

	this->root = torso;
}

// KeyFrame::KeyFrame( KeyFrame const & KeyFrame ) {
// 	*this = KeyFrame;
// }

KeyFrame::~KeyFrame( void ) {
	//TODO ...
}

KeyFrame & KeyFrame::operator=( KeyFrame const & rhs ) {
	return *this;
}

Frame* KeyFrame::interpolate( KeyFrame const & other, unsigned maxFramesPerCycle, int & size ) {
	// calculate and set size (number of frames generated)
	//		include first keyFrame, exclude last
	size = std::abs(other.index - this->index);
	// calculate 
	return nullptr;
}