#ifndef _WINDOW_H_
#define _WINDOW_H_

#include "opengl.h"

class Window
{
public:
	Window(size_t W = 400, size_t H = 300);
	~Window();

	bool create();
	bool closed() const { return glfwWindowShouldClose(oWHeandler); }
	void update() const
	{ 
		glfwPollEvents();
		glfwSwapBuffers(oWHeandler); 
	}
private:
	GLFWwindow* oWHeandler;
	size_t oWeight;
	size_t oHeight;
};

#endif // !_WINDOW_H_