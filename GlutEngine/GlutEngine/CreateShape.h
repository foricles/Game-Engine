#ifndef _CREATESHAPE_H
#define _CREATESHAPE_H

#include "..\GlutEngine\math_help_funk.h"
#include "..\GlutEngine\RenderShape.h"

class CreateShape
{
public:
	static RenderShape * Quad();
	static RenderShape * Triangle();
	static RenderShape * Circle();
	static RenderShape * Circle(int seg);
	static RenderShape * Arrow();
};


#endif // !_CREATESHAPE_H
