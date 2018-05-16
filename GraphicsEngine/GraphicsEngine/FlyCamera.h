#pragma once
class FlyCamera
{
public:
	FlyCamera();
	~FlyCamera();


	// if (glfwGetKey(a_GLWindow, GLFW_KEY_W))
	// m_worldTransform[3] += m_worldTransform[2] * a_fDeltaTime * -m_fMovement
	// if (glfwGetKey(a_GLWindow, GLFW_KEY_S))
	// m_worldTransform[3] += m_worldTransform[2] * a_fDeltaTime * m_fMovement
	// if (glfwGetKey(a_GLWindow, GLFW_KEY_A))
	// m_worldTransform[3] += m_worldTransform[0] * a_fDeltaTime * -m_fMovement
	// if (glfwGetKey(a_GLWindow, GLFW_KEY_D))
	// m_worldTransform[3] += m_worldTransform[0] * a_fDeltaTime * m_fMovement
	// 400 300 need to be half of window
	// glfwGetCursorPos(a_GLWindow, &m_dMouseX, &m_dMouseY);
	// m_dDeltaTiemMouseX = (400 - m_dMouseX) * 0.0174533;
	// m_dDeltaTiemMouseY = (300 - m_dMouseY) * 0.0174533;
	// glfwSetCursorPos(a_GLWindow, 400 , 300);
	// glm::vec4 up = glm::inverse(m_worldTrasform) * glm::vec4(0,1,0,0);
	// glm::mat4 rotMat(1.0f);
	// rotMat = glm::rotate((float)-m_dDeltaMousX * a_fDeltaTime, glm::vec3(1,0,0);
	// m_viewTransform = rotMat * m_viewTransform;
	// m_worldTransform = glm::inverse(m_viewTransform)
};

