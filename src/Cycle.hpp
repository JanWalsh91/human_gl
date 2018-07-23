#ifndef CYCLE_H
# define CYCLE_H

# include "Frame.hpp"
# include "KeyFrame.hpp"
# include "Vector.hpp"

# include <GLFW/glfw3.h>
# include <string>

class Cycle {

public:
		
	enum Type {
		STANDING,
		WALKING,
		JUMPING,
		MOON_WALSH
	};

	Cycle( Cycle::Type );
	~Cycle( void );
		
	void	play();
	
	void	setStartTime( unsigned time ) { this->startTime = time; }
		
	Frame&	getCurrentFrame();
	unsigned	getStartTime() const { return this->startTime; }
	const std::vector<KeyFrame*>& getKeyFrames();
		
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

	static const unsigned	keyFramesPerCycle = 60;
};

#endif