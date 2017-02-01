#ifndef _TRANSFORM_H
#define _TRANSFORM_H

#include <cmath>


#include "../GlutEngine/Vector2.h"
#include "../GlutEngine/math_help_funk.h"

class Transform
{
protected:
	//������� �������
	vec2 *m_Position;
	//�������� �������
	double m_Angle;
	//������ �������
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

	//�������� ������� �� ������ dv
	void Translate(const vec2 &dv);
	//�������� ������� �� dx, dy
	void Translate(float dx, float dy);
	//��������� �� deg ��������
	void Rotate(float deg);
	//��������� � k ���
	void Scale(float k);
    
	vec2 getPosition();
	vec2 getScale();
	double getAngle();

};


#endif // !_TRANSFORM_H
