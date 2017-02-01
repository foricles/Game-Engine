#ifndef _RENDERSHAPE_H
#define _RENDERSHAPE_H

#include "../GlutEngine/Transform.h"
#include "../GlutEngine/VertexArray.h"
#include "../GlutEngine/Renderable.h"
#include "../GlutEngine/Tags.h"
#include "../GlutEngine/Color.h"

class RenderShape :  public Renderable
{
	friend class Render;
	friend class CreateShape;
public:
	Transform transform;

	RenderShape();
	RenderShape(int size);
	~RenderShape();

	void setColor(const Color &color);
	void AddPoint(float x, float y)
	{
		m_VArray.AddVertex(x, y);
	}
	void AddPoint(const vec2 &point)
	{
		m_VArray.AddVertex(point);
	}
private:
	VertexArray m_VArray;
};


#endif // !_RENDERSHAPE_H

