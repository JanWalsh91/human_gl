#ifndef VECTOR_H
# define VECTOR_H

# include <vector>
# include <iostream>

class Matrix;

class Vector {
	
	public:
		Vector( void );
		Vector( float x, float y, float z );
		Vector( Vector const & );
		~Vector( void );
		
		Vector &	operator=( Vector const & rhs );
		Vector 	operator+( Vector const & rhs ) const;
		Vector 	operator-( Vector const & rhs ) const;
		Vector 	operator*( Vector const & rhs );
		Vector 	operator*( Matrix const & rhs );
		Vector 	operator*( float rhs );
		Vector 	operator/( Vector const & rhs );
		bool	operator==(Vector const & rhs);
		float &			operator[](int i);
		float const &	operator[](int i) const;
		void	normalize();
		
		float *	toArray( void );
		
	private:
		std::vector<float>	v;
};

# include "Matrix.hpp"

std::ostream &	operator<<( std::ostream & o, Vector const & rhs );

#endif