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
	std::cout << "createCycle: " << glfwGetTime() << std::endl;
	this->name = "Walking";
	this->keyFrames.resize( Cycle::keyFramesPerCycle );


	this->keyFrames[0] = new KeyFrame();
	this->keyFrames[0]->setIndex(0);
	Mesh* torso = this->keyFrames[0]->getTorso();
	torso->setRotationAngles(Vector(0, 40, 0));
	torso->setTranslation(Vector(0.0f, 3.0f, 15.0f));
	Mesh* head = this->keyFrames[0]->getHead();
	head->setRotationAngles(Vector(0, 0, 0));
	Mesh* rightLeg = this->keyFrames[0]->getRightLeg();
	rightLeg->setRotationAngles(Vector(40, 0, 0));
	Mesh* rightLowerLeg = this->keyFrames[0]->getRightLowerLeg();
	rightLowerLeg->setRotationAngles(Vector(0, 0, 0));
	Mesh* leftLeg = this->keyFrames[0]->getLeftLeg();
	leftLeg->setRotationAngles(Vector(-40, 0, 0));
	Mesh* leftLowerLeg = this->keyFrames[0]->getLeftLowerLeg();
	leftLowerLeg->setRotationAngles(Vector(-20, 0, 0));
	Mesh* rightArm = this->keyFrames[0]->getRightArm();
	rightArm->setRotationAngles(Vector(-40, 0, 0));
	Mesh* leftArm = this->keyFrames[0]->getLeftArm();
	leftArm->setRotationAngles(Vector(40, 0, 0));
	Mesh* rightLowerArm = this->keyFrames[0]->getRightLowerArm();
	rightLowerArm->setRotationAngles(Vector(0, 0, 0));
	Mesh* leftLowerArm = this->keyFrames[0]->getLeftLowerArm();
	leftLowerArm->setRotationAngles(Vector(30, 0, 0));


	this->keyFrames[15] = new KeyFrame();
	this->keyFrames[15]->setIndex(15);
	torso = this->keyFrames[15]->getTorso();
	torso->setTranslation(Vector(0.0f, 3.35f, 15.0f));
	torso->setRotationAngles(Vector(0, 40, 0));
	head = this->keyFrames[15]->getHead();
	head->setRotationAngles(Vector(-10, 0, 0));
	rightLeg = this->keyFrames[15]->getRightLeg();
	rightLeg->setRotationAngles(Vector(0, 0, 0));
	rightLowerLeg = this->keyFrames[15]->getRightLowerLeg();
	rightLowerLeg->setRotationAngles(Vector(0, 0, 0));
	leftLeg = this->keyFrames[15]->getLeftLeg();
	leftLeg->setRotationAngles(Vector(0, 0, 0));
	leftLowerLeg = this->keyFrames[15]->getLeftLowerLeg();
	leftLowerLeg->setRotationAngles(Vector(-40, 0, 0));
	rightArm = this->keyFrames[15]->getRightArm();
	rightArm->setRotationAngles(Vector(0, 0, 0));
	leftArm = this->keyFrames[15]->getLeftArm();
	leftArm->setRotationAngles(Vector(0, 0, 0));
	rightLowerArm = this->keyFrames[15]->getRightLowerArm();
	rightLowerArm->setRotationAngles(Vector(0, 0, 0));
	leftLowerArm = this->keyFrames[15]->getLeftLowerArm();
	leftLowerArm->setRotationAngles(Vector(0, 0, 0));


	this->keyFrames[30] = new KeyFrame();
	this->keyFrames[30]->setIndex(30);
	torso = this->keyFrames[30]->getTorso();
	torso->setRotationAngles(Vector(0, 40, 0));
	torso->setTranslation(Vector(0.0f, 3.0f, 15.0f));
	head = this->keyFrames[30]->getHead();
	head->setRotationAngles(Vector(0, 0, 0));
	rightLeg = this->keyFrames[30]->getRightLeg();
	rightLeg->setRotationAngles(Vector(-40, 0, 0));
	rightLowerLeg = this->keyFrames[30]->getRightLowerLeg();
	rightLowerLeg->setRotationAngles(Vector(-20, 0, 0));
	leftLeg = this->keyFrames[30]->getLeftLeg();
	leftLeg->setRotationAngles(Vector(40, 0, 0));
	leftLowerLeg = this->keyFrames[30]->getLeftLowerLeg();
	leftLowerLeg->setRotationAngles(Vector(0, 0, 0));
	rightArm = this->keyFrames[30]->getRightArm();
	rightArm->setRotationAngles(Vector(40, 0, 0));
	leftArm = this->keyFrames[30]->getLeftArm();
	leftArm->setRotationAngles(Vector(-40, 0, 0));
	rightLowerArm = this->keyFrames[30]->getRightLowerArm();
	rightLowerArm->setRotationAngles(Vector(30, 0, 0));
	leftLowerArm = this->keyFrames[30]->getLeftLowerArm();
	leftLowerArm->setRotationAngles(Vector(0, 0, 0));


	this->keyFrames[45] = new KeyFrame();
	this->keyFrames[45]->setIndex(45);
	torso = this->keyFrames[45]->getTorso();
	torso->setRotationAngles(Vector(0, 40, 0));
	torso->setTranslation(Vector(0.0f, 3.35f, 15.0f));
	head = this->keyFrames[45]->getHead();
	head->setRotationAngles(Vector(-10, 0, 0));
	rightLeg = this->keyFrames[45]->getRightLeg();
	rightLeg->setRotationAngles(Vector(0, 0, 0));
	rightLowerLeg = this->keyFrames[45]->getRightLowerLeg();
	rightLowerLeg->setRotationAngles(Vector(-40, 0, 0));
	leftLeg = this->keyFrames[45]->getLeftLeg();
	leftLeg->setRotationAngles(Vector(0, 0, 0));
	leftLowerLeg = this->keyFrames[45]->getLeftLowerLeg();
	leftLowerLeg->setRotationAngles(Vector(0, 0, 0));
	rightArm = this->keyFrames[45]->getRightArm();
	rightArm->setRotationAngles(Vector(0, 0, 0));
	leftArm = this->keyFrames[45]->getLeftArm();
	leftArm->setRotationAngles(Vector(0, 0, 0));
	rightLowerArm = this->keyFrames[45]->getRightLowerArm();
	rightLowerArm->setRotationAngles(Vector(0, 0, 0));
	leftLowerArm = this->keyFrames[45]->getLeftLowerArm();
	leftLowerArm->setRotationAngles(Vector(0, 0, 0));




	this->keyFrames[59] = new KeyFrame();
	this->keyFrames[59]->setIndex(59);
	torso = this->keyFrames[59]->getTorso();
	torso->setRotationAngles(Vector(0, 40, 0));
	torso->setTranslation(Vector(0.0f, 3.0f, 15.0f));
	head = this->keyFrames[59]->getHead();
	head->setRotationAngles(Vector(0, 0, 0));
	rightLeg = this->keyFrames[59]->getRightLeg();
	rightLeg->setRotationAngles(Vector(40, 0, 0));
	rightLowerLeg = this->keyFrames[59]->getRightLowerLeg();
	rightLowerLeg->setRotationAngles(Vector(0, 0, 0));
	leftLeg = this->keyFrames[59]->getLeftLeg();
	leftLeg->setRotationAngles(Vector(-40, 0, 0));
	leftLowerLeg = this->keyFrames[59]->getLeftLowerLeg();
	leftLowerLeg->setRotationAngles(Vector(-20, 0, 0));
	rightArm = this->keyFrames[59]->getRightArm();
	rightArm->setRotationAngles(Vector(-40, 0, 0));
	leftArm = this->keyFrames[59]->getLeftArm();
	leftArm->setRotationAngles(Vector(40, 0, 0));
	rightLowerArm = this->keyFrames[59]->getRightLowerArm();
	rightLowerArm->setRotationAngles(Vector(0, 0, 0));
	leftLowerArm = this->keyFrames[59]->getLeftLowerArm();
	leftLowerArm->setRotationAngles(Vector(30, 0, 0));

	std::vector<Frame>* tmp = this->keyFrames[0]->interpolate(*this->keyFrames[15]);
	this->frames.insert( this->frames.end(), tmp->begin(), tmp->end() );
	delete tmp;	

	tmp = this->keyFrames[15]->interpolate(*this->keyFrames[30]);
	this->frames.insert( this->frames.end(), tmp->begin(), tmp->end() );
	delete tmp;

	tmp = this->keyFrames[30]->interpolate(*this->keyFrames[45]);
	this->frames.insert( this->frames.end(), tmp->begin(), tmp->end() );
	delete tmp;

	tmp = this->keyFrames[45]->interpolate(*this->keyFrames[59]);
	this->frames.insert( this->frames.end(), tmp->begin(), tmp->end() );
	delete tmp;

	std::cout << "deleting keyframes after interpolation" << std::endl;
	delete this->keyFrames[0];
	delete this->keyFrames[15];
	delete this->keyFrames[30];
	delete this->keyFrames[45];
	delete this->keyFrames[59];
}

std::vector<KeyFrame*> const & Cycle::getKeyFrames() {
	return this->keyFrames;
}