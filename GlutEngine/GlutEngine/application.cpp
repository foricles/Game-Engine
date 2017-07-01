#include "application.h"

Application::Application(int argc, char ** argv)
	: oArgc(argc)
	, oArgv(argv)
	, oWasError(0)
	, oWindow(nullptr)
{
	if (!glfwInit())
	{
		Logger::Log("GLWF can`t be inicialized!", LogType::ERR);
		Logger::Pause();
		oWasError = 1;
	}

	if (!glewInit())
	{
		Logger::Log("GLEW can`t be inicialized!", LogType::ERR);
		Logger::Pause();
		oWasError = 2;
	}

	oWindow = new Window();
	if (!oWindow->create())
	{
		Logger::Log("Window can`t be created!", LogType::ERR);
		Logger::Pause();
		glfwTerminate();
		oWasError = 3;
	}

	mainLoop();
}

Application::~Application()
{
	glfwTerminate();
}

void Application::mainLoop()
{
	/* Loop until the user closes the window */
	while (!oWindow->closed()  && !oWasError)
	{
		/* Render here */
		glClear(GL_COLOR_BUFFER_BIT);

		/* Swap front and back buffers */
		oWindow->update();

		/* Poll for and process events */
		glfwPollEvents();
	}
}
