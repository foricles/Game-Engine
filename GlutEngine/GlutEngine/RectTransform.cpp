#include "RectTransform.h"

RectTransform::RectTransform(int x, int y, int w, int h)
	: m_PointA( vec2(x,y) )
	, m_PointB( vec2(x+w, y+h) )
{
}
RectTransform::RectTransform(const vec2 &pos, int w, int h)
	: m_PointA(pos)
	, m_PointB(vec2(pos.x + w, pos.y + h))
{}
RectTransform::RectTransform(const RectTransform &rectTransform)
	: m_PointA(rectTransform.m_PointA)
	, m_PointB(rectTransform.m_PointB)
{}

RectTransform::~RectTransform()
{}

vec2 & RectTransform::getPosition()
{
	return m_PointA;
}

int RectTransform::getWidth()
{
	return (int)m_PointB.x;
}

int RectTransform::getHeight()
{
	return (int)m_PointB.y;
}

bool RectTransform::Contain(const vec2 & point)
{
	return Contain( (int)point.x, (int)point.y);
}

bool RectTransform::Contain(int x, int y)
{
	bool Ox = (m_PointA.x <= x) && (m_PointA.x+m_PointB.x >= x);
	bool Oy = (m_PointA.y <= y) && ((m_PointA.y + m_PointB.y >= y));
	return (Ox && Oy);
}

void RectTransform::setPosition(const vec2 & vec)
{
	setPosition((int)vec.x, (int)vec.y);
}

void RectTransform::setPosition(int x, int y)
{
	m_PointA.x  = x;
	m_PointA.y  = y;
}

void RectTransform::setWidth(int w)
{
	m_PointB.x = w;
}

void RectTransform::setHeight(int h)
{
	m_PointB.y += h;
}
