#pragma once

#include <glm\glm.hpp>
#include <glm\ext.hpp>

#include "Gizmos.h"

class Planet
{
public:
	//-----------------------------------------------------------------------------------------------
	// constructer initializes values.
	//-----------------------------------------------------------------------------------------------
	Planet();
	//-----------------------------------------------------------------------------------------------
	// destructer deallocates memory.
	//-----------------------------------------------------------------------------------------------
	~Planet();
	//-----------------------------------------------------------------------------------------------
	// updates the planet.
	// Param:
	//		deltaTime: A float which represents deltatime which increases over time
	//-----------------------------------------------------------------------------------------------
	void update(float deltaTime);
	//-----------------------------------------------------------------------------------------------
	// draws the planet.
	//-----------------------------------------------------------------------------------------------
	void draw();

protected:
	// mat4 used for rotaion.
	glm::mat4 rot;
	// Parent.
	glm::mat4 parentMatrix;
	// Child object.
	glm::mat4 localMatrix;
	glm::mat4 globalMatrix;
};

