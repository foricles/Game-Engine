#include "Transform.h"



Transform::Transform()
{
	m_Position = new vec2(0, 0);
	m_Angle = 0.0;
	m_Scale    = new vec2(1, 1);
}

Transform::Transform(const vec2 & pos, double angle, const vec2 & sca)
{
	*m_Position = pos;
	m_Angle = angle;
	*m_Scale    = sca;
}

Transform::Transform(double posx_x, double pos_y, double angle, double scl_x, double scl_y)
{
	m_Position = new vec2(posx_x, pos_y);
	m_Angle = angle;
	m_Scale    = new vec2(scl_x, scl_y);
}

Transform::~Transform()
{
	delete m_Position;
	delete m_Scale;
}

void Transform::Translate(const vec2 & dv)
{
	*m_Position += dv;
}

void Transform::Translate(float dx, float dy)
{
	m_Position->x += dx;
	m_Position->y += dy;
}

void Transform::Rotate(float deg)
{
	m_Angle += deg;
}

void Transform::Scale(float k)
{
	*m_Scale *= k;
}

vec2 Transform::getPosition()
{
	return *m_Position;
}

vec2 Transform::getScale()
{
	return *m_Scale;
}

double Transform::getAngle()
{
	return m_Angle;
}
