#pragma once
#include <glm\glm.hpp>
#include <glm\ext.hpp>

#include "glfw3.h"

class Camera
{
public:
	Camera();
	~Camera();

	virtual void update(const float deltaTime, GLFWwindow* a_GLWindow) = 0;
	void setPerspective(const float fieldOfView, const float aspectRatio, const float near, const float far);
	void setLookAt(const glm::vec3 from, const glm::vec3 to, const glm::vec3 up);
	void setPosition(const glm::vec3 position);
	glm::mat4 getWorldTransform() const;
	glm::mat4 getView() const;
	glm::mat4 getProjection() const;
	glm::mat4 getProjectionView() const;

protected:

	void updateProjectionViewTransform();

	glm::mat4 m_worldTransform;
	glm::mat4 m_viewTransform;
	glm::mat4 m_projectTransform;
	glm::mat4 m_projectViewTransform;
};

