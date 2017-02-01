#include "Color.h"

Color::Color()
{
	Red = 255;
	Green = 255;
	Blue = 255;
	Alpha = 255;
}

Color::Color(float r, float g, float b, float a)
{
	Red = r;
	Green = g;
	Blue = b;
	Alpha = a;
}

Color::Color(const Color & color)
{
	Red =   color.Red;
	Green = color.Green;
	Blue =  color.Blue;
	Alpha = color.Alpha;
}

Color::~Color()
{

}

void Color::Identity()
{
	Red   /=255;
	Green /=255;
	Blue  /=255;
	Alpha /=255;
}

void Color::UnIdentity()
{
	Red   *= 255;
	Green *= 255;
	Blue  *= 255;
	Alpha *= 255;
}

float Color::ToIdentity(int c)
{
	return (float)c/255;
}

int Color::ToUnidentity(float c)
{
	return (int)c * 255;
}

void Color::operator=(const Color & color)
{
	Red = color.Red;
	Blue = color.Blue;
	Green = color.Green;
	Alpha = color.Alpha;
}

