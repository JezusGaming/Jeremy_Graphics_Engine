#pragma once
#include "ApplicationCore.h"
#include "Planet.h"
#include "FlyCamera.h"
#include "Mesh.h"
#include "Shader.h"
#include "OBJMesh.h"

class Application
{
public:
	Application();
	~Application();

	int Initialize(const glm::ivec2 & resolution = glm::ivec2(1280,720), const char * window = "Graphics engine");
	void Run();
	void Render();
	void Terminate();

protected:
	my::clock m_clock;
	my::time m_startTime;
	my::time m_currentTime;
	my::time m_previousTime;

	GLFWwindow* m_window;

	Planet* planet;

	FlyCamera* MyCamera;

	aie::Texture m_gridTexture;

	aie::ShaderProgram m_shader;

	aie::OBJMesh m_bunnyMesh;
	glm::mat4 m_bunnyTransform;

	aie::OBJMesh m_spearMesh;
	glm::mat4 m_spearTransform;

	Mesh m_quadMesh;
	glm::mat4 m_quadTransform;
};

