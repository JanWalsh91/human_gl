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
		Cycle( Cycle const & );
		~Cycle( void );

		Cycle & operator=( Cycle const & rhs );
		
		void	interpolate(); // call on each KeyFrame to interpolate Frames between itself and next KeyFrame
		void	play(); // loop over updating uniform matrix and VBO

		Frame&	getCurrentFrame();

		void	setStartTime( unsigned time ) { this->startTime = time; }
		unsigned	getStartTime() { return this->startTime; }
		
		std::vector<KeyFrame*>	keyFrames;

	private:
		std::vector<Frame>		frames;
		unsigned			totalTime;
		unsigned			framesPerCycle;
		unsigned			startTime;
		std::string				name;

		void createWalkingCycle();


		static const unsigned	keyFramesPerCycle = 60;

};

#endif