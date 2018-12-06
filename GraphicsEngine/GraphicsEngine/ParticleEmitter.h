#pragma once
#include <glm\glm.hpp>
#include <glm\ext.hpp>
#include "../dependencies/glcore//gl_core_4_5.h"

class ParticleEmitter
{
public:
	//-----------------------------------------------------------------------------------------------
	// constructer initializes values.
	//-----------------------------------------------------------------------------------------------
	ParticleEmitter();
	//-----------------------------------------------------------------------------------------------
	// destructer deallocates memory.
	//-----------------------------------------------------------------------------------------------
	virtual ~ParticleEmitter();

	struct Particle {
		//-----------------------------------------------------------------------------------------------
		// vec3 used to store the position of the particle.
		//-----------------------------------------------------------------------------------------------
		glm::vec3 position;
		//-----------------------------------------------------------------------------------------------
		// vec3 used to store the vel of the particle.
		//-----------------------------------------------------------------------------------------------
		glm::vec3 velocity;
		//-----------------------------------------------------------------------------------------------
		// vec3 used to store the colour of the particle.
		//-----------------------------------------------------------------------------------------------
		glm::vec4 colour;
		//-----------------------------------------------------------------------------------------------
		// float used to store the size of the particle.
		//-----------------------------------------------------------------------------------------------
		float size;
		//-----------------------------------------------------------------------------------------------
		// float used to store the lifetime of the particle.
		//-----------------------------------------------------------------------------------------------
		float lifetime;
		//-----------------------------------------------------------------------------------------------
		// float used to store the lifespan of the particle.
		//-----------------------------------------------------------------------------------------------
		float lifespan;
	};
	struct ParticleVertex {
		//-----------------------------------------------------------------------------------------------
		// vec3 used to store the position of the particle vertex.
		//-----------------------------------------------------------------------------------------------
		glm::vec4 position;
		//-----------------------------------------------------------------------------------------------
		// vec3 used to store the colour of the particle vertex.
		//-----------------------------------------------------------------------------------------------
		glm::vec4 colour;
	};

	//-----------------------------------------------------------------------------------------------
	// initalises the particles and their variables such as colour, lifetime, etc.
	//
	// Param:
	//		a_maxParticles: an unsigned int used for max particles used.
	//		a_emitRate: unsigned int used to set the rate that particles emit.
	//		a_lifetimeMin: a float which sets the min life time.
	//		a_lifetimeMax: a float which sets the max life time.
	//		a_velocityMin: it is a float used to set the min velocity of the particle.
	//		a_velocityMax: it is a float used to set the max velocity of the particle.
	//		a_startSize: the start size of the particle which is a float.
	//		a_endSize: the end size of the particle which is a float.
	//		a_startColour: is a vec4 which sets the start colour of the particles.
	//		a_endColour: is a vec4 which sets the end colour of the particles.
	//-----------------------------------------------------------------------------------------------
	void initalise(unsigned int a_maxParticles, unsigned int a_emitRate, float a_lifetimeMin, 
		float a_lifetimeMax, float a_velocityMin, float a_velocityMax, float a_startSize, 
		float a_endSize, const glm::vec4& a_startColour, const glm::vec4& a_endColour);
	//-----------------------------------------------------------------------------------------------
	// emits particles and resurrect the first dead particle, randomise its lifespan, sets start 
	// colour and size, as well as randomise velocity direction and strength.
	//-----------------------------------------------------------------------------------------------
	void emit();
	//-----------------------------------------------------------------------------------------------
	// spawns particles and updates particles and turn live particles into billboard quads.
	//-----------------------------------------------------------------------------------------------
	void update(float a_deltaTime, const glm::mat4& a_cameraTransform);
	//-----------------------------------------------------------------------------------------------
	// draw particles and syncs the particle vertex buffer.
	//-----------------------------------------------------------------------------------------------
	void draw();

protected:
	//-----------------------------------------------------------------------------------------------
	// a pointer to particle.
	//-----------------------------------------------------------------------------------------------
	Particle* m_particles;
	//-----------------------------------------------------------------------------------------------
	// an unsigned int used to for the first dead particle.
	//-----------------------------------------------------------------------------------------------
	unsigned int m_firstDead;
	//-----------------------------------------------------------------------------------------------
	// an unsigned int used for seting max particles.
	//-----------------------------------------------------------------------------------------------
	unsigned int m_maxParticles;
	//-----------------------------------------------------------------------------------------------
	// unsigned int used for Vertex Buffer Objects (VBOs), Vertex Array Objects(VAOs), 
	// Index Buffer Objects(IBOs).
	//-----------------------------------------------------------------------------------------------
	unsigned int m_vao, m_vbo, m_ibo;
	//-----------------------------------------------------------------------------------------------
	// a pointer to particleVertex.
	//-----------------------------------------------------------------------------------------------
	ParticleVertex* m_vertexData;
	//-----------------------------------------------------------------------------------------------
	// vec3 which is used for the position.
	//-----------------------------------------------------------------------------------------------
	glm::vec3 m_position;
	//-----------------------------------------------------------------------------------------------
	// float used fro an emit timer.
	//-----------------------------------------------------------------------------------------------
	float m_emitTimer;
	//-----------------------------------------------------------------------------------------------
	// float used to set the rate that particles emit.
	//-----------------------------------------------------------------------------------------------
	float m_emitRate;
	//-----------------------------------------------------------------------------------------------
	// a float used to set the min life time.
	//-----------------------------------------------------------------------------------------------
	float m_lifespanMin;
	//-----------------------------------------------------------------------------------------------
	// a float used to set the max life time.
	//-----------------------------------------------------------------------------------------------
	float m_lifespanMax;
	//-----------------------------------------------------------------------------------------------
	// a float used to set the min vel.
	//-----------------------------------------------------------------------------------------------
	float m_velocityMin;
	//-----------------------------------------------------------------------------------------------
	// a float used to set the max vel.
	//-----------------------------------------------------------------------------------------------
	float m_velocityMax;
	//-----------------------------------------------------------------------------------------------
	//  a float used to set the start size.
	//-----------------------------------------------------------------------------------------------
	float m_startSize;
	//-----------------------------------------------------------------------------------------------
	// a float used to set the end size.
	//-----------------------------------------------------------------------------------------------
	float m_endSize;
	//-----------------------------------------------------------------------------------------------
	// a float used to set the start colour.
	//-----------------------------------------------------------------------------------------------
	glm::vec4 m_startColour;
	//-----------------------------------------------------------------------------------------------
	// a float used to set the end colour.
	//-----------------------------------------------------------------------------------------------
	glm::vec4 m_endColour;

};
