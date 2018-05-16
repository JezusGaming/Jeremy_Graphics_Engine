#pragma once

#include <glm\glm.hpp>
#include <glm\ext.hpp>

#include "Gizmos.h"

class Planet
{
public:
	Planet();
	~Planet();

	void update(float deltaTime);
	void draw();

protected:

	glm::mat4 rot;
	// Parent
	glm::mat4 parentMatrix;
	// Child object
	glm::mat4 localMatrix;
	glm::mat4 globalMatrix;
};

