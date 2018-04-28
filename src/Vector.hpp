#ifndef VECTOR_H
# define VECTOR_H

# include <vector>
# include <iostream>

class Vector {

	public:
		Vector( void );
		Vector( float x, float y, float z );
		Vector( Vector const & );
		~Vector( void );

		Vector &	operator=( Vector const & rhs );
		Vector 	operator+( Vector const & rhs );
		Vector 	operator-( Vector const & rhs );
		Vector 	operator*( Vector const & rhs );
		Vector 	operator*( float rhs );
		Vector 	operator/( Vector const & rhs );
		float &			operator[](int i);
		float const &	operator[](int i) const;

		float *	toArray( void );

	private:
		std::vector<float>	v;

};

std::ostream &	operator<<( std::ostream & o, Vector const & rhs );

#endif