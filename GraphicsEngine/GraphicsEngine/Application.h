#pragma once
#include "ApplicationCore.h"
#include "Planet.h"
#include "FlyCamera.h"
#include "Mesh.h"
#include "Shader.h"
#include "OBJMesh.h"
#include "RenderTarget.h"

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
	aie::ShaderProgram m_phongShader;
	aie::ShaderProgram m_texturedShader;

	aie::OBJMesh m_bunnyMesh;
	glm::mat4 m_bunnyTransform;

	aie::OBJMesh m_catMesh;
	glm::mat4 m_catTransform;

	aie::OBJMesh m_spearMesh;
	glm::mat4 m_spearTransform;

	aie::OBJMesh m_cargoMesh;
	glm::mat4 m_cargoTransform;

	aie::OBJMesh m_grassMesh01;
	glm::mat4 m_grassTransform01;

	aie::OBJMesh m_grassMesh02;
	glm::mat4 m_grassTransform02;

	Mesh m_quadMesh;
	glm::mat4 m_quadTransform;

	//aie::RenderTarget m_renderTarget;

	struct Light {
		glm::vec3 direction;
		glm::vec3 diffuse;
		glm::vec3 specular;
	};
	Light m_light;
	glm::vec3 m_ambientLight;

};

