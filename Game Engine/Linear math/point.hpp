#ifndef _POINT_H_
#define _POINT_H_

struct Point2f
{
	float x;
	float y;

	Point2f() :Point2f(0, 0) {}
	Point2f(float X, float Y) :x(X), y(Y) {}
	Point2f(const Point2f &another) :Point2f(another.x, another.y) {}
	const Point2f &operator=(const Point2f &another)
	{
		this->x = another.x;
		this->y = another.y;
		return *this;
	}
};

struct Point3f
{
	float x;
	float y;
	float z;

	Point3f() :Point3f(0, 0, 0) {}
	Point3f(float X, float Y, float Z) :x(X), y(Y), z(Z) {}
	Point3f(const Point3f &another) :Point3f(another.x, another.y, another.z) {}
	const Point3f &operator=(const Point3f &another)
	{
		this->x = another.x;
		this->y = another.y;
		this->z = another.z;
		return *this;
	}
};

struct Point4f
{
	float x;
	float y;
	float z;
	float w;

	Point4f() :Point4f(0, 0, 0, 1) {}
	Point4f(float X, float Y, float Z, float W) :x(X), y(Y), z(Z), w(W) {}
	Point4f(const Point4f &another) :Point4f(another.x, another.y, another.z, another.w) {}
	const Point4f &operator=(const Point4f &another)
	{
		this->x = another.x;
		this->y = another.y;
		this->z = another.z;
		this->w = another.w;
		return *this;
	}
};
#endif // !_POINT_H_