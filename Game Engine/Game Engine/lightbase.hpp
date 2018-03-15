#ifndef _LIGHTBASE_HPP_
#define _LIGHTBASE_HPP_

#include "transform.h"

class LightBase : public Transform
{
public:
	LightBase();
	LightBase(const kmu::vec4 &color);
	LightBase(float r, float g, float b, float a = 1.0f);
	~LightBase();

	void setColor(const kmu::vec4 &color);
	void setColor(float r, float g, float b, float a = 1.0f);
protected:
	kmu::vec4 m_color;
};

#endif // !_LIGHTBASE_HPP_