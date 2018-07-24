#ifndef FRAME_HPP
# define FRAME_HPP

# include "Mesh/Mesh.hpp"

# include <vector>
# include <map>

class Frame {

public:
	Frame() {}
	Frame( Frame const & );

	~Frame();

	Mesh* getRoot() const;

	Mesh* getTorso()			const;
	Mesh* getHead()				const;
	Mesh* getRightArm()			const;
	Mesh* getRightLowerArm()	const;
	Mesh* getRightHand()		const;
	Mesh* getLeftArm()			const;
	Mesh* getLeftLowerArm()		const;
	Mesh* getLeftHand()			const;
	Mesh* getLeftLeg()			const;
	Mesh* getLeftLowerLeg()		const;
	Mesh* getRightLeg()			const;
	Mesh* getRightLowerLeg()	const;
	Mesh* getRightFoot()		const;
	Mesh* getLeftFoot()			const;

	typedef Mesh* (Frame::*getMesh) () const;
	std::map<std::string, getMesh> getMeshMap();

	static void setFrameLength(unsigned i);
	static unsigned getFrameLength(void);

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

	static unsigned frameLength;

private:

	std::map<std::string, getMesh> meshMap;
};

#endif
