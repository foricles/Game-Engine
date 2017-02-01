#ifndef _COLORS_H
#define _COLORS_H

#include "../GlutEngine/Color.h"

class Colors
{
public:
	static Color White() 
	{
		Color color(255, 255, 255);
		color.Identity();
		return color;
	}
	static Color Black() 
	{
		Color color(0, 0, 0);
		color.Identity();
		return color;
	}
	static Color Gray()
	{
		Color color(204, 204, 204);
		color.Identity();
		return color;
	}

	static Color Red()
	{
		Color color(255, 0, 0);
		color.Identity();
		return color;
	}
	static Color DarkRed()
	{
		Color color(102, 0, 0);
		color.Identity();
		return color;
	}
	static Color SoftRed()
	{
		Color color(204, 0, 0);
		color.Identity();
		return color;
	}

	static Color Blue() 
	{
		Color color(0, 0, 255);
		color.Identity();
		return color;
	}
	static Color DarkBlue()
	{
		Color color(0, 0, 102);
		color.Identity();
		return color;
	}
	static Color SoftBlue()
	{
		Color color(0, 51, 204);
		color.Identity();
		return color;
	}

	static Color Green()
	{
		Color color(0, 255, 0);
		color.Identity();
		return color;
	}
	static Color DarkGreen()
	{
		Color color(51, 102, 51);
		color.Identity();
		return color;
	}
	static Color SoftGreen()
	{
		Color color(51, 204, 0);
		color.Identity();
		return color;
	}

	static Color Yellow()
	{
		Color color(255, 255, 0);
		color.Identity();
		return color;
	}

	static Color Orange()
	{
		Color color(255, 153, 0);
		color.Identity();
		return color;
	}
};

#endif // !_COLORS_H

