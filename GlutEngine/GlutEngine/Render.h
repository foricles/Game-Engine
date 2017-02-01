#ifndef _RENDER_H
#define _RENDER_H

#include <gl\glut.h>
#include <vector>
#include <algorithm>


#include "../GlutEngine/System.h"
#include "../GlutEngine/Settings.h"
#include "../GlutEngine/math_help_funk.h"

#include "../GlutEngine/Renderable.h"
#include "../GlutEngine/RenderShape.h"
#include "../GlutEngine/UI.h"

class Render : protected  System
{
	friend class Engine;
private:
	Render();
	~Render();
	static bool m_Sort;

	static bool comp(Renderable *rend1, Renderable *rend2);
	static std::vector<Renderable*> *buffer;
	static void Flush();
public:

	void SetGrid2D(float left, float right, float bottom, float top);
	static void Add(Renderable *renderable);
};



#endif // !_RENDER_H
