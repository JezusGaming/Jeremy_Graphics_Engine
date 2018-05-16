#pragma once
#include "ApplicationCore.h"
#include "Planet.h"

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

	glm::mat4 view;
	glm::mat4 projection;

	Planet* planet;
};

