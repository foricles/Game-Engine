#include "Logger.h"
#include "opengl.h"

void Logger::CheckGLErrors(std::string pref)
{
	GLenum error;
	std::string mess;
	if ((error = glGetError()) != GL_NO_ERROR)
	{
		switch (error)
		{
		case GL_INVALID_ENUM: mess = "GL_INVALID_ENUM"; break;
		case GL_INVALID_OPERATION: mess = "GL_INVALID_OPERATION"; break;
		case GL_INVALID_VALUE: mess = "GL_INVALID_VALUE"; break;
		case GL_OUT_OF_MEMORY: mess = "GL_OUT_OF_MEMORY"; break;
		case GL_INVALID_FRAMEBUFFER_OPERATION: mess = "GL_INVALID_FRAMEBUFFER_OPERATION"; break;
		default: mess = "undef";  break;
		}
		Logger::Log("Was Error at " + pref + " :" + mess + ": " + conv<GLenum>(error), LogType::ERR);
	}
}

void Logger::Log(const std::string & message, LogType logType)
{
	/*ѕолучение дескриптора*/
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		
	SetConsoleTextAttribute(hConsole, (WORD)((ConsoleColor::Black << 4) | ConsoleColor::White));

	switch (logType)
	{
	case LogType::MESS:
		std::cout << message << std::endl;
			break;
	case LogType::INF:
		/*÷вет символов - зеленый. ÷вет фона - черный*/
		SetConsoleTextAttribute(hConsole, (WORD)((ConsoleColor::Black << 4) | ConsoleColor::LightGreen));
		std::cout << message << std::endl;
		break;
	case LogType::ATTMP:
		/*÷вет символов - желтый. ÷вет фона - черный*/
		SetConsoleTextAttribute(hConsole, (WORD)((ConsoleColor::Black << 4) | ConsoleColor::Yellow));
		std::cout << message << std::endl;
		break;
	case LogType::ERR:
		/*÷вет символов - красный. ÷вет фона - черный*/
		SetConsoleTextAttribute(hConsole, (WORD)((ConsoleColor::Black << 4) | ConsoleColor::LightRed));
		std::cout << message << std::endl;
		break;
	}

	SetConsoleTextAttribute(hConsole, (WORD)((ConsoleColor::Black << 4) | ConsoleColor::White));

}

void Logger::Pause()
{
	_getch();
}

void Logger::FatalError(const std::string & message)
{
	Logger::Log(message, LogType::ERR);
	system("pause");
	exit(69);
}
