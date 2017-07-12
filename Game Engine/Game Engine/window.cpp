#include "window.h"



Window::Window(size_t W, size_t H)
	: oWeight(W)
	, oHeight(H)
{
}


Window::~Window()
{
}

bool Window::create()
{
	oWHeandler = glfwCreateWindow(oWeight, oHeight, "Hello World", NULL, NULL);
	glfwMakeContextCurrent(oWHeandler);

	glEnable(GL_DEPTH_TEST); glEnable(GL_CULL_FACE);
	glCullFace(GL_FRONT);
	glFrontFace(GL_CCW);
	return oWHeandler;
}
