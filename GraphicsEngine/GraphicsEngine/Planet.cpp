#include "Planet.h"

Planet::Planet()
{
	parentMatrix = glm::mat4(1);
	parentMatrix[3] = glm::vec4(0, 0, 10, 1);

	rot = glm::mat4(1);
	rot = glm::rotate(0.7853975f, glm::vec3(0, 1, 0));

	parentMatrix = rot * parentMatrix;

	localMatrix = glm::mat4(1);
	localMatrix[3] = glm::vec4(0, 0, -2, 1);

	globalMatrix = localMatrix * parentMatrix;
}


Planet::~Planet()
{
}

void Planet::update(float deltaTime)
{
	// Create rotation matrix
	rot = glm::rotate(deltaTime, glm::vec3(0, 1, 0));
	// Apply rotation to parent
	// Parent orbits center
	parentMatrix = rot * parentMatrix;
	// Parent spins
	rot = glm::rotate(deltaTime * 3, glm::vec3(0, 1, 0));
	parentMatrix = parentMatrix * rot;
	// Child syncs with parent
	rot = glm::rotate(deltaTime * -5, glm::vec3(0, 1, 0));
	localMatrix = rot * localMatrix;
	// Spins child
	rot = glm::rotate(deltaTime * 5, glm::vec3(0, 1, 0));
	localMatrix = localMatrix * rot;
	// once child syncs with parent
	globalMatrix = parentMatrix * localMatrix;
}

void Planet::draw()
{
	aie::Gizmos::addSphere(glm::vec3(0), 1, 4, 4, glm::vec4(1, 1, 0, 1), &parentMatrix);
	aie::Gizmos::addSphere(glm::vec3(0), 0.5f, 4, 4, glm::vec4(1, 0, 0, 1), &globalMatrix);
}
