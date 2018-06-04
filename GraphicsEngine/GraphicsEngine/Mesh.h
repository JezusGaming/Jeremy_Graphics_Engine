#pragma once
#include "ApplicationCore.h"
class Mesh
{
public:
	Mesh() : triCount(0), vao(0), vbo(0), ibo(0) {}
	~Mesh();

	struct Vertex {
		glm::vec4 position;
		glm::vec4 normal;
		glm::vec2 texCoord;
	};

	void initialise(unsigned int vertexCount, const Vertex* vertices,
		unsigned int indexCount = 0,
		unsigned int* indices = nullptr);
	void initialiseQuad();
	virtual void draw();

protected:
	unsigned int triCount;
	unsigned int  vao, vbo, ibo;
};

