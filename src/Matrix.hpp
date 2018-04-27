#ifndef MATRIX_H
# define MATRIX_H

# include "Vector.hpp"

# include <cstring>
# include <iostream>
# include <vector>
# include <exception>
# include <cmath>

class Matrix {

	public:
		Matrix( void );
		Matrix( unsigned size );

		enum TYPE {
			ROTATION_X,
			ROTATION_Y,
			ROTATION_Z,
			SCALE,
			TRANSLATE
		};

		Matrix( float angle, Matrix::TYPE type );

		Matrix( Vector const & v, Matrix::TYPE type );
		Matrix( Matrix const & );
		~Matrix( void );
		
		Matrix &	operator=( Matrix const & rhs );
		Matrix		operator*( Matrix const & rhs );
		Matrix		operator*( Vector const & rhs );
		float &			operator[](int i);
		float const &	operator[](int i) const;

		float *	toArray( void );

		unsigned		getSize( void ) const;
	


	private:
		unsigned			size;
		std::vector<float>	m;
		void	rot_x( float angle );
		void	rot_y( float angle );
		void	rot_z( float angle );
	
	class OperationImpossible : public std::exception {
		virtual const char* what() const throw();
	};
};

std::ostream &	operator<<( std::ostream & o, Matrix const & rhs );

#endif