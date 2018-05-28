#include "Camera.h"



Camera::Camera()
{
	m_worldTransform = glm::mat4(1);
	m_viewTransform = glm::mat4(1);
	m_projectTransform = glm::mat4(1);
}


Camera::~Camera()
{
}

void Camera::setPerspective(float fieldOfView, float aspectRatio, float near, float far)
{
	m_projectTransform = glm::perspective(glm::pi<float>() * fieldOfView, aspectRatio, near, far);
}

void Camera::setLookAt(glm::vec3 from, glm::vec3 to, glm::vec3 up)
{
	m_viewTransform = glm::lookAt(from, to, up);
}

void Camera::setPosition(glm::vec3 position)
{
	m_worldTransform[3][0] = position.x;
	m_worldTransform[3][1] = position.y;
	m_worldTransform[3][2] = position.z;
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
	m_projectViewTransform = m_projectTransform * m_viewTransform;
}

