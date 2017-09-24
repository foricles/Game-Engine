#include "application.h"

#define SINGLERENDER  1

Application::Application(int argc, char ** argv)
	: oArgc(argc)
	, oArgv(argv)
	, oWasError(0)
	, oWindow(nullptr)
	, oRender(nullptr)
	, oObjectManager(nullptr)
{
	if (!glfwInit())
	{
		Logger::Log("GLWF can`t be inicialized!", LogType::ERR);
		Logger::Pause();
		oWasError = 1;
	}

	oWindow = new Window();
	oObjectManager = new ObjectManager();

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

	oRender = new Render(oObjectManager);
}

Application::~Application()
{
	glfwTerminate();
	delete oRender;
	delete oWindow;
	delete oObjectManager;
}

int Application::run()
{
	////C:\\Users\\foricles\\Desktop\\Cathedral.fbx
	////C:\\Users\\foricles\\Desktop\\man.fbx
	if (oWasError == 0)
	{
		auto heandler = oWindow->getWindowHeandler();
		glfwSetWindowSizeCallback(heandler, windowSizeCallback);
		mainLoop();
	}

	return oWasError;
}


void Application::mainLoop()
{
	if (oWasError == 0)
	{
		GameObject* cube1 = oObjectManager->getObject();
		cube1->getMesh().loadModel("D:\\Work\\projects\\cpp\\Game-Engine\\Game Engine\\shader\\cube.fbx");

		GameObject* cube2 = oObjectManager->getObject();
		cube2->getMesh().loadModel("D:\\Work\\projects\\cpp\\Game-Engine\\Game Engine\\shader\\cube.fbx");

		GameObject* cube3 = oObjectManager->getObject();
		cube3->getMesh().loadModel("D:\\Work\\projects\\cpp\\Game-Engine\\Game Engine\\shader\\cube.fbx");

		cube2->transform().setPosition(-3, 0, 0);
		cube2->transform().setParent(&cube1->transform());

		cube3->transform().setPosition(-5, 0, 0);
		cube3->transform().setParent(&cube2->transform());

		float a(0);

		double t;

		while (!oWindow->closed() && (oWasError == 0))
		{
			oWindow->clear();

			a += 0.01;
			cube1->transform().setRotation(kmu::quaternion::euler(+a, VEC3_FRONT));
			cube2->transform().setRotation(kmu::quaternion::euler(-a*2, VEC3_FRONT));

			oRender->draw();
			/* Swap front and back buffers */
			oWindow->update();
		}
	}
}

void Application::windowSizeCallback(GLFWwindow * window, int width, int height)
{
	glfwSetWindowSize(window, width, height);
	Logger::Log(std::to_string(width) + " " + std::to_string(height));
}

void Application::keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods)
{}

void Application::characterCallback(GLFWwindow* window, unsigned int codepoint)
{}

void Application::cursorPositionCallback(GLFWwindow* window, double xpos, double ypos)
{}