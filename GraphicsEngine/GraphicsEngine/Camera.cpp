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
//-----------------------------------------------------------------------------------------------
// set the perspective of the camera.
// Param:
//		fieldOfView: A float which represents the field of view of the camera.
//		aspectRatio: A float used to set the aspectRatio.
//		near: A float used to set the near of the perspective.
//		far: A float used to set the far of the perspective.
//-----------------------------------------------------------------------------------------------
void Camera::setPerspective(float fieldOfView, float aspectRatio, float near, float far)
{
	m_projectTransform = glm::perspective(glm::pi<float>() * fieldOfView, aspectRatio, near, far);
}
//-----------------------------------------------------------------------------------------------
// sets the LookAt of the camera.
// Param:
//		from: A vec3 of where it is from.
//		to: A vec3 of where to lookAt.
//		up: A vec3 which is used for the up vector.
//-----------------------------------------------------------------------------------------------
void Camera::setLookAt(glm::vec3 from, glm::vec3 to, glm::vec3 up)
{
	m_viewTransform = glm::lookAt(from, to, up);
}
//-----------------------------------------------------------------------------------------------
// sets the postition of the camera.
// Param:
//		position: A float which represents the position of the camera.
//-----------------------------------------------------------------------------------------------
void Camera::setPosition(glm::vec3 position)
{
	m_worldTransform[3][0] = position.x;
	m_worldTransform[3][1] = position.y;
	m_worldTransform[3][2] = position.z;
}
//-----------------------------------------------------------------------------------------------
// Gets the worldTransform.
// Return:
//		Returns a mat4 m_worldTransform.
//-----------------------------------------------------------------------------------------------
glm::mat4 Camera::getWorldTransform() const
{
	return m_worldTransform;
}
//-----------------------------------------------------------------------------------------------
// Gets the viewTransform.
// Return:
//		Returns a mat4 m_viewTransform.
//-----------------------------------------------------------------------------------------------
glm::mat4 Camera::getView() const
{
	return m_viewTransform;
}
//-----------------------------------------------------------------------------------------------
// Gets the projectionTransform.
// Return:
//		Returns a mat4 m_projectTransform.
//-----------------------------------------------------------------------------------------------
glm::mat4 Camera::getProjection() const
{
	return m_projectTransform;
}
//-----------------------------------------------------------------------------------------------
// Gets the projectViewTransform.
// Return:
//		Returns a mat4 m_projectViewTransform.
//-----------------------------------------------------------------------------------------------
glm::mat4 Camera::getProjectionView() const
{
	return m_projectViewTransform;
}
//-----------------------------------------------------------------------------------------------
// updates the project * View Transform.
//-----------------------------------------------------------------------------------------------
void Camera::updateProjectionViewTransform()
{
	m_projectViewTransform = m_projectTransform * m_viewTransform;
}

