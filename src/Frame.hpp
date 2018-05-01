#ifndef FRAME_H
# define FRAME_H

# include "Mesh/Mesh.hpp"

# include <vector>

class Frame {

public:
	Frame() {}
	Frame( Frame const & );

	virtual ~Frame() {}

	Mesh* getRoot() { return this->root; }

	Mesh* getTorso() const { return this->torso; }
	Mesh* getHead() const { return this->head; }
	Mesh* getRightArm() const { return this->rightArm; }
	Mesh* getRightLowerArm() const { return this->rightLowerArm; }
	Mesh* getRightHand() const { return this->rightHand; }
	Mesh* getLeftArm() const { return this->leftArm; }
	Mesh* getLeftLowerArm() const { return this->leftLowerArm; }
	Mesh* getLeftHand() const { return this->leftHand; }
	Mesh* getLeftLeg() const { return this->leftLeg; }
	Mesh* getLeftLowerLeg() const { return this->leftLowerLeg; }
	Mesh* getRightLeg() const { return this->rightLeg; }
	Mesh* getRightLowerLeg() const { return this->rightLowerLeg; }
	Mesh* getRightFoot() const { return this->rightFoot; }
	Mesh* getLeftFoot() const { return this->leftFoot; }

protected:
	Mesh* root;

	Mesh* torso;
	Mesh* head;
	Mesh* rightArm;
	Mesh* rightLowerArm;
	Mesh* rightHand;
	Mesh* leftArm;
	Mesh* leftLowerArm;
	Mesh* leftHand;
	Mesh* leftLeg;
	Mesh* leftLowerLeg;
	Mesh* rightLeg;
	Mesh* rightLowerLeg;
	Mesh* rightFoot;
	Mesh* leftFoot;

	static const unsigned frameLength = 16; //ms
};


#endif
