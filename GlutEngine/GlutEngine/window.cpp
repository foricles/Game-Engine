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
	return oWHeandler;
}
