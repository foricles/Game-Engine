#include "Vector2.h"

vec2::vec2()
{
	*this = VNULL;
}

vec2::vec2(double X, double Y)
{
	x = X;
	y = Y;
}

vec2::vec2(const vec2 & vec)
{
	x = vec.x;
	y = vec.y;
}

void vec2::Normalize()
{
	double mg = Magnitude();
	x = x / mg;
	y = y / mg;
}

vec2 vec2::Normalized()
{
	double mg = Magnitude();
	double _x = x / mg;
	double _y = y / mg;
	return vec2(_x, _y);
}

double vec2::Magnitude()
{
	return sqrt(pow(x,2)+pow(y,2));
}

vec2::~vec2()
{
}


void vec2::operator=(const vec2 &vec)
{
	x = vec.x;
	y = vec.y;
}

void vec2::operator+=(const vec2 & vec)
{
	x += vec.x;
	y += vec.y;
}

void vec2::operator-=(const vec2 & vec)
{
	x -= vec.x;
	y -= vec.y;
}

void vec2::operator*=(double k)
{
	x *= k;
	y *= k;
}

vec2  vec2::operator*(double k) const
{
	vec2 temp;
	temp.x = x*k;
	temp.y = y*k;
	return temp;
}

double vec2::operator*(const vec2 &vec) const
{
	return (x*vec.x + y*vec.y);
}

bool vec2::operator!=(const vec2 &vec)const
{
	return((x != vec.x) && (y != vec.y));
}

bool vec2::operator==(const vec2 & vec) const
{
	return ((x == vec.x) && (y == vec.y));
}

vec2 vec2::operator+(const vec2 &vec)const
{
	vec2 temp;
	temp.x = x + vec.x;
	temp.y = y + vec.y;
	return temp;
}

vec2 vec2::operator-(const vec2 &vec)const
{
	vec2 temp;
	temp.x = x - vec.x;
	temp.y = y - vec.y;
	return temp;
}




