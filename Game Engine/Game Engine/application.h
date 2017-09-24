#ifndef _APPLICATION_H_
#define _APPLICATION_H_

#include "opengl.h"
#include "objectmanager.hpp"
#include "utils.h"
#include "gameobject.h"
#include "glprogram.h"

#include "Logger.h"
#include "window.h"
#include "render.hpp"
#include <time.h>

class Application
{
private:
	int oArgc;
	char **oArgv;
public:
	Application(int argc, char **argv);
	~Application();

	int run();
private:
	Window *oWindow;
	//-------------into-one-scene------------------------------------
	Render *oRender;
	ObjectManager *oObjectManager;
	//--------------------------------------

	int oWasError;

	void mainLoop();
private:
	static void windowSizeCallback(GLFWwindow* window, int width, int height);
	static void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);
	static void characterCallback(GLFWwindow* window, unsigned int codepoint);
	static void cursorPositionCallback(GLFWwindow* window, double xpos, double ypos);
};

#endif // !_APPLICATION_H_