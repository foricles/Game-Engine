#ifndef _APPLICATION_H_
#define _APPLICATION_H_

#include "opengl.h"

#include "Logger.h"
#include "window.h"

class Application
{
private:
	int oArgc;
	char **oArgv;
public:
	Application(int argc, char **argv);
	~Application();
private:
	Window *oWindow;
	int oWasError;

	void mainLoop();
};

#endif // !_APPLICATION_H_