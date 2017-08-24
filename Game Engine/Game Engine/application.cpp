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
}

int Application::run()
{
	////C:\\Users\\foricles\\Desktop\\Cathedral.fbx
	////C:\\Users\\foricles\\Desktop\\man.fbx

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
		kmu::mat4 world(kmu::mat4::Perspective(90, 800, 600, 0.03, 1000));
		world *= kmu::mat4::Translation(0, 0, 50);


		GameObject man1;
		man1.getMesh().loadModel("C:\\Users\\foricles\\Desktop\\man.fbx");
		GameObject man2;
		man2.getMesh().loadModel("C:\\Users\\foricles\\Desktop\\man.fbx");
		GameObject man3;
		man3.getMesh().loadModel("C:\\Users\\foricles\\Desktop\\man.fbx");
		GameObject man4;
		man4.getMesh().loadModel("C:\\Users\\foricles\\Desktop\\man.fbx");
		float a(0);
		prog->bind();
		
		double t;

		while (!oWindow->closed() && (oWasError == 0))
		{
			oWindow->clear();

			a += 0.002;
			//cube.transform().rotation(kmu::quaternion::euler(MY_PI/12, a, a, a));
			man1.transform().position(-60, 0, 0);
			man2.transform().position( 60, 0, 0);
			man3.transform().position(  0, 60, 0);
			man4.transform().position(  0,-60, 0);

			man1.transform().rotation(kmu::quaternion::euler(+a, VEC3_FRONT));
			man2.transform().rotation(kmu::quaternion::euler(-a, VEC3_FRONT));
			man3.transform().rotation(kmu::quaternion::euler(+a, VEC3_FRONT));
			man4.transform().rotation(kmu::quaternion::euler(-a, VEC3_FRONT));

			glUniformMatrix4fv(prog->getUniform("worldMatrix"), 1, GL_TRUE, &world.at(0,0));
			glUniform1f(prog->getUniform("time"), a);

			glUniformMatrix4fv(prog->getUniform("selfMatrix"), 1, GL_TRUE, &man1.transMatrix().at(0, 0));
			man1.getMesh().draw();

			glUniformMatrix4fv(prog->getUniform("selfMatrix"), 1, GL_TRUE, &man2.transMatrix().at(0, 0));
			man2.getMesh().draw();

			glUniformMatrix4fv(prog->getUniform("selfMatrix"), 1, GL_TRUE, &man3.transMatrix().at(0, 0));
			man3.getMesh().draw();

			glUniformMatrix4fv(prog->getUniform("selfMatrix"), 1, GL_TRUE, &man4.transMatrix().at(0, 0));
			man4.getMesh().draw();

			/* Swap front and back buffers */
			oWindow->update();
		}
	}
}
