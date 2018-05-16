#include "Application.h"

Application::Application()
{
}


Application::~Application()
{
}

int Application::Initialize(const glm::ivec2 & resolution, const char * window)
{
	planet = new Planet();

	m_startTime = m_clock.now();
	m_currentTime = m_clock.now();
	m_previousTime = m_clock.now();

	// If we can hook into GPU
	if (glfwInit() == false)
	{
		// -1 is a failure code
		return -1;
	}

	GLFWmonitor** screens;
	int count = 0;
	screens = glfwGetMonitors(&count);
	std::cout << count << std::endl;

	// Make window with openGL render
	m_window = glfwCreateWindow(resolution.x, resolution.y, window, nullptr, nullptr);

	// Check if window worked
	if (m_window == nullptr)
	{
		glfwTerminate();
		return -2;
	}

	// Bring to front
	glfwMakeContextCurrent(m_window);

	// ..before loading interface functions
	if (ogl_LoadFunctions() == ogl_LOAD_FAILED)
	{
		glfwDestroyWindow(m_window);
		glfwTerminate();
		return -3;
	}

	// Open GL version
	auto major = ogl_GetMajorVersion();
	auto minor = ogl_GetMinorVersion();
	printf("GL: %i.%i\n", major, minor);

	glClearColor(0.25f, 0.25f, 0.25f, 0.25f);
	// Enable Depth
	glEnable(GL_DEPTH_TEST);

	aie::Gizmos::create(10000, 10000, 10000, 10000);

	view = glm::lookAt(glm::vec3(20), glm::vec3(0), glm::vec3(0, 1, 0));
	projection = glm::perspective(glm::pi<float>() * 0.25f, 16 / 9.0f, 0.1f, 1000.0f);

	return 0;
}

void Application::Run()
{
	while (glfwWindowShouldClose(m_window) == false && glfwGetKey(m_window, GLFW_KEY_ESCAPE) != GLFW_PRESS)
	{
		m_previousTime = m_currentTime;
		m_currentTime = m_clock.now();
		auto duration = m_currentTime - m_previousTime;
		float deltaTime = duration.count() * NANO_TO_SECONDS;
		std::cout << duration.count() << " " << deltaTime << std::endl;

		aie::Gizmos::addTransform(glm::mat4(1));
		glm::vec4 white(1);
		glm::vec4 black(0, 0, 0, 1);

		// Clearing buffer - colour and depth check
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		for (int i = 0; i < 21; ++i)
		{
			aie::Gizmos::addLine(glm::vec3(-10 + i, 0, 10), glm::vec3(-10 + i, 0, -10), i == 10 ? white : black);
			aie::Gizmos::addLine(glm::vec3(10, 0, -10 + i), glm::vec3(-10, 0, -10 + i), i == 10 ? white : black);
		}
		planet->update(deltaTime);
		Render();

		glfwPollEvents();
	}
}

void Application::Render()
{
	planet->draw();
	aie::Gizmos::draw(projection * view);
	aie::Gizmos::clear();
	glfwSwapBuffers(m_window);
}

void Application::Terminate()
{
	aie::Gizmos::destroy();
	// Clean up window and GPU linkage
	glfwDestroyWindow(m_window);
	glfwTerminate();
}
