#ifndef CYCLE_H
# define CYCLE_H

# include "KeyFrame.hpp"
# include "Vector.hpp"

# include <string>

class Cycle {

public:
		
	enum Type {
		STAND,
		WALK,
		JUMP,
		MOON_WALK,
		WAVE,
		PUSH_UP
	};

	Cycle( Cycle::Type );
	~Cycle( void );
		
	void	play();
	
	void	setStartTime( unsigned time ) { this->startTime = time; }
		
	Frame&	getCurrentFrame();
	unsigned	getStartTime() const { return this->startTime; }
	const std::vector<KeyFrame*>& getKeyFrames();
	std::vector<Frame>& getFrames();
		
private:
	std::vector<KeyFrame*>	keyFrames;
	std::vector<Frame>		frames;
	unsigned			totalTime;
	unsigned			framesPerCycle;
	unsigned			startTime;
	std::string				name;

	void createStandingCycle();
	void createWalkingCycle();
	void createJumpingCycle();
	void createMoonWalshCycle();
	void createWaveCycle();
	void createPushUpCycle();

	static const unsigned	keyFramesPerCycle = 60;
};

#endif
