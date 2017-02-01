#ifndef _WINDOW_H
#define _WINDOW_H

#include <string>

#include <GL\glut.h>
#include "../GlutEngine/System.h"
#include "../GlutEngine/Settings.h"

class Window : protected System
{
	friend class Engine;
private:
	int m_WindowDeskriptor;

	int *m_Argc;
	char **m_Argv;

public:
	Window(int *argc, char **argv);
	~Window();

	int getWidght() { return Settings::Window_Widght; };
	int getHeight() { return Settings::Window_Height; };
	int getPositionX() { return Settings::Window_Position_X; };
	int getPositionY() { return Settings::Window_Position_Y; };
	int getDeskriptor() { return m_WindowDeskriptor; };
};

#endif //_WINDOW_H
