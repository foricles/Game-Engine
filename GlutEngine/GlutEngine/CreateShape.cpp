#include "CreateShape.h"

RenderShape * CreateShape::Quad()
{
	RenderShape *shape = new RenderShape(4);

	shape->m_VArray.AddVertex(0, 0);
	shape->m_VArray.AddVertex(1, 0);
	shape->m_VArray.AddVertex(1, 1);
	shape->m_VArray.AddVertex(0, 1);

	return shape;
}

RenderShape * CreateShape::Triangle()
{
	RenderShape *shape = new RenderShape(3);

	shape->m_VArray.AddVertex(0, 0);
	shape->m_VArray.AddVertex(1, 0);
	shape->m_VArray.AddVertex(0.5, 1);

	return shape;
}

RenderShape * CreateShape::Circle()
{
	return Circle(36);
}

RenderShape * CreateShape::Circle(int seg)
{
	RenderShape *shape = new RenderShape(seg);

	if (seg <= 0)seg = 2;
	if (seg >= 360)seg = 360;
	double interval = 360 / seg;

	for (double i(0); i < 360; i+=interval)
	{
		double rad = (double)MathHelp::DegToRad(i);
		shape->m_VArray.AddVertex(cos(rad), sin(rad));
	}
	return shape;
}

RenderShape * CreateShape::Arrow()
{
	RenderShape *shape = new RenderShape(7);
	shape->m_VArray.AddVertex(0.25, 0.0);
	shape->m_VArray.AddVertex(0.75, 0.0);
	shape->m_VArray.AddVertex(0.75, 0.5);
	shape->m_VArray.AddVertex(1.00, 0.5);
	shape->m_VArray.AddVertex(0.50, 1.0);
	shape->m_VArray.AddVertex(0.00, 0.5);
	shape->m_VArray.AddVertex(0.25, 0.5);
	return shape;
}
