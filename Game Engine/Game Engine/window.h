#ifndef _WINDOW_H_
#define _WINDOW_H_

#include "opengl.h"
#include "Logger.h"

class Window
{
	friend class Application;
public:
	Window(size_t W = 1366, size_t H = 768);
	virtual ~Window();

	bool create();
	bool closed();
	void update();
	void clear();
	void close();

	GLFWwindow* getWindowHeandler();

private:
	GLFWwindow* oWHeandler;
	GLFWmonitor* oMonitor;
	size_t oWeight;
	size_t oHeight;
private:
	void windowSizeCallback(int width, int height);
};

#endif // !_WINDOW_H_