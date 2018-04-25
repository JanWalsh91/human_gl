#ifndef CYCLE_H
# define CYCLE_H

class Cycle {

	public:
		Cycle( void );
		Cycle( Cycle const & );
		~Cycle( void );

		Cycle & operator=( Cycle const & rhs );
		
	private:

};

#endif