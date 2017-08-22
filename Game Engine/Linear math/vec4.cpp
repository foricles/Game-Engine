#include "vec4.hpp"


kmu::vec4::vec4()
	: vec4(0.0f, 0.0f, 0.0f, 1.0f)
{
}
kmu::vec4::vec4(float a, float b, float c, float d)
	: oData(new Point4f(a, b, c, d))
	, x(oData->x)
	, y(oData->y)
	, z(oData->z)
	, w(oData->w)
	, r(oData->x)
	, g(oData->y)
	, b(oData->z)
	, a(oData->w)
{
}
kmu::vec4::vec4(const vec4 & vec)
	: vec4(vec.oData->x, vec.oData->y, vec.oData->z, vec.oData->w)
{
}
kmu::vec4::~vec4()
{
	delete oData;
}

inline float kmu::vec4::dot(const vec4 & vec)const
{
	return (oData->x*vec.oData->x
		+ oData->y*vec.oData->y
		+ oData->z*vec.oData->z
		+ oData->w*vec.oData->w);
}
inline float kmu::vec4::magnitude()const
{
	return sqrtf(oData->x*oData->x
		+ oData->y*oData->y
		+ oData->z*oData->z
		+ oData->w*oData->w);
}
inline kmu::vec4 & kmu::vec4::normalize()
{
	float l(this->magnitude());
	l = (l == 0) ? 0.00001f : l;
	oData->x /= l;
	oData->y /= l;
	oData->z /= l;
	oData->w /= l;
	return *this;
}
inline kmu::vec4 kmu::vec4::normalized()const
{
	float l(this->magnitude());
	l = (l == 0) ? 0.00001f : l;
	return vec4(oData->x / l,
		oData->y / l,
		oData->z / l,
		oData->w / l);
}
inline Point4f kmu::vec4::point() const
{
	return *oData;
}
inline kmu::vec4::operator Point4f() const
{
	return *oData;
}
inline std::string kmu::vec4::toString()const
{
	return std::string('(' + std::to_string(oData->x) + ", " + std::to_string(oData->y) + ", " + std::to_string(oData->z) + ", " + std::to_string(oData->w) + ')');
}
inline float & kmu::vec4::operator[](size_t id)
{
	switch (id)
	{
	case 1: return oData->y;
	case 2: return oData->z;
	case 3: return oData->w;
	default: return oData->x;
	}
}
inline const kmu::vec4 & kmu::vec4::operator=(const vec4 & vec)
{
	(*oData) = (*vec.oData);
	return *this;
}
inline kmu::vec4 & kmu::vec4::operator+=(const vec4 & vec)
{
	oData->x += vec.oData->x;
	oData->y += vec.oData->y;
	oData->z += vec.oData->z;
	oData->w += vec.oData->w;
	return *this;
}
inline kmu::vec4 & kmu::vec4::operator-=(const vec4 & vec)
{
	oData->x -= vec.oData->x;
	oData->y -= vec.oData->y;
	oData->z -= vec.oData->z;
	oData->w -= vec.oData->w;
	return *this;
}
inline kmu::vec4 & kmu::vec4::operator*=(float n)
{
	oData->x *= n;
	oData->y *= n;
	oData->z *= n;
	oData->w *= n;
	return *this;
}
inline kmu::vec4 & kmu::vec4::operator/=(float n)
{
	n = (n == 0) ? 0.00001f : n;
	oData->x /= n;
	oData->y /= n;
	oData->z /= n;
	oData->w /= n;
	return *this;
}
inline kmu::vec4 kmu::vec4::operator+(const vec4 & vec)const
{
	return vec4(oData->x + vec.oData->x,
		oData->y + vec.oData->y,
		oData->z + vec.oData->z,
		oData->w + vec.oData->w);
}
inline kmu::vec4 kmu::vec4::operator-(const vec4 & vec)const
{
	return vec4(oData->x - vec.oData->x,
		oData->y - vec.oData->y,
		oData->z - vec.oData->z,
		oData->w - vec.oData->w);
}
inline kmu::vec4 kmu::vec4::operator*(float n)const
{
	return vec4(oData->x * n,
		oData->y * n,
		oData->z * n,
		oData->w * n);
}
inline kmu::vec4 kmu::vec4::operator/(float n)const
{
	n = (n == 0) ? 0.00001f : n;
	return vec4(oData->x / n,
		oData->y / n,
		oData->z / n,
		oData->w / n);
}