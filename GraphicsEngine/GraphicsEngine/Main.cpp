#include "Application.h"

int main()
{
	//-----------------------------------------------------------------------------------------------
	// pointer to application.
	//-----------------------------------------------------------------------------------------------
	Application* app = new Application;
	//-----------------------------------------------------------------------------------------------
	// Initializes variables to run the application window and other things.
	//-----------------------------------------------------------------------------------------------
	app->Initialize();
	//-----------------------------------------------------------------------------------------------
	// Runs the applicaton.
	//-----------------------------------------------------------------------------------------------
	app->Run();
	//-----------------------------------------------------------------------------------------------
	// draws everything to the screen.
	//-----------------------------------------------------------------------------------------------
	app->Render();
	//-----------------------------------------------------------------------------------------------
	// shutsdown the applicatoin.
	//-----------------------------------------------------------------------------------------------
	app->Terminate();

	return 0;
}