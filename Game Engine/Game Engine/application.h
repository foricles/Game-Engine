#ifndef _APPLICATION_H_
#define _APPLICATION_H_

#include "opengl.h"
#include "glprogram.h"
#include "utils.h"
#include "Logger.h"
#include "gameobject.h"
#include "window.h"
#include "mygame.hpp"

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
	double oDeltaTime;

	void mainLoop();
private:
	void cursorUpdate();
	static void windowSizeCallback(GLFWwindow* window, int width, int height);
	static void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);
	static void charmodsCallback(GLFWwindow* window, unsigned int codepoint, int mods);
	static void mouseButtonCallback(GLFWwindow* window, int button, int action, int mods);
	static void scrollCallback(GLFWwindow* window, double xoffset, double yoffset);
};

#endif // !_APPLICATION_H_