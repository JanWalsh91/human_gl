#ifndef CAMERA_HPP
# define CAMERA_HPP

# include "Matrix.hpp"
# include "Vector.hpp"

class Camera {

public:

	Camera();
	virtual ~Camera();

	const Matrix& getViewMatrix();
	const Vector & getCameraDirection();

	void setCameraDirection(Vector newDirection);

private:

	Matrix		viewMatrix;
	Vector		camPos;
	Vector		camDir;
	Vector		camRight;
	Vector		camUp;

};

#endif
