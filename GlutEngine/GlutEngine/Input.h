#ifndef _INPUT_H
#define _INPUT_H

#include <GL\glut.h>
#include "../GlutEngine/System.h"
#include "../GlutEngine/Settings.h"

#define NULLBUTTON -1

class Input : System
{
	friend class Engine;
private:
	static bool *m_Arr;
	
	static unsigned char prevKey;
	static bool EnyButtonPressed;

	static int m_mcX;
	static int m_mcY;
	static int m_mcButton;

	static void OnKeyDown(unsigned char key, int x, int y);
	static void OnKeyUp(unsigned char key, int x, int y);

	static void OnMouseClick(int button, int state, int x, int y);


public:
	Input();
	~Input();

	static bool KeyPressed(unsigned char key);
	static bool MouseButton(int button);
	static int MouseX();
	static int MouseY();
	static char getKey() { return prevKey; }
	static bool EnyButton() { return EnyButtonPressed; }
};


#endif // !_INPUT_H

