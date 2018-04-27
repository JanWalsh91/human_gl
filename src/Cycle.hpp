#ifndef CYCLE_H
# define CYCLE_H

# include "Frame.hpp"
# include "KeyFrame.hpp"
# include "Vector.hpp"

# include <string>

class Cycle {

	public:
		Cycle( void );
		Cycle( Cycle const & );
		~Cycle( void );

		Cycle & operator=( Cycle const & rhs );
		
		void	interpolate(); // call on each KeyFrame to interpolate Frames between itself and next KeyFrame
		void	play(); // loop over updating uniform matrix and VBO

	private:
		vector<KeyFrame>	keyFrames;
		vector<Frame>		frames;
		unsigned			totalTime;
		unsigned			framesPerCycle;
		static const unsigned	keyFramesPerCycle = 60;
		string				name;


};

#endif