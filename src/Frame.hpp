#ifndef FRAME_H
# define FRAME_H

# include "Mesh/Mesh.hpp"

# include <vector>

class Frame {

public:
	Frame() {}

	virtual ~Frame() {}


	void render();
	Mesh* getRoot() { return this->root; }

	Mesh* getTorso() { return this->torso; }
	Mesh* getHead() { return this->head; }
	Mesh* getRightArm() { return this->rightArm; }
	Mesh* getRightLowerArm() { return this->rightLowerArm; }
	Mesh* getRightHand() { return this->rightHand; }
	Mesh* getLeftArm() { return this->leftArm; }
	Mesh* getLeftLowerArm() { return this->leftLowerArm; }
	Mesh* getLeftHand() { return this->leftHand; }
	Mesh* getLeftLeg() { return this->leftLeg; }
	Mesh* getLeftLowerLeg() { return this->leftLowerLeg; }
	Mesh* getRightLeg() { return this->rightLeg; }
	Mesh* getRightLowerLeg() { return this->rightLowerLeg; }
	Mesh* getRightFoot() { return this->rightFoot; }
	Mesh* getLeftFoot() { return this->leftFoot; }

protected:
	// std::vector<Mesh> meshes;
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

	static const unsigned frameLength = 16;
};


#endif
