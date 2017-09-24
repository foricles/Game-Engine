#include "application.h"

InputManager *Application::input = nullptr;

Application::Application(int argc, char ** argv)
	: oArgc(argc)
	, oArgv(argv)
	, oWasError(0)
	, oWindow(nullptr)
	, oScene(nullptr)
{
	if (!glfwInit())
	{
		Logger::Log("GLWF can`t be inicialized!", LogType::ERR);
		Logger::Pause();
		oWasError = 1;
	}

	oWindow = new Window();

	if (!oWindow->create())
	{
		Logger::Log("Window can`t be created!", LogType::ERR);
		Logger::Pause();
		glfwTerminate();
		oWasError = 2;
	}

	//glewExperimental = true;
	auto err = glewInit();
	if (err != GLEW_OK)
	{
		Logger::Log("GLEW can`t be inicialized: " + std::string((char*)(glewGetErrorString(err))) + "!", LogType::ERR);
		Logger::Pause();
		oWasError = 3;
	}
	Logger::Log("OpenGL " + std::string((char*)glGetString(GL_VERSION)), LogType::INF);

}

Application::~Application()
{
	glfwTerminate();
	delete oScene;
	delete oWindow;
}

int Application::run()
{
	if (oWasError == 0)
	{
		input = &oInputManager;
		GLFWwindow *heandler = oWindow->getWindowHeandler();

		glfwSetWindowSizeCallback(heandler, windowSizeCallback);
		glfwSetKeyCallback(heandler, keyCallback);
		glfwSetCharModsCallback(heandler, charmodsCallback);
		glfwSetCursorPosCallback(heandler, cursorPositionCallback);
		glfwSetMouseButtonCallback(heandler, mouseButtonCallback);
		glfwSetScrollCallback(heandler, scrollCallback);

		oScene = new Fly();
		oScene->setInput(input);
		mainLoop();
	}

	return oWasError;
}


void Application::mainLoop()
{
	if (oWasError == 0)
	{
		oScene->Start();
		while (!oWindow->closed() && (oWasError == 0))
		{
			oScene->Update();

			oWindow->clear();
			oScene->drawScene();
			oWindow->update();

			oScene->LateUpdate();
		}
		oScene->Finish();
	}
}

void Application::windowSizeCallback(GLFWwindow * window, int width, int height)
{
	glfwSetWindowSize(window, width, height);
	Logger::Log(conv(width) + " " + conv(height));
}

void Application::keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	input->keyCallback(key, scancode, action, mods);
}

void Application::charmodsCallback(GLFWwindow* window, unsigned int codepoint, int mods)
{
	input->characterCallback(codepoint, mods);
}

void Application::cursorPositionCallback(GLFWwindow* window, double xpos, double ypos)
{
	input->cursorPositionCallback(xpos, ypos);
}

void Application::mouseButtonCallback(GLFWwindow* window, int button, int action, int mods)
{
	input->mouseButtonCallback(button, action, mods);
}

void Application::scrollCallback(GLFWwindow* window, double xoffset, double yoffset)
{
	input->scrollCallback(xoffset, yoffset);
}