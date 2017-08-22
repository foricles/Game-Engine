#ifndef _APPLICATION_H_
#define _APPLICATION_H_

#include "opengl.h"
#include "utils.h"
#include "gameobject.h"
#include "glprogram.h"

#include "Logger.h"
#include "window.h"
#include <time.h>

class Application
{
private:
	GLProgram *prog;

	int oArgc;
	char **oArgv;
public:
	Application(int argc, char **argv);
	~Application();

	int run();
private:
	Window *oWindow;
	int oWasError;

	void mainLoop();
};

#endif // !_APPLICATION_H_