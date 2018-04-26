#ifndef MATRIX_H
# define MATRIX_H

# include <cstring>

class Matrix {

	public:
		Matrix( unsigned size );
		Matrix( Matrix const & );
		~Matrix( void );
		
		Matrix & operator=( Matrix const & rhs );
		float const & toArray( void ) const;

	private:
		Matrix( void );
		float		*m;
		unsigned	size;
};

#endif