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

	MyCamera = new FlyCamera();

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

	glfwSetCursorPos(m_window, 640, 360);
	
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

	MyCamera->setLookAt(glm::vec3(20), glm::vec3(0), glm::vec3(0, 1, 0));
	MyCamera->setPerspective(0.25f, 16 / 9.0f, 0.1f, 1000.0f);

	m_light.diffuse = { 1, 1, 0 };
	m_light.specular = { 1, 1, 0 };
	m_ambientLight = { 0.25f, 0.25f, 0.25f };
	
	/*if (m_renderTarget.initialise(1, resolution.x, resolution.y) == false) {
		printf("Render Target Error!\n");
		return false;
	}*/

	m_phongShader.loadShader(aie::eShaderStage::VERTEX,
		"../shaders/phong.vert.txt");
	m_phongShader.loadShader(aie::eShaderStage::FRAGMENT,
		"../shaders/phong.frag.txt");

	if (m_phongShader.link() == false) {
		printf("Shader Error: %s\n", m_phongShader.getLastError());
		return false;
	}

	m_shader.loadShader(aie::eShaderStage::VERTEX,
		"../shaders/normalmap.vert.txt");
	m_shader.loadShader(aie::eShaderStage::FRAGMENT,
		"../shaders/normalmap.frag.txt");

	if (m_shader.link() == false) {
		printf("Shader Error: %s\n", m_shader.getLastError());
		return false;
	}

	m_texturedShader.loadShader(aie::eShaderStage::VERTEX,
		"../shaders/textured.vert.txt");
	m_texturedShader.loadShader(aie::eShaderStage::FRAGMENT,
		"../shaders/textured.frag.txt");

	if (m_texturedShader.link() == false) {
		printf("Shader Error: %s\n", m_texturedShader.getLastError());
		return false;
	}

	if (m_spearMesh.load("../soulspear/soulspear.obj",
		true, true) == false) {
		printf("Soulspear Mesh Error!\n");
		return false;
	}
	m_spearTransform = {
		1,0,0,0,
		0,1,0,0,
		0,0,1,0,
		0,0,0,1
	};

	if (m_gridTexture.load("../textures/numbered_grid.tga") == false) {
		printf("Failed to load texture!\n");
		return false;
	}
	// create a simple quad
	m_quadMesh.initialiseQuad();
	// define a scale matrix for the quad
	m_quadTransform = {
		10,0,0,0,
		0,10,0,0,
		0,0,10,0,
		0,0,0,1
	};

	if (m_bunnyMesh.load("../stanford/bunny.obj") == false) {
		printf("Bunny Mesh Error!\n");
		return false;
	}
	m_bunnyTransform = {
		0.5f,0,0,0,
		0,0.5f,0,0,
		0,0,0.5f,0,
		5,0,0,1
	};

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
		
		// query time since application started
		float time = glfwGetTime();
		// rotate light
		m_light.direction = glm::normalize(glm::vec3(glm::cos(time * 2),
			glm::sin(time * 2), 0));

		Render();

		MyCamera->update(deltaTime, m_window);
		glfwPollEvents();
	}
}

void Application::Render()
{
	// bind shader
	m_shader.bind();
	
	// bind light
	m_shader.bindUniform("Ia", m_ambientLight);
	m_shader.bindUniform("Id", m_light.diffuse);
	m_shader.bindUniform("Is", m_light.specular);
	m_shader.bindUniform("lightDirection", m_light.direction);
	// bind transform
	auto pvm = MyCamera->getProjection() * MyCamera->getView() * m_spearTransform;
	m_shader.bindUniform("ProjectionViewModel", pvm);
	m_shader.bindUniform("cameraPosition", glm::vec3(glm::inverse(MyCamera->getView())[3]));
	// bind transforms for lighting
	m_shader.bindUniform("NormalMatrix", glm::inverseTranspose(glm::mat3(m_spearTransform)));
	// draw mesh
	m_spearMesh.draw();

	// bind our render target
	//m_renderTarget.bind();

	// draw bunny with a light
	m_phongShader.bind();
	// bind light
	m_phongShader.bindUniform("Ia", m_ambientLight);
	m_phongShader.bindUniform("Id", m_light.diffuse);
	m_phongShader.bindUniform("Is", m_light.specular);
	m_phongShader.bindUniform("LightDirection", m_light.direction);
	m_phongShader.bindUniform("cameraPosition", glm::vec3(glm::inverse(MyCamera->getView())[3]));
	// bind transform
	pvm = MyCamera->getProjection() * MyCamera->getView() * m_bunnyTransform;
	m_phongShader.bindUniform("ProjectionViewModel", pvm);
	// bind transforms for lighting
	m_phongShader.bindUniform("ModelMatrix", m_bunnyTransform);
	m_phongShader.bindUniform("NormalMatrix", glm::inverseTranspose(glm::mat3(m_bunnyTransform)));

	// unbind target to return to backbuffer
	//m_renderTarget.unbind();

	// draw mesh
	m_bunnyMesh.draw();	// bind texturing shader
	m_texturedShader.bind();
	pvm = MyCamera->getProjection() * MyCamera->getView() * m_quadTransform;
	m_texturedShader.bindUniform("ProjectionViewModel", pvm);
	// bind texture location
	m_texturedShader.bindUniform("diffuseTexture", 0);
	//m_renderTarget.getTarget(0).bind(0);
	// bind texture to specified location
	m_gridTexture.bind(0);
	// draw quad
	m_quadMesh.draw();

	planet->draw();

	aie::Gizmos::draw(MyCamera->getProjectionView());
	aie::Gizmos::clear();
	glfwSwapBuffers(m_window);
}

void Application::Terminate()
{
	delete planet;
	delete MyCamera;
	aie::Gizmos::destroy();
	// Clean up window and GPU linkage
	glfwDestroyWindow(m_window);
	glfwTerminate();
}
