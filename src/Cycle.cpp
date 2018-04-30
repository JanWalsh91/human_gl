#include "Cycle.hpp"

Cycle::Cycle( Cycle::Type type ) {

	switch (type) {
	case Cycle::Type::WALKING:
		this->createWalkingCycle();
		break;
	}

}

Cycle::Cycle( Cycle const & Cycle ) {
	*this = Cycle;
}

Cycle::~Cycle( void ) {}

Cycle & Cycle::operator=( Cycle const & rhs ) {
	return *this;
}

void Cycle::interpolate() {
	
}

Frame&	Cycle::getCurrentFrame() {
	return this->frames[(int)(this->getStartTime() - glfwGetTime() / 16) % this->frames.size()];
}


void Cycle::createWalkingCycle() {
	this->name = "Walking";
	this->keyFrames.resize( Cycle::keyFramesPerCycle );

	this->keyFrames[0] = new KeyFrame();
	Mesh* rightLeg = this->keyFrames[0]->getRightLeg();
	rightLeg->setRotationAngles(Vector(40, 0, 0));
	Mesh* leftLeg = this->keyFrames[0]->getLeftLeg();
	leftLeg->setRotationAngles(Vector(-40, 0, 0));

	this->keyFrames[30] = new KeyFrame();
	rightLeg = this->keyFrames[30]->getRightLeg();
	rightLeg->setRotationAngles(Vector(-40, 0, 0));
	leftLeg = this->keyFrames[30]->getLeftLeg();
	leftLeg->setRotationAngles(Vector(40, 0, 0));
}