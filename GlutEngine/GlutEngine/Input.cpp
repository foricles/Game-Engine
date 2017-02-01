#include "Input.h"

#include <iostream>

bool *Input::m_Arr = nullptr;

int Input::m_mcX      = NULLBUTTON;
int Input::m_mcY      = NULLBUTTON;
int Input::m_mcButton = NULLBUTTON;
bool Input::EnyButtonPressed = false;
unsigned char Input::prevKey = '\0';

Input::Input() : System("Input", EngSys::INPUTS)
{
	m_Arr = new bool[128]{ false };

	glutKeyboardFunc(OnKeyDown);
	glutKeyboardUpFunc(OnKeyUp);

	glutMouseFunc(OnMouseClick);
}

Input::~Input()
{
	delete[] m_Arr;
}

#include <iostream>
void Input::OnKeyDown(unsigned char key, int x, int y)
{
	prevKey = key;
	Input::m_Arr[tolower(key)] = true;
	EnyButtonPressed = true;
}

void Input::OnKeyUp(unsigned char key, int x, int y)
{
	prevKey = '\0';
	Input::m_Arr[tolower(key)] = false;
	EnyButtonPressed = false;
}

void Input::OnMouseClick(int button, int state, int x, int y)
{
	if (state == GLUT_DOWN)
	{
		Input::m_mcX      = x;
		Input::m_mcY      = Settings::Window_Height-y;
		Input::m_mcButton = button;
		return;
	}

	if (state == GLUT_UP)
	{
		Input::m_mcX      = NULLBUTTON;
		Input::m_mcY      = NULLBUTTON;
		Input::m_mcButton = NULLBUTTON;
		return;
	}
}

bool Input::KeyPressed(unsigned char key)
{
	return (Input::m_Arr[key]);
}

bool Input::MouseButton(int button)
{
	bool notLeft   = (button != GLUT_LEFT_BUTTON);
	bool notMiddle = (button != GLUT_MIDDLE_BUTTON);
	bool notRight  = (button != GLUT_RIGHT_BUTTON);

	if (notLeft && notMiddle && notRight)return false; 

	return (button == m_mcButton);
}

int Input::MouseX()
{
	return m_mcX;
}

int Input::MouseY()
{
	return m_mcY;
}
