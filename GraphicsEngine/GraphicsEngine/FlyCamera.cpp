#include "FlyCamera.h"


//-----------------------------------------------------------------------------------------------
// constructer initializes values.
//-----------------------------------------------------------------------------------------------
FlyCamera::FlyCamera()
{
	m_fSpeed = 10;
}

//-----------------------------------------------------------------------------------------------
// destructer deallocates memory.
//-----------------------------------------------------------------------------------------------
FlyCamera::~FlyCamera()
{
}
//-----------------------------------------------------------------------------------------------
// updates the flyCamera.
// Param:
//		deltaTime: A float which represents deltatime which increases over time
//		a_GLWindow: A pointer to the window.
//-----------------------------------------------------------------------------------------------
void FlyCamera::update(float deltaTime, GLFWwindow* a_GLWindow)
{
	// Calculate delta XY of mouse
	glfwGetCursorPos(a_GLWindow, &m_dMouseX, &m_dMouseY);
	// Radians to degrees
	m_dDeltaTiemMouseX = (640 - m_dMouseX) * 0.0174533;
	m_dDeltaTiemMouseY = (360 - m_dMouseY) * 0.0174533;

	// Keep mouse locked to screen
	glfwSetCursorPos(a_GLWindow, 640, 360);

	// Calculate reletive world up
	glm::vec4 up = glm::inverse(m_worldTransform) * glm::vec4(0,1,0,0);
	glm::mat4 rotMat(1.0f);
	// Rotate around world up
	rotMat = glm::rotate((float)-m_dDeltaTiemMouseX * deltaTime, glm::vec3(up[0], up[1], up[2]));
	m_viewTransform = rotMat * m_viewTransform;
	// Rotate up down
	rotMat = glm::rotate((float)-m_dDeltaTiemMouseY * deltaTime, glm::vec3(1, 0, 0));
	m_viewTransform = rotMat * m_viewTransform;
	// Update world transform
	m_worldTransform = glm::inverse(m_viewTransform);
	// Moves the camera based on the input
	if (glfwGetKey(a_GLWindow, GLFW_KEY_W))
	{
		m_worldTransform[3] += m_worldTransform[2] * deltaTime * -m_fSpeed;
	}
	if (glfwGetKey(a_GLWindow, GLFW_KEY_S))
	{
		m_worldTransform[3] += m_worldTransform[2] * deltaTime * m_fSpeed;
	}
	if (glfwGetKey(a_GLWindow, GLFW_KEY_A))
	{
		m_worldTransform[3] += m_worldTransform[0] * deltaTime * -m_fSpeed;
	}
	if (glfwGetKey(a_GLWindow, GLFW_KEY_D))
	{
		m_worldTransform[3] += m_worldTransform[0] * deltaTime * m_fSpeed;
	}

	m_worldTransform[3][3] = 1.0f;
	m_viewTransform = glm::inverse(m_worldTransform);

	updateProjectionViewTransform();
}
//-----------------------------------------------------------------------------------------------
// updates the flyCamera.
// Param:
//		speed: A float wich sets the speed of the flying camera
//-----------------------------------------------------------------------------------------------
void FlyCamera::setSpeed(float speed)
{
	m_fSpeed = speed;
}
