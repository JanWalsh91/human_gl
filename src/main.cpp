#include "Glfw.hpp"
#include "Matrix.hpp"

#include <vector>

int    main ( void ) {
	
	Matrix m(50, Matrix::TYPE::ROTATION_X);
	std::cout << m << std::endl;

	return (0);
}