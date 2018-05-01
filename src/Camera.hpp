#ifndef CAMERA_HPP
#define CAMERA_HPP

#include "Matrix.hpp"
#include "Vector.hpp"

class Camera {

public:

	Camera();
	virtual ~Camera();

	Matrix const & getViewMatrix();
	Vector const & getCameraDirection();

	void setCameraDirection(Vector newDirection);

private:

	Matrix		viewMatrix;
	Vector		camPos;
	Vector		camDir;
	Vector		camRight;
	Vector		camUp;

};


#endif
