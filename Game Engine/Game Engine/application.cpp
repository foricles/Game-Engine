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

	//prog = new GLProgram();
	//prog->begin();
	//prog->addShader(SHADER::VERTEX, "shader\\vrt.vrt");
	//prog->addShader(SHADER::FRAGMENT, "shader\\frg.frg");
	//prog->end();


	mainLoop();

	return oWasError;
}

//#define VECT
#define FLT

void Application::mainLoop()
{
	if (oWasError == 0)
	{
#ifdef VECT
		std::vector<vertex> data = {
			vertex(kmu::vec3(-0.9f, -0.9f, 0.0f), kmu::vec3(), kmu::vec4()),
			vertex(kmu::vec3( 0.9f, -0.9f, 0.0f), kmu::vec3(), kmu::vec4()),
			vertex(kmu::vec3( 0.9f,  0.9f, 0.0f), kmu::vec3(), kmu::vec4()),
			vertex(kmu::vec3(-0.9f,  0.9f, 0.0f), kmu::vec3(), kmu::vec4())
		};
		std::cout << sizeof(vertex) << std::endl;
#endif // VECT
#ifdef FLT
		std::vector<float> data = {
			-0.9f, -0.9f, 0.0f,
			0.9f, -0.9f, 0.0f ,
			0.9f,  0.9f, 0.0f ,
			-0.9f,  0.9f, 0.0f
		};	
		std::cout << sizeof(float) << std::endl;
#endif // FLT
		std::cout << sizeof(kmu::vec2) << " " << sizeof(kmu::vec3) << " " << sizeof(kmu::vec4) << std::endl;
		GLuint vbo;
		glGenBuffers(1, &vbo);
		glBindBuffer(GL_ARRAY_BUFFER, vbo);
		glBufferData(GL_ARRAY_BUFFER, sizeof(vertex)*data.size(), &data[0], GL_STATIC_DRAW);

		std::vector<size_t> indices;
		indices.push_back(0);
		indices.push_back(1);
		indices.push_back(2);
		indices.push_back(0);
		indices.push_back(2);
		indices.push_back(3);
		GLuint ibo;
		glGenBuffers(1, &ibo);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(size_t), &indices[0], GL_STATIC_DRAW);

		glEnableVertexAttribArray(0);
#ifdef VECT
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(vertex), (void*)offsetof(vertex, point));
#endif // VECT
#ifdef FLT
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, nullptr);
#endif // FLT
		glDisableVertexAttribArray(0);

		glBindBuffer(GL_ARRAY_BUFFER, 0);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
		/* Loop until the user closes the window */
		while (!oWindow->closed() && (oWasError == 0))
		{
			/* Render here */
			glClear(GL_COLOR_BUFFER_BIT);

			glBindBuffer(GL_ARRAY_BUFFER, vbo);
			glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);
			glEnableVertexAttribArray(0);

			glDrawElements(GL_TRIANGLES, indices.size(), GL_UNSIGNED_INT, nullptr);

			glDisableVertexAttribArray(0);
			glBindBuffer(GL_ARRAY_BUFFER, 0);
			glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

			/* Swap front and back buffers */
			oWindow->update();
		}
	}
}
