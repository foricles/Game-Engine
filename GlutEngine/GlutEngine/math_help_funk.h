#ifndef _MATH_HELP_H
#define _MATH_HELP_H

class MathHelp
{
public:
	static float DegToRad(float deg)
	{
		float pi = 3.141592653589793238462643f;
		return (deg*(pi / 180));
	}

	static float RadToDeg(float rad)
	{
		float pi = 3.141592653589793238462643f;
		return (rad*(180 / pi));
	}

	static float clamp(float value, float min, float max)
	{
		if (value <= min)return min;
		if (value >= max)return max;
		return value;
	}
};

#endif //_MATH_HELP_H