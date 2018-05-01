#include "Frame.hpp"

Frame::Frame(Frame const & other) {
	this->torso			= new Mesh( *other.getTorso() );
	this->head			= new Mesh( *other.getHead() );
	this->rightArm		= new Mesh( *other.getRightArm() );
	this->rightLowerArm	= new Mesh( *other.getRightLowerArm() );
	this->rightHand		= new Mesh( *other.getRightHand() );
	this->leftArm		= new Mesh( *other.getLeftArm() );
	this->leftLowerArm	= new Mesh( *other.getLeftLowerArm() );
	this->leftHand		= new Mesh( *other.getLeftHand() );
	this->leftLeg		= new Mesh( *other.getLeftLeg() );
	this->leftLowerLeg	= new Mesh( *other.getLeftLowerLeg() );
	this->rightLeg		= new Mesh( *other.getRightLeg() );
	this->rightLowerLeg	= new Mesh( *other.getRightLowerLeg() );
	this->rightFoot		= new Mesh( *other.getRightFoot() );
	this->leftFoot		= new Mesh( *other.getLeftFoot() );

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

	this->root = this->torso;
}