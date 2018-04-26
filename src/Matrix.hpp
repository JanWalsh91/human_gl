#ifndef MATRIX_H
# define MATRIX_H

# include <cstring>
# include <iostream>
# include <vector>

class Matrix {

	public:
		Matrix( void );
		Matrix( unsigned size );
		Matrix( Matrix const & );
		~Matrix( void );
		
		Matrix &	operator=( Matrix const & rhs );
		float		operator[](int i);
		const float &	operator[](int i) const;

		float const &	toArray( void ) const;

		unsigned		getSize( void ) const;
	
	private:
		unsigned		size;
		std::vector<float>	m;
};

std::ostream &	operator<<( std::ostream & o, Matrix const & rhs );

#endif