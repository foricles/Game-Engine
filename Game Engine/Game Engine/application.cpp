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

	oWindow = new Window();
	if (!oWindow->create())
	{
		Logger::Log("Window can`t be created!", LogType::ERR);
		Logger::Pause();
		glfwTerminate();
		oWasError = 2;
	}

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
}

int Application::run()
{
	////C:\\Users\\foricles\\Desktop\\Cathedral.fbx
	//church = new GameObject();
	//church->setData(*utils::file::loadModel("C:\\Users\\foricles\\Desktop\\Cathedral.fbx")[1]);

	prog = new GLProgram();
	prog->begin();
	prog->addShader(SHADER::VERTEX, "D:\\Work\\projects\\cpp\\Game-Engine\\Game Engine\\shader\\vrt.vrt");
	prog->addShader(SHADER::FRAGMENT, "D:\\Work\\projects\\cpp\\Game-Engine\\Game Engine\\shader\\frg.frg");
	prog->end();


	mainLoop();

	return oWasError;
}


void Application::mainLoop()
{
	if (oWasError == 0)
	{
		kmu::mat4 world(kmu::mat4::Perspective(65, 800, 600, 0.03, 1000));
		world *= kmu::mat4::Translation(0, 0, 1);


		GameObject cube;
		cube.loadModel("D:\\Work\\projects\\cpp\\Game-Engine\\Game Engine\\shader\\cube.fbx");
		float a(0);
		prog->bind();
		
		double t;

		while (!oWindow->closed() && (oWasError == 0))
		{
			oWindow->clear();

			a += 0.002;
			//cube.transform().rotation(kmu::quaternion::euler(MY_PI/12, a, a, a));
			cube.transform().position(cos(a)*2, sin(a)*2, 0);

			cube.transform().rotation( kmu::quaternion::euler(a, VEC3_FRONT));

			glUniformMatrix4fv(prog->getUniform("worldMatrix"), 1, GL_TRUE, &world.at(0,0));
			glUniformMatrix4fv(prog->getUniform("selfMatrix"), 1, GL_TRUE, &cube.transMatrix().at(0, 0));
			glUniform1f(prog->getUniform("time"), a);
			cube.draw();

			/* Swap front and back buffers */
			oWindow->update();
		}
	}
}
