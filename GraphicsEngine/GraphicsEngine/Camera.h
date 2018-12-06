#pragma once
#include <glm\glm.hpp>
#include <glm\ext.hpp>

#include "glfw3.h"

class Camera
{
public:
	//-----------------------------------------------------------------------------------------------
	// constructer initializes values.
	//-----------------------------------------------------------------------------------------------
	Camera();
	//-----------------------------------------------------------------------------------------------
	// destructer deallocates memory.
	//-----------------------------------------------------------------------------------------------
	~Camera();
	//-----------------------------------------------------------------------------------------------
	// updates the camera.
	// Param:
	//		deltaTime: A float which represents deltatime which increases over time
	//		a_GLWindow: A pointer to the window.
	//-----------------------------------------------------------------------------------------------
	virtual void update(const float deltaTime, GLFWwindow* a_GLWindow) = 0;
	//-----------------------------------------------------------------------------------------------
	// set the perspective of the camera.
	// Param:
	//		fieldOfView: A float which represents the field of view of the camera.
	//		aspectRatio: A float used to set the aspectRatio.
	//		near: A float used to set the near of the perspective.
	//		far: A float used to set the far of the perspective.
	//-----------------------------------------------------------------------------------------------
	void setPerspective(const float fieldOfView, const float aspectRatio, const float near, 
		const float far);
	//-----------------------------------------------------------------------------------------------
	// sets the LookAt of the camera.
	// Param:
	//		from: A vec3 of where it is from.
	//		to: A vec3 of where to lookAt.
	//		up: A vec3 which is used for the up vector.
	//-----------------------------------------------------------------------------------------------
	void setLookAt(const glm::vec3 from, const glm::vec3 to, const glm::vec3 up);
	//-----------------------------------------------------------------------------------------------
	// sets the postition of the camera.
	// Param:
	//		position: A float which represents the position of the camera.
	//-----------------------------------------------------------------------------------------------
	void setPosition(const glm::vec3 position);
	//-----------------------------------------------------------------------------------------------
	// Gets the worldTransform.
	// Return:
	//		Returns a mat4 m_worldTransform.
	//-----------------------------------------------------------------------------------------------
	glm::mat4 getWorldTransform() const;
	//-----------------------------------------------------------------------------------------------
	// Gets the viewTransform.
	// Return:
	//		Returns a mat4 m_viewTransform.
	//-----------------------------------------------------------------------------------------------
	glm::mat4 getView() const;
	//-----------------------------------------------------------------------------------------------
	// Gets the projectionTransform.
	// Return:
	//		Returns a mat4 m_projectTransform.
	//-----------------------------------------------------------------------------------------------
	glm::mat4 getProjection() const;
	//-----------------------------------------------------------------------------------------------
	// Gets the projectViewTransform.
	// Return:
	//		Returns a mat4 m_projectViewTransform.
	//-----------------------------------------------------------------------------------------------
	glm::mat4 getProjectionView() const;

protected:
	//-----------------------------------------------------------------------------------------------
	// updates the project * View Transform.
	//-----------------------------------------------------------------------------------------------
	void updateProjectionViewTransform();

	glm::mat4 m_worldTransform;
	glm::mat4 m_viewTransform;
	glm::mat4 m_projectTransform;
	glm::mat4 m_projectViewTransform;
};

