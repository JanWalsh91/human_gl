#ifndef CYCLE_H
# define CYCLE_H

# include "Frame.hpp"
# include "KeyFrame.hpp"
# include "Vector.hpp"

# include <GLFW/glfw3.h>
# include <string>

class Cycle {

	public:
		
		enum Type { WALKING };

		Cycle( Cycle::Type );
		~Cycle( void );
		
		void	interpolate(); // call on each KeyFrame to interpolate Frames between itself and next KeyFrame
		void	play();
	
		void	setStartTime( unsigned time ) { this->startTime = time; }
		
		Frame&	getCurrentFrame();
		unsigned	getStartTime() { return this->startTime; }
		std::vector<KeyFrame*> const & getKeyFrames();
		
	private:
		std::vector<KeyFrame*>	keyFrames;
		std::vector<Frame>		frames;
		unsigned			totalTime;
		unsigned			framesPerCycle;
		unsigned			startTime;
		std::string				name;

		void createWalkingCycle();

		static const unsigned	keyFramesPerCycle = 60;
};

#endif