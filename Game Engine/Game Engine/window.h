#ifndef _WINDOW_H_
#define _WINDOW_H_

#include "opengl.h"
#include "Logger.h"

class Window
{
public:
	Window(size_t W = 640, size_t H = 480);
	virtual ~Window();

	bool create();
	bool closed();
	void update();
	void clear();

	GLFWwindow* getWindowHeandler();

private:
	GLFWwindow* oWHeandler;
	GLFWmonitor* oMonitor;
	size_t oWeight;
	size_t oHeight;
};

#endif // !_WINDOW_H_