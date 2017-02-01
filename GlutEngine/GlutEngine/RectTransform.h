#ifndef _RECTTRANSFORM_H
#define _RECTTRANSFORM_H

#include "Vector2.h"
#include "Color.h"


class RectTransform
{
public:
	RectTransform(int x, int y, int w, int h);
	RectTransform(const vec2 &pos, int w, int h);
	RectTransform(const RectTransform &rectTransform);
	virtual ~RectTransform();

	vec2 & getPosition();
	int getWidth();
	int getHeight();

	bool Contain(const vec2 &point);
	bool Contain(int x, int y);

	virtual void setPosition(const vec2 &vec);
	virtual void setPosition(int x, int y);
	virtual void setWidth(int w);
	virtual void setHeight(int h);
private:
	vec2 m_PointA;
	vec2 m_PointB;
};


#endif // _RECTTRANSFORM_H

