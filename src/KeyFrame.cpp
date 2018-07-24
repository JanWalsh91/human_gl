#include "KeyFrame.hpp"

KeyFrame::KeyFrame() {
	static int i = 0;
	this->torso			= new TorsoMesh();
	this->head			= new HeadMesh();
	this->rightArm		= new ArmMesh(Side::RIGHT);
	this->rightLowerArm = new LowerArmMesh(Side::RIGHT);
	this->rightHand		= new HandMesh(Side::RIGHT);
	this->leftArm		= new ArmMesh(Side::LEFT);
	this->leftLowerArm	= new LowerArmMesh(Side::LEFT);
	this->leftHand		= new HandMesh(Side::LEFT);
	this->leftLeg		= new LegMesh(Side::LEFT);
	this->leftLowerLeg	= new LowerLegMesh(Side::LEFT);
	this->rightLeg		= new LegMesh(Side::RIGHT);
	this->rightLowerLeg	= new LowerLegMesh(Side::RIGHT);
	this->rightFoot		= new FootMesh(Side::RIGHT);
	this->leftFoot		= new FootMesh(Side::LEFT);

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

KeyFrame::~KeyFrame( void ) {
	static int i = 0;
	//TODO ...
	// delete this->torso;
	// delete this->head;
	// delete this->rightArm;
	// delete this->rightLowerArm;
	// delete this->rightHand;
	// delete this->leftArm;
	// delete this->leftLowerArm;
	// delete this->leftHand;
	// delete this->leftLeg;
	// delete this->leftLowerLeg;
	// delete this->rightLeg;
	// delete this->rightLowerLeg;
	// delete this->rightFoot;
	// delete this->leftFoot;
}

KeyFrame & KeyFrame::operator=( KeyFrame const & rhs ) {
	return *this;
}

// returns list of interpolated frames between two KeyFrames
std::vector<Frame>* KeyFrame::interpolate( KeyFrame const & other ) {
	int size = std::abs(other.index - this->index) * Frame::frameLength;
	KeyFrame *tmp = new KeyFrame();
	std::vector<Frame>* frames = new std::vector<Frame>( size, *dynamic_cast<Frame *>(tmp) );
	delete tmp;
	std::vector<Mesh*> meshesFirst;
	std::vector<Mesh*> meshesFinal;
	std::vector<Mesh*> meshesToUpdate;


	this->copyFramesToList(meshesFirst, *this);
	this->copyFramesToList(meshesFinal, other);
	for( int i = 0; i < size; ++i ) {
		float step = (float)i / (float)size;
		Frame &	currentFrame = (*frames)[i];		
		meshesToUpdate.clear();

		this->addFramesToList( meshesToUpdate, currentFrame );
		for( unsigned y = 0; y < meshesFirst.size(); ++y ) {
			this->updateMeshValues(
				meshesFirst[y],
				meshesFinal[y],
				meshesToUpdate[y],
				step
			);
		}
	}

	for (Mesh* p: meshesFirst) {
		delete p;
	}
	for (Mesh* p: meshesFinal) {
		delete p;
	}
	return frames;
}

// std::vector<Frame>* KeyFrame::interpolate( KeyFrame const & other, std::vector<Frame> *frames /* list f {"rightFoot"} */ ) {
// 	if (frame) {
// 		// modify existing frames
// 	}
// 	else {
// 		// create new frames
// 	}
// 	if (rightFoot)

// 	return frames;
// }

void	KeyFrame::copyFramesToList( std::vector<Mesh*> & list, Frame const & frame ) {
	list.push_back( new Mesh(*frame.getTorso()) );
	list.push_back( new Mesh(*frame.getHead()) );
	list.push_back( new Mesh(*frame.getRightArm()) );
	list.push_back( new Mesh(*frame.getRightLowerArm()) );
	list.push_back( new Mesh(*frame.getRightHand()) );
	list.push_back( new Mesh(*frame.getLeftArm()) );
	list.push_back( new Mesh(*frame.getLeftLowerArm()) );
	list.push_back( new Mesh(*frame.getLeftHand()) );
	list.push_back( new Mesh(*frame.getLeftLeg()) );
	list.push_back( new Mesh(*frame.getLeftLowerLeg()) );
	list.push_back( new Mesh(*frame.getRightLeg()) );
	list.push_back( new Mesh(*frame.getRightLowerLeg()) );
	list.push_back( new Mesh(*frame.getRightFoot()) );
	list.push_back( new Mesh(*frame.getLeftFoot()) );
}

void	KeyFrame::addFramesToList( std::vector<Mesh*> & list, Frame const & frame ) {
	list.push_back( frame.getTorso() );
	list.push_back( frame.getHead() );
	list.push_back( frame.getRightArm() );
	list.push_back( frame.getRightLowerArm() );
	list.push_back( frame.getRightHand() );
	list.push_back( frame.getLeftArm() );
	list.push_back( frame.getLeftLowerArm() );
	list.push_back( frame.getLeftHand() );
	list.push_back( frame.getLeftLeg() );
	list.push_back( frame.getLeftLowerLeg() );
	list.push_back( frame.getRightLeg() );
	list.push_back( frame.getRightLowerLeg() );
	list.push_back( frame.getRightFoot() );
	list.push_back( frame.getLeftFoot() );
}

void	KeyFrame::updateMeshValues( Mesh * meshFirst, Mesh * meshLast, Mesh * meshToUpdate, float fraction ) {

	Vector firstRotation = meshFirst->getRotationAngles();
	Vector lastRotation = meshLast->getRotationAngles();
	Vector currentRotation = meshToUpdate->getRotationAngles();
	
	Vector newRotation = firstRotation + (lastRotation - firstRotation) * fraction;
	
	meshToUpdate->setRotationAngles(newRotation);
	
	meshToUpdate->setTranslation(
		meshFirst->getTranslation() + ( meshLast->getTranslation() - meshFirst->getTranslation() ) * fraction
	);
		
	meshToUpdate->setScale(
		meshFirst->getScale() + ( meshLast->getScale() - meshFirst->getScale() ) * fraction
	);
}