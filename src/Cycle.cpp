#include "Cycle.hpp"

Cycle::Cycle( Cycle::Type type ) {

	switch (type) {
	case Cycle::Type::WALKING:
		this->createWalkingCycle();
		break;
	}

	// TODO: use function when starting cycle
	this->setStartTime( static_cast<unsigned>(glfwGetTime()) );
}

Cycle::~Cycle( void ) {}

void Cycle::interpolate() {
	
}

Frame&	Cycle::getCurrentFrame() {
	int f = (int)(( (float)glfwGetTime() - (float)this->getStartTime() ) * 16.0f * 40) % this->frames.size();
	return this->frames[ f ];
}

void Cycle::createWalkingCycle() {
	this->name = "Walking";
	this->keyFrames.resize( Cycle::keyFramesPerCycle + 1 );

	this->keyFrames[0] = new KeyFrame();
	this->keyFrames[0]->setIndex(0);
	Mesh* torso = this->keyFrames[0]->getTorso();
	torso->setRotationAngles(Vector(0, 40, 0));
	Mesh* rightLeg = this->keyFrames[0]->getRightLeg();
	rightLeg->setRotationAngles(Vector(40, 0, 0));
	Mesh* leftLeg = this->keyFrames[0]->getLeftLeg();
	leftLeg->setRotationAngles(Vector(-40, 0, 0));
	
	this->keyFrames[30] = new KeyFrame();
	this->keyFrames[30]->setIndex(30);
	torso = this->keyFrames[30]->getTorso();
	torso->setRotationAngles(Vector(0, 40, 0));
	rightLeg = this->keyFrames[30]->getRightLeg();
	rightLeg->setRotationAngles(Vector(-40, 0, 0));
	leftLeg = this->keyFrames[30]->getLeftLeg();
	leftLeg->setRotationAngles(Vector(40, 0, 0));

	this->keyFrames[60] = new KeyFrame();
	this->keyFrames[60]->setIndex(0);
	torso = this->keyFrames[60]->getTorso();
	torso->setRotationAngles(Vector(0, 40, 0));
	rightLeg = this->keyFrames[60]->getRightLeg();
	rightLeg->setRotationAngles(Vector(40, 0, 0));
	leftLeg = this->keyFrames[60]->getLeftLeg();
	leftLeg->setRotationAngles(Vector(-40, 0, 0));

	int size;

	std::vector<Frame>* tmp = this->keyFrames[0]->interpolate(*this->keyFrames[30], size);
	this->frames.insert( this->frames.end(), tmp->begin(), tmp->end() );
	tmp = this->keyFrames[30]->interpolate(*this->keyFrames[60], size);

	this->frames.insert( this->frames.end(), tmp->begin(), tmp->end() );
}

std::vector<KeyFrame*> const & Cycle::getKeyFrames() {
	return this->keyFrames;
}