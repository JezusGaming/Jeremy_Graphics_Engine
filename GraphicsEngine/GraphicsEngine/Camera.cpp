#include "Camera.h"



Camera::Camera()
{
}


Camera::~Camera()
{
}

void Camera::setPerspective(float fieldOfView, float aspectRatio, float near, float)
{
}

void Camera::setLookAt(glm::vec3 from, glm::vec3 to, glm::vec3 up)
{
}

void Camera::setPosition(glm::vec3 position)
{
}

glm::mat4 Camera::getWorldTransform() const
{
	return m_worldTransform;
}

glm::mat4 Camera::getView() const
{
	return m_viewTransform;
}

glm::mat4 Camera::getProjection() const
{
	return m_projectTransform;
}

glm::mat4 Camera::getProjectionView() const
{
	return m_projectViewTransform;
}

void Camera::updateProjectionViewTransform()
{
}

