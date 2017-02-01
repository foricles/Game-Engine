#ifndef _TRANSFORM_H
#define _TRANSFORM_H

#include <cmath>


#include "../GlutEngine/Vector2.h"
#include "../GlutEngine/math_help_funk.h"

class Transform
{
protected:
	//Позиция объекта
	vec2 *m_Position;
	//Вращение объекта
	double m_Angle;
	//Размер объекта
	vec2 *m_Scale;
public:
	Transform();
	Transform(
		const vec2 &pos,
		double angle,
		const vec2 &sca);
	Transform(
		double posx_x = 0, double pos_y  = 0,
		double angle = 0,
		double scl_x  = 1, double scl_y  = 1);
	virtual ~Transform();

	//Сдвинуть позицию на вектор dv
	void Translate(const vec2 &dv);
	//Сдвинуть позицию на dx, dy
	void Translate(float dx, float dy);
	//Повернуть на deg градусов
	void Rotate(float deg);
	//Увеличить в k раз
	void Scale(float k);
    
	vec2 getPosition();
	vec2 getScale();
	double getAngle();

};


#endif // !_TRANSFORM_H
