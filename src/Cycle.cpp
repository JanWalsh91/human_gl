#include "Cycle.hpp"

Cycle::Cycle( Cycle::Type type ) {

	switch (type) {
	case Cycle::Type::STAND:
		this->createStandingCycle();
		break;
	case Cycle::Type::WALK:
		this->createWalkingCycle();
		break;
	case Cycle::Type::JUMP:
		this->createJumpingCycle();
		break;
	case Cycle::Type::MOON_WALK:
		this->createMoonWalshCycle();
		break;
	case Cycle::Type::WAVE:
		this->createWaveCycle();
		break;
	case Cycle::Type::PUSH_UP:
		this->createPushUpCycle();
		break;
	}
	this->setStartTime( static_cast<unsigned>(glfwGetTime()) );
}

Cycle::~Cycle( void ) {}

Frame&	Cycle::getCurrentFrame() {
	int f = (int)(( (float)glfwGetTime() - (float)this->getStartTime() ) * Frame::getFrameLength() * 40) % this->frames.size();
	return this->frames[ f ];
}

void Cycle::createStandingCycle() {
	this->name = "Standing";
	this->keyFrames.resize( Cycle::keyFramesPerCycle );

	this->keyFrames[0] = new KeyFrame();
	this->keyFrames[0]->setIndex(0);
	Mesh* torso = this->keyFrames[0]->getTorso();
	torso->setRotationAngles(Vector(0, 0, 0));
	this->keyFrames[59] = new KeyFrame();
	this->keyFrames[59]->setIndex(59);
	torso = this->keyFrames[59]->getTorso();
	torso->setRotationAngles(Vector(0, 359, 0));

	std::vector<Frame>* tmp = this->keyFrames[0]->interpolate(*this->keyFrames[59]);
	this->frames.insert( this->frames.end(), tmp->begin(), tmp->end() );

	delete tmp;

	delete this->keyFrames[0];
	delete this->keyFrames[59];
}

void Cycle::createJumpingCycle() {

	this->name = "Jumping";
	this->keyFrames.resize( Cycle::keyFramesPerCycle );

	this->keyFrames[0] = new KeyFrame();
	this->keyFrames[0]->setIndex(0);
	Mesh* torso = this->keyFrames[0]->getTorso();
	torso->setRotationAngles(Vector(-30, 40, 0));
	torso->setTranslation(Vector(0.0f, 1.0f - 2, 15.0f));
	Mesh* rightLeg = this->keyFrames[0]->getRightLeg();
	rightLeg->setRotationAngles(Vector(130, 0, 0));
	Mesh* rightLowerLeg = this->keyFrames[0]->getRightLowerLeg();
	rightLowerLeg->setRotationAngles(Vector(-130, 0, 0));
	Mesh* leftLeg = this->keyFrames[0]->getLeftLeg();
	leftLeg->setRotationAngles(Vector(130, 0, 0));
	Mesh* leftLowerLeg = this->keyFrames[0]->getLeftLowerLeg();
	leftLowerLeg->setRotationAngles(Vector(-130, 0, 0));
	Mesh* rightArm = this->keyFrames[0]->getRightArm();
	rightArm->setRotationAngles(Vector(45, 0, 0));
	Mesh* leftArm = this->keyFrames[0]->getLeftArm();
	leftArm->setRotationAngles(Vector(45, 0, 0));
	Mesh* rightLowerArm = this->keyFrames[0]->getRightLowerArm();
	rightLowerArm->setRotationAngles(Vector(120, 0, 0));
	Mesh* leftLowerArm = this->keyFrames[0]->getLeftLowerArm();
	leftLowerArm->setRotationAngles(Vector(120, 0, 0));

	this->keyFrames[19] = new KeyFrame();
	this->keyFrames[19]->setIndex(19);
	torso = this->keyFrames[19]->getTorso();
	torso->setRotationAngles(Vector(0, 40, 0));
	torso->setTranslation(Vector(0.0f, 1.0f + 2, 15.0f));
	rightArm = this->keyFrames[19]->getRightArm();
	rightArm->setRotationAngles(Vector(25, 0, 0));
	leftArm = this->keyFrames[19]->getLeftArm();
	leftArm->setRotationAngles(Vector(25, 0, 0));
	rightLowerArm = this->keyFrames[19]->getRightLowerArm();
	rightLowerArm->setRotationAngles(Vector(80, 0, 0));
	leftLowerArm = this->keyFrames[19]->getLeftLowerArm();
	leftLowerArm->setRotationAngles(Vector(80, 0, 0));

	this->keyFrames[30] = new KeyFrame();
	this->keyFrames[30]->setIndex(30);
	torso = this->keyFrames[30]->getTorso();
	torso->setRotationAngles(Vector(-30, 40, 0));
	torso->setTranslation(Vector(0.0f, 1.0f + 5.5f, 15.0f));
	rightLeg = this->keyFrames[30]->getRightLeg();
	rightLeg->setRotationAngles(Vector(130, 0, 0));
	rightLowerLeg = this->keyFrames[30]->getRightLowerLeg();
	rightLowerLeg->setRotationAngles(Vector(-130, 0, 0));
	leftLeg = this->keyFrames[30]->getLeftLeg();
	leftLeg->setRotationAngles(Vector(130, 0, 0));
	leftLowerLeg = this->keyFrames[30]->getLeftLowerLeg();
	leftLowerLeg->setRotationAngles(Vector(-130, 0, 0));

	this->keyFrames[41] = new KeyFrame();
	this->keyFrames[41]->setIndex(41);
	torso = this->keyFrames[41]->getTorso();
	torso->setRotationAngles(Vector(0, 41, 0));
	torso->setTranslation(Vector(0.0f, 1.0f + 2, 15.0f));
	rightArm = this->keyFrames[41]->getRightArm();
	rightArm->setRotationAngles(Vector(45, 0, 0));
	leftArm = this->keyFrames[41]->getLeftArm();
	leftArm->setRotationAngles(Vector(45, 0, 0));
	rightLowerArm = this->keyFrames[41]->getRightLowerArm();
	rightLowerArm->setRotationAngles(Vector(120, 0, 0));
	leftLowerArm = this->keyFrames[41]->getLeftLowerArm();
	leftLowerArm->setRotationAngles(Vector(120, 0, 0));

	this->keyFrames[59] = new KeyFrame();
	this->keyFrames[59]->setIndex(59);
	torso = this->keyFrames[59]->getTorso();
	torso->setRotationAngles(Vector(-30, 40, 0));
	torso->setTranslation(Vector(0.0f, 1.0f - 2, 15.0f));
	rightLeg = this->keyFrames[59]->getRightLeg();
	rightLeg->setRotationAngles(Vector(130, 0, 0));
	rightLowerLeg = this->keyFrames[59]->getRightLowerLeg();
	rightLowerLeg->setRotationAngles(Vector(-130, 0, 0));
	leftLeg = this->keyFrames[59]->getLeftLeg();
	leftLeg->setRotationAngles(Vector(130, 0, 0));
	leftLowerLeg = this->keyFrames[59]->getLeftLowerLeg();
	leftLowerLeg->setRotationAngles(Vector(-130, 0, 0));
	rightArm = this->keyFrames[59]->getRightArm();
	rightArm->setRotationAngles(Vector(45, 0, 0));
	leftArm = this->keyFrames[59]->getLeftArm();
	leftArm->setRotationAngles(Vector(45, 0, 0));
	rightLowerArm = this->keyFrames[59]->getRightLowerArm();
	rightLowerArm->setRotationAngles(Vector(120, 0, 0));
	leftLowerArm = this->keyFrames[59]->getLeftLowerArm();
	leftLowerArm->setRotationAngles(Vector(120, 0, 0));

	std::vector<Frame>* tmp = this->keyFrames[0]->interpolate(*this->keyFrames[19]);
	this->frames.insert( this->frames.end(), tmp->begin(), tmp->end() );
	delete tmp;

	tmp = this->keyFrames[19]->interpolate(*this->keyFrames[30]);
	this->frames.insert( this->frames.end(), tmp->begin(), tmp->end() );
	delete tmp;

	tmp = this->keyFrames[30]->interpolate(*this->keyFrames[41]);
	this->frames.insert( this->frames.end(), tmp->begin(), tmp->end() );
	delete tmp;

	tmp = this->keyFrames[41]->interpolate(*this->keyFrames[59]);
	this->frames.insert( this->frames.end(), tmp->begin(), tmp->end() );
	delete tmp;

	delete this->keyFrames[0];
	delete this->keyFrames[19];
	delete this->keyFrames[30];
	delete this->keyFrames[41];
	delete this->keyFrames[59];
}


void Cycle::createWalkingCycle() {
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

	delete this->keyFrames[0];
	delete this->keyFrames[15];
	delete this->keyFrames[30];
	delete this->keyFrames[45];
	delete this->keyFrames[59];
}


void Cycle::createMoonWalshCycle() {
	this->name = "MoonWalsh";
	this->keyFrames.resize( Cycle::keyFramesPerCycle );

	this->keyFrames[0] = new KeyFrame();
	this->keyFrames[0]->setIndex(0);
	Mesh* torso = this->keyFrames[0]->getTorso();
	torso->setRotationAngles(Vector(0, 90, 0));
	torso->setTranslation(Vector(0.0f, 3.0f, 15.0f));
	Mesh* rightLeg = this->keyFrames[0]->getRightLeg();
	rightLeg->setRotationAngles(Vector(40, 0, 0));
	Mesh* rightLowerLeg = this->keyFrames[0]->getRightLowerLeg();
	rightLowerLeg->setRotationAngles(Vector(0, 0, 0));
	Mesh* leftLeg = this->keyFrames[0]->getLeftLeg();
	leftLeg->setRotationAngles(Vector(0, 0, 0));
	Mesh* leftLowerLeg = this->keyFrames[0]->getLeftLowerLeg();
	leftLowerLeg->setRotationAngles(Vector(-20, 0, 0));
	Mesh* rightArm = this->keyFrames[0]->getRightArm();
	rightArm->setRotationAngles(Vector(-10, 0, 0));
	Mesh* leftArm = this->keyFrames[0]->getLeftArm();
	leftArm->setRotationAngles(Vector(10, 0, 0));
	Mesh* rightLowerArm = this->keyFrames[0]->getRightLowerArm();
	rightLowerArm->setRotationAngles(Vector(70, 0, 0));
	Mesh* leftLowerArm = this->keyFrames[0]->getLeftLowerArm();
	leftLowerArm->setRotationAngles(Vector(70, 0, 0));

	this->keyFrames[15] = new KeyFrame();
	this->keyFrames[15]->setIndex(15);
	torso = this->keyFrames[15]->getTorso();
	torso->setTranslation(Vector(2.0f, 3.0f, 15.0f));
	torso->setRotationAngles(Vector(0, 90, 0));
	rightLeg = this->keyFrames[15]->getRightLeg();
	rightLeg->setRotationAngles(Vector(0, 0, 0));
	rightLowerLeg = this->keyFrames[15]->getRightLowerLeg();
	rightLowerLeg->setRotationAngles(Vector(0, 0, 0));
	leftLeg = this->keyFrames[15]->getLeftLeg();
	leftLeg->setRotationAngles(Vector(0, 0, 0));
	leftLowerLeg = this->keyFrames[15]->getLeftLowerLeg();
	leftLowerLeg->setRotationAngles(Vector(-30, 0, 0));
	rightArm = this->keyFrames[15]->getRightArm();
	rightArm->setRotationAngles(Vector(0, 0, 0));
	leftArm = this->keyFrames[15]->getLeftArm();
	leftArm->setRotationAngles(Vector(0, 0, 0));
	rightLowerArm = this->keyFrames[15]->getRightLowerArm();
	rightLowerArm->setRotationAngles(Vector(70, 0, 0));
	leftLowerArm = this->keyFrames[15]->getLeftLowerArm();
	leftLowerArm->setRotationAngles(Vector(70, 0, 0));


	this->keyFrames[30] = new KeyFrame();
	this->keyFrames[30]->setIndex(30);
	torso = this->keyFrames[30]->getTorso();
	torso->setRotationAngles(Vector(0, 90, 0));
	torso->setTranslation(Vector(4.0f, 3.0f, 15.0f));
	rightLeg = this->keyFrames[30]->getRightLeg();
	rightLeg->setRotationAngles(Vector(0, 0, 0));
	rightLowerLeg = this->keyFrames[30]->getRightLowerLeg();
	rightLowerLeg->setRotationAngles(Vector(-20, 0, 0));
	leftLeg = this->keyFrames[30]->getLeftLeg();
	leftLeg->setRotationAngles(Vector(40, 0, 0));
	leftLowerLeg = this->keyFrames[30]->getLeftLowerLeg();
	leftLowerLeg->setRotationAngles(Vector(0, 0, 0));
	rightArm = this->keyFrames[30]->getRightArm();
	rightArm->setRotationAngles(Vector(10, 0, 0));
	leftArm = this->keyFrames[30]->getLeftArm();
	leftArm->setRotationAngles(Vector(-10, 0, 0));
	rightLowerArm = this->keyFrames[30]->getRightLowerArm();
	rightLowerArm->setRotationAngles(Vector(70, 0, 0));
	leftLowerArm = this->keyFrames[30]->getLeftLowerArm();
	leftLowerArm->setRotationAngles(Vector(70, 0, 0));

	this->keyFrames[45] = new KeyFrame();
	this->keyFrames[45]->setIndex(45);
	torso = this->keyFrames[45]->getTorso();
	torso->setRotationAngles(Vector(0, 90, 0));
	torso->setTranslation(Vector(6.0f, 3.0f, 15.0f));
	rightLeg = this->keyFrames[45]->getRightLeg();
	rightLeg->setRotationAngles(Vector(0, 0, 0));
	rightLowerLeg = this->keyFrames[45]->getRightLowerLeg();
	rightLowerLeg->setRotationAngles(Vector(-30, 0, 0));
	leftLeg = this->keyFrames[45]->getLeftLeg();
	leftLeg->setRotationAngles(Vector(0, 0, 0));
	leftLowerLeg = this->keyFrames[45]->getLeftLowerLeg();
	leftLowerLeg->setRotationAngles(Vector(0, 0, 0));
	rightArm = this->keyFrames[45]->getRightArm();
	rightArm->setRotationAngles(Vector(0, 0, 0));
	leftArm = this->keyFrames[45]->getLeftArm();
	leftArm->setRotationAngles(Vector(0, 0, 0));
	rightLowerArm = this->keyFrames[45]->getRightLowerArm();
	rightLowerArm->setRotationAngles(Vector(70, 0, 0));
	leftLowerArm = this->keyFrames[45]->getLeftLowerArm();
	leftLowerArm->setRotationAngles(Vector(70, 0, 0));

	this->keyFrames[59] = new KeyFrame();
	this->keyFrames[59]->setIndex(59);
	torso = this->keyFrames[59]->getTorso();
	torso->setRotationAngles(Vector(0, 90, 0));
	torso->setTranslation(Vector(8.0f, 3.0f, 15.0f));
	rightLeg = this->keyFrames[59]->getRightLeg();
	rightLeg->setRotationAngles(Vector(40, 0, 0));
	rightLowerLeg = this->keyFrames[59]->getRightLowerLeg();
	rightLowerLeg->setRotationAngles(Vector(0, 0, 0));
	leftLeg = this->keyFrames[59]->getLeftLeg();
	leftLeg->setRotationAngles(Vector(0, 0, 0));
	leftLowerLeg = this->keyFrames[59]->getLeftLowerLeg();
	leftLowerLeg->setRotationAngles(Vector(-20, 0, 0));
	rightArm = this->keyFrames[59]->getRightArm();
	rightArm->setRotationAngles(Vector(-10, 0, 0));
	leftArm = this->keyFrames[59]->getLeftArm();
	leftArm->setRotationAngles(Vector(10, 0, 0));
	rightLowerArm = this->keyFrames[59]->getRightLowerArm();
	rightLowerArm->setRotationAngles(Vector(70, 0, 0));
	leftLowerArm = this->keyFrames[59]->getLeftLowerArm();
	leftLowerArm->setRotationAngles(Vector(70, 0, 0));

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

	delete this->keyFrames[0];
	delete this->keyFrames[15];
	delete this->keyFrames[30];
	delete this->keyFrames[45];
	delete this->keyFrames[59];
}

void Cycle::createWaveCycle() {
	this->name = "Wave";
	this->keyFrames.resize( Cycle::keyFramesPerCycle );

	this->keyFrames[0] = new KeyFrame();
	this->keyFrames[0]->setIndex(0);
	Mesh* torso = this->keyFrames[0]->getTorso();
	torso->setRotationAngles(Vector(0, 20, 0));
	torso->setTranslation(Vector(0.0f, 3.0f, 15.0f));
	Mesh* head = this->keyFrames[0]->getHead();
	head->setRotationAngles(Vector(0, 0, 10));
	Mesh* rightArm = this->keyFrames[0]->getRightArm();
	rightArm->setRotationAngles(Vector(10, 0, -10));
	Mesh* rightLowerArm = this->keyFrames[0]->getRightLowerArm();
	rightLowerArm->setRotationAngles(Vector(150, -70, 0));
	Mesh* leftArm = this->keyFrames[0]->getLeftArm();
	leftArm->setRotationAngles(Vector(10, 0, 10));
	Mesh* leftLowerArm = this->keyFrames[0]->getLeftLowerArm();
	leftLowerArm->setRotationAngles(Vector(150, 70, 0));
	Mesh* leftFoot = this->keyFrames[0]->getLeftFoot();
	leftFoot->setRotationAngles(Vector(0, 0, 0));
	Mesh* rightFoot = this->keyFrames[0]->getRightFoot();
	rightFoot->setRotationAngles(Vector(0, 0, 0));

	this->keyFrames[15] = new KeyFrame();
	this->keyFrames[15]->setIndex(15);
	torso = this->keyFrames[15]->getTorso();
	torso->setRotationAngles(Vector(0, 20, 0));
	torso->setTranslation(Vector(0.0f, 3.0f + 0.5, 15.0f));
	head = this->keyFrames[15]->getHead();
	head->setRotationAngles(Vector(0, 0, 0));
	rightArm = this->keyFrames[15]->getRightArm();
	rightArm->setRotationAngles(Vector(10, 0, -10));
	rightLowerArm = this->keyFrames[15]->getRightLowerArm();
	rightLowerArm->setRotationAngles(Vector(150, 70, 0));
	leftArm = this->keyFrames[15]->getLeftArm();
	leftArm->setRotationAngles(Vector(10, 0, 10));
	leftLowerArm = this->keyFrames[15]->getLeftLowerArm();
	leftLowerArm->setRotationAngles(Vector(150, -70, 0));
	leftFoot = this->keyFrames[15]->getLeftFoot();
	leftFoot->setRotationAngles(Vector(-20, 0, 0));
	rightFoot = this->keyFrames[15]->getRightFoot();
	rightFoot->setRotationAngles(Vector(-20, 0, 0));

	this->keyFrames[30] = new KeyFrame();
	this->keyFrames[30]->setIndex(30);
	torso = this->keyFrames[30]->getTorso();
	torso->setRotationAngles(Vector(0, 20, 0));
	torso->setTranslation(Vector(0.0f, 3.0f + 0.75, 15.0f));
	head = this->keyFrames[30]->getHead();
	head->setRotationAngles(Vector(0, 0, -10));
	rightArm = this->keyFrames[30]->getRightArm();
	rightArm->setRotationAngles(Vector(10, 0, -10));
	rightLowerArm = this->keyFrames[30]->getRightLowerArm();
	rightLowerArm->setRotationAngles(Vector(150, -70, 0));
	leftArm = this->keyFrames[30]->getLeftArm();
	leftArm->setRotationAngles(Vector(10, 0, 10));
	leftLowerArm = this->keyFrames[30]->getLeftLowerArm();
	leftLowerArm->setRotationAngles(Vector(150, 70, 0));
	leftFoot = this->keyFrames[30]->getLeftFoot();
	leftFoot->setRotationAngles(Vector(-40, 0, 0));
	rightFoot = this->keyFrames[30]->getRightFoot();
	rightFoot->setRotationAngles(Vector(-40, 0, 0));

	this->keyFrames[45] = new KeyFrame();
	this->keyFrames[45]->setIndex(45);
	torso = this->keyFrames[45]->getTorso();
	torso->setRotationAngles(Vector(0, 20, 0));
	torso->setTranslation(Vector(0.0f, 3.0f + 0.5, 15.0f));
	head = this->keyFrames[45]->getHead();
	head->setRotationAngles(Vector(0, 0, 0));
	rightArm = this->keyFrames[45]->getRightArm();
	rightArm->setRotationAngles(Vector(10, 0, -10));
	rightLowerArm = this->keyFrames[45]->getRightLowerArm();
	rightLowerArm->setRotationAngles(Vector(150, 70, 0));
	leftArm = this->keyFrames[45]->getLeftArm();
	leftArm->setRotationAngles(Vector(10, 0, 10));
	leftLowerArm = this->keyFrames[45]->getLeftLowerArm();
	leftLowerArm->setRotationAngles(Vector(150, -70, 0));
	leftFoot = this->keyFrames[45]->getLeftFoot();
	leftFoot->setRotationAngles(Vector(-20, 0, 0));
	rightFoot = this->keyFrames[45]->getRightFoot();
	rightFoot->setRotationAngles(Vector(-20, 0, 0));

	this->keyFrames[59] = new KeyFrame();
	this->keyFrames[59]->setIndex(59);
	torso = this->keyFrames[59]->getTorso();
	torso->setRotationAngles(Vector(0, 20, 0));
	torso->setTranslation(Vector(0.0f, 3.0f, 15.0f));
	head = this->keyFrames[59]->getHead();
	head->setRotationAngles(Vector(0, 0, 10));
	rightArm = this->keyFrames[59]->getRightArm();
	rightArm->setRotationAngles(Vector(10, 0, -10));
	rightLowerArm = this->keyFrames[59]->getRightLowerArm();
	rightLowerArm->setRotationAngles(Vector(150, -70, 0));
	leftArm = this->keyFrames[59]->getLeftArm();
	leftArm->setRotationAngles(Vector(10, 0, 10));
	leftLowerArm = this->keyFrames[59]->getLeftLowerArm();
	leftLowerArm->setRotationAngles(Vector(150, 70, 0));
	leftFoot = this->keyFrames[59]->getLeftFoot();
	leftFoot->setRotationAngles(Vector(0, 0, 0));
	rightFoot = this->keyFrames[59]->getRightFoot();
	rightFoot->setRotationAngles(Vector(0, 0, 0));

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

	delete this->keyFrames[0];
	delete this->keyFrames[15];
	delete this->keyFrames[30];
	delete this->keyFrames[45];
	delete this->keyFrames[59];
}

void Cycle::createPushUpCycle() {
	this->name = "PushUp";
	this->keyFrames.resize( Cycle::keyFramesPerCycle );

	this->keyFrames[0] = new KeyFrame();
	this->keyFrames[0]->setIndex(0);
	Mesh* torso = this->keyFrames[0]->getTorso();
	torso->setRotationAngles(Vector(20, 90, 90));
	torso->setTranslation(Vector(0.0f, -1.0f, 15.0f));
	Mesh* rightArm = this->keyFrames[0]->getRightArm();
	rightArm->setRotationAngles(Vector(75, 0, 0));
	Mesh* rightLowerArm = this->keyFrames[0]->getRightLowerArm();
	rightLowerArm->setRotationAngles(Vector(0, 0, 0));
	Mesh* leftArm = this->keyFrames[0]->getLeftArm();
	leftArm->setRotationAngles(Vector(75, 0, 0));
	Mesh* leftLowerArm = this->keyFrames[0]->getLeftLowerArm();
	leftLowerArm->setRotationAngles(Vector(0, 0, 0));
	Mesh* leftHand = this->keyFrames[0]->getLeftHand();
	leftHand->setRotationAngles(Vector(75, 0, 0));
	Mesh* rightHand = this->keyFrames[0]->getRightHand();
	rightHand->setRotationAngles(Vector(75, 0, 0));

	this->keyFrames[30] = new KeyFrame();
	this->keyFrames[30]->setIndex(30);
	torso = this->keyFrames[30]->getTorso();
	torso->setRotationAngles(Vector(0, 90, 90));
	torso->setTranslation(Vector(0.0f, -1.0f - 2.5f, 15.0f));
	rightArm = this->keyFrames[30]->getRightArm();
	rightArm->setRotationAngles(Vector(30, 0, 0));
	rightLowerArm = this->keyFrames[30]->getRightLowerArm();
	rightLowerArm->setRotationAngles(Vector(150, 0, 0));
	leftArm = this->keyFrames[30]->getLeftArm();
	leftArm->setRotationAngles(Vector(30, 0, 0));
	leftLowerArm = this->keyFrames[30]->getLeftLowerArm();
	leftLowerArm->setRotationAngles(Vector(150, 0, 0));
	leftHand = this->keyFrames[30]->getLeftHand();
	leftHand->setRotationAngles(Vector(0, 0, 0));
	rightHand = this->keyFrames[30]->getRightHand();
	rightHand->setRotationAngles(Vector(0, 0, 0));

	this->keyFrames[59] = new KeyFrame();
	this->keyFrames[59]->setIndex(59);
	torso = this->keyFrames[59]->getTorso();
	torso->setRotationAngles(Vector(20, 90, 90));
	torso->setTranslation(Vector(0.0f, -1.0f, 15.0f));
	rightArm = this->keyFrames[59]->getRightArm();
	rightArm->setRotationAngles(Vector(75, 0, 0));
	rightLowerArm = this->keyFrames[59]->getRightLowerArm();
	rightLowerArm->setRotationAngles(Vector(0, 0, 0));
	leftArm = this->keyFrames[59]->getLeftArm();
	leftArm->setRotationAngles(Vector(75, 0, 0));
	leftLowerArm = this->keyFrames[59]->getLeftLowerArm();
	leftLowerArm->setRotationAngles(Vector(0, 0, 0));
	leftHand = this->keyFrames[59]->getLeftHand();
	leftHand->setRotationAngles(Vector(75, 0, 0));
	rightHand = this->keyFrames[59]->getRightHand();
	rightHand->setRotationAngles(Vector(75, 0, 0));

	std::vector<Frame>* tmp = this->keyFrames[0]->interpolate(*this->keyFrames[30]);
	this->frames.insert( this->frames.end(), tmp->begin(), tmp->end() );
	delete tmp;

	tmp = this->keyFrames[30]->interpolate(*this->keyFrames[59]);
	this->frames.insert( this->frames.end(), tmp->begin(), tmp->end() );
	delete tmp;

	delete this->keyFrames[0];
	delete this->keyFrames[30];
	delete this->keyFrames[59];
}

std::vector<KeyFrame*> const & Cycle::getKeyFrames() {
	return this->keyFrames;
}

std::vector<Frame>& Cycle::getFrames() {
	return this->frames;
}

void	Cycle::setStartTime(unsigned time) {
	this->startTime = time;
}

unsigned	Cycle::getStartTime() const {
	return this->startTime;
}
