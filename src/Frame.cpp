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

	this->meshMap["LeftArm"]		= &Frame::getLeftArm;
	this->meshMap["RightArm"]		= &Frame::getRightArm;
	this->meshMap["LeftFoot"]		= &Frame::getLeftFoot;
	this->meshMap["RightFoot"]		= &Frame::getRightFoot;
	this->meshMap["LeftHand"]		= &Frame::getLeftHand;
	this->meshMap["RightHand"]		= &Frame::getRightHand;
	this->meshMap["Head"]			= &Frame::getHead;
	this->meshMap["LeftLeg"]		= &Frame::getLeftLeg;
	this->meshMap["RightLeg"]		= &Frame::getRightLeg;
	this->meshMap["LeftLowerLeg"]	= &Frame::getLeftLowerLeg;
	this->meshMap["RightLowerLeg"]	= &Frame::getRightLowerLeg;
	this->meshMap["LeftLowerArm"]	= &Frame::getLeftLowerArm;
	this->meshMap["RightLowerArm"]	= &Frame::getRightLowerArm;
	this->meshMap["Torso"]			= &Frame::getTorso;
}

Frame::~Frame() {
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

std::map<std::string, Frame::getMesh> Frame::getMeshMap() {
	return this->meshMap;
}

Mesh* Frame::getRoot() const {
	return this->root;

}

Mesh* Frame::getTorso()	const {
	return this->torso;
}

Mesh* Frame::getHead() const {
	return this->head;
}

Mesh* Frame::getRightArm() const {
	return this->rightArm;
}

Mesh* Frame::getRightLowerArm()	const {
	return this->rightLowerArm;
}

Mesh* Frame::getRightHand()	const {
	return this->rightHand;
}

Mesh* Frame::getLeftArm() const {
	return this->leftArm;
}

Mesh* Frame::getLeftLowerArm()	const {
	return this->leftLowerArm;
}

Mesh* Frame::getLeftHand() const {
	return this->leftHand;
}

Mesh* Frame::getLeftLeg() const {
	return this->leftLeg;
}

Mesh* Frame::getLeftLowerLeg()	const {
	return this->leftLowerLeg;
}

Mesh* Frame::getRightLeg() const {
	return this->rightLeg;
}

Mesh* Frame::getRightLowerLeg()	const {
	return this->rightLowerLeg;
}

Mesh* Frame::getRightFoot()	const {
	return this->rightFoot;
}

Mesh* Frame::getLeftFoot() const {
	return this->leftFoot;
}

void Frame::setFrameLength(unsigned i) {
	Frame::frameLength = i;
}

unsigned Frame::getFrameLength(void) {
	return Frame::frameLength;
}

unsigned Frame::frameLength = 16;
