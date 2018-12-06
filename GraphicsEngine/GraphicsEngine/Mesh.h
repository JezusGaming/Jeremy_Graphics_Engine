#pragma once
#include "ApplicationCore.h"
class Mesh
{
public:
	//-----------------------------------------------------------------------------------------------
	// constructer initializes values.
	//-----------------------------------------------------------------------------------------------
	Mesh() : triCount(0), vao(0), vbo(0), ibo(0) {}
	//-----------------------------------------------------------------------------------------------
	// destructer deallocates memory.
	//-----------------------------------------------------------------------------------------------
	~Mesh();

	struct Vertex {
		//-----------------------------------------------------------------------------------------------
		// vec4 used to store the position of the vertex.
		//-----------------------------------------------------------------------------------------------
		glm::vec4 position;
		//-----------------------------------------------------------------------------------------------
		// vec4 used to store the normal of the vertex.
		//-----------------------------------------------------------------------------------------------
		glm::vec4 normal;
		//-----------------------------------------------------------------------------------------------
		// vec2 used to store the texcoord of the vertex.
		//-----------------------------------------------------------------------------------------------
		glm::vec2 texCoord;
	};
	//-----------------------------------------------------------------------------------------------
	// initialised a mesh based on the parameters.
	//-----------------------------------------------------------------------------------------------
	void initialise(unsigned int vertexCount, const Vertex* vertices, unsigned int indexCount = 0, 
		unsigned int* indices = nullptr);
	//-----------------------------------------------------------------------------------------------
	// initialised a quad mesh which can be textured in the future.
	//-----------------------------------------------------------------------------------------------
	void initialiseQuad();
	//-----------------------------------------------------------------------------------------------
	// used to draw mesh.
	//-----------------------------------------------------------------------------------------------
	virtual void draw();

protected:
	unsigned int triCount;
	//-----------------------------------------------------------------------------------------------
	// unsigned int used for Vertex Buffer Objects (VBOs), Vertex Array Objects(VAOs), 
	// Index Buffer Objects(IBOs).
	//-----------------------------------------------------------------------------------------------
	unsigned int  vao, vbo, ibo;
};

