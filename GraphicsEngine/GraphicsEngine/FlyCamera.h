#pragma once
#include "Camera.h"
class FlyCamera : public Camera
{
public:
	FlyCamera();
	~FlyCamera();

	void update(float deltaTime, GLFWwindow* a_GLWindow);
	void setSpeed(float speed);

protected:
	float m_fSpeed;
	glm::vec3 up;

	double m_dMouseX;
	double m_dMouseY;

	double m_dDeltaTiemMouseX;
	double m_dDeltaTiemMouseY;
};

