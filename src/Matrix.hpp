#ifndef MATRIX_H
# define MATRIX_H

# include <cstring>

class Matrix {

	public:
		Matrix( void );
		Matrix( Matrix const & );
		~Matrix( void );

		Matrix & operator=( Matrix const & rhs );
	
	private:
		float	m[16];
};

#endif