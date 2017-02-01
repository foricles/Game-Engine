#include "Window.h"
#include <iostream>
Window::Window(int * argc, char ** argv)
	: System("Window", EngSys::WINDOW)
	, m_Argc(argc)
	, m_Argv(argv)
{
	glutInit(m_Argc, m_Argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_MULTISAMPLE | GLUT_RGBA);

	glutInitWindowSize(
		Settings::Window_Widght,
		Settings::Window_Height);

	glutInitWindowPosition(
		Settings::Window_Position_X,
		Settings::Window_Position_Y);

	

	m_WindowDeskriptor = glutCreateWindow(Settings::Window_Name.c_str());
}

Window::~Window()
{
	
}