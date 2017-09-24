#ifndef _APPLICATION_H_
#define _APPLICATION_H_

#include "opengl.h"
#include "utils.h"
#include "gameobject.h"
#include "glprogram.h"

#include "Logger.h"
#include "window.h"
#include "mygame.hpp"
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
	InputManager oInputManager;
	static InputManager *input;

	Scene *oScene;

	int oWasError;

	void mainLoop();
private:
	static void windowSizeCallback(GLFWwindow* window, int width, int height);
	static void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);
	static void charmodsCallback(GLFWwindow* window, unsigned int codepoint, int mods);
	static void cursorPositionCallback(GLFWwindow* window, double xpos, double ypos);
	static void mouseButtonCallback(GLFWwindow* window, int button, int action, int mods);
	static void scrollCallback(GLFWwindow* window, double xoffset, double yoffset);
};

#endif // !_APPLICATION_H_