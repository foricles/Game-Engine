#include "window.h"

Window::Window(size_t W, size_t H)
	: oWeight(W)
	, oHeight(H)
	, oWHeandler(nullptr)
	, oMonitor(nullptr)
{
}


Window::~Window()
{
}

bool Window::create()
{
#ifdef _DEBUG
	oWHeandler = glfwCreateWindow(oWeight, oHeight, "Hello World", NULL, NULL);
#else
	oWHeandler = glfwCreateWindow(oWeight, oHeight, "Hello World", glfwGetPrimaryMonitor(), NULL);
#endif // DEBUG
	glfwMakeContextCurrent(oWHeandler);
	oMonitor = glfwGetWindowMonitor(oWHeandler);

	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);
	glCullFace(GL_FRONT);
	glFrontFace(GL_CCW);

	return oWHeandler;
}

bool Window::closed()
{
	return glfwWindowShouldClose(oWHeandler);
}

void Window::update()
{
	glfwPollEvents();
	glfwSwapBuffers(oWHeandler);
}

void Window::windowSizeCallback(int width, int height)
{
}

void Window::close()
{
	glfwSetWindowShouldClose(oWHeandler, 1);
}

void Window::clear()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

GLFWwindow * Window::getWindowHeandler()
{
	return oWHeandler;
}
