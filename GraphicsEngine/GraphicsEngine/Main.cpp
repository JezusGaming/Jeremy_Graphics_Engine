#include "Application.h"

int main()
{
	Application* app = new Application;
	
	app->Initialize();
	app->Run();
	app->Render();
	app->Terminate();

	return 0;
}