#include "lightbase.hpp"

LightBase::LightBase()
	: LightBase(0.0f, 0.0f, 0.0f, 1.0f)
{
}

LightBase::LightBase(const kmu::vec4 & color)
	:m_color(color)
{
}

LightBase::LightBase(float r, float g, float b, float a)
	:m_color(r, g, b, a)
{
}

LightBase::~LightBase()
{
}

void LightBase::setColor(const kmu::vec4 & color)
{
	m_color = color;
}

void LightBase::setColor(float r, float g, float b, float a)
{
	m_color = kmu::vec4(r, g, b, a);
}
