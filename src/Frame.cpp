#include "Frame.hpp"

Frame::Frame(Frame const & other) {
	std::cout << "New Copied Frame: " << glfwGetTime() << std::endl;
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

Frame::~Frame() {
	static int i = 0;
	std::cout << "delete frame" << i++ << "\n";
	delete this->torso;
	delete this->head;
	delete this->rightArm;
	delete this->rightLowerArm;
	delete this->rightHand;
	delete this->leftArm;
	delete this->leftLowerArm;
	delete this->leftHand;
	delete this->leftLeg;
	delete this->leftLowerLeg;
	delete this->rightLeg;
	delete this->rightLowerLeg;
	delete this->rightFoot;
	delete this->leftFoot;
}

unsigned Frame::frameLength = 16;