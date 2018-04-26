#include "Glfw.cpp"
#include "Matrix.cpp"

#include <vector>

int    main ( void ) {
	
	Matrix m(4);
	std::cout << m[0] << std::endl;
	Matrix n = m;
	
	std::cout << n <<std::endl;
	
	// std::vector<float> m;
	return (0);
}