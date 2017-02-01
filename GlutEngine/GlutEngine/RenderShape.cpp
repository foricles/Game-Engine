#include "RenderShape.h"

RenderShape::RenderShape()
	: Renderable(Tags::SOLIDOBJ, 1)
	, m_VArray(0)
	, transform(0.0, 0.0, 0.0, 1.0, 1.0)
{
}
RenderShape::RenderShape(int size)
	: Renderable(Tags::SOLIDOBJ, 1)
	, m_VArray(size)
	, transform(0.0, 0.0, 0.0, 1.0, 1.0)
{
}

RenderShape::~RenderShape()
{
}


void RenderShape::setColor(const Color & color)
{
	for (int i(0); i < m_VArray.getSize(); i++)
		m_VArray.SetVertexColor(i, color);
		
}
