#include "vec3.hpp"

kmu::vec3::vec3()
	: vec3(0.0f, 0.0f, 0.0f)
{
}
kmu::vec3::vec3(float a, float b, float c)
	: oData(new Point3f(a, b, c))
	, x(oData->x)
	, y(oData->y)
	, z(oData->z)
	, r(oData->x)
	, g(oData->y)
	, b(oData->z)
{
}
kmu::vec3::vec3(const vec3 & vec)
	: vec3(vec.oData->x, vec.oData->y, vec.oData->z)
{
}
kmu::vec3::~vec3()
{
	delete oData;
}
inline float kmu::vec3::magnitude()const
{
	return sqrtf(this->sqrMagnitude());
}
inline float kmu::vec3::sqrMagnitude()const
{
	return (oData->x*oData->x +
		oData->y*oData->y +
		oData->z*oData->z);
}
inline float kmu::vec3::dot(const vec3 & vec)const
{
	return (oData->x*vec.oData->x +
		oData->y*vec.oData->y +
		oData->z*vec.oData->z);
}
inline kmu::vec3 kmu::vec3::cross(const vec3 & vec)const
{
	return vec3(oData->y * vec.oData->z - oData->z * vec.oData->y,
		oData->z * vec.oData->x - oData->x * vec.oData->z,
		oData->x * vec.oData->y - oData->y * vec.oData->x);
}
inline kmu::vec3 & kmu::vec3::normalize()
{
	float len = this->magnitude();
	if (len != 0)
	{
		oData->x /= len;
		oData->y /= len;
		oData->z /= len;
	}
	return *this;
}
inline kmu::vec3 kmu::vec3::normalized()const
{
	float len = this->magnitude();
	if (len == 0)
		len = 0.000001f;
	return vec3(oData->x / len,
		oData->y / len,
		oData->z / len);
}
inline Point3f kmu::vec3::point() const
{
	return *oData;
}
inline kmu::vec3::operator Point3f() const
{
	return *oData;
}
inline std::string kmu::vec3::toString()const
{
	return std::string('(' + std::to_string(oData->x) + ", " + std::to_string(oData->y) + ", " + std::to_string(oData->z) + ')');
}
inline void kmu::vec3::set(float X, float Y, float Z)
{
	oData->x = X;
	oData->y = Y;
	oData->z = Z;
}
inline float & kmu::vec3::operator[](size_t id)
{
	switch (id)
	{
	case 1: return oData->y;
	case 2: return oData->z;
	default: return oData->x;
	}
}
inline const kmu::vec3 & kmu::vec3::operator=(const vec3 & vec)
{
	(*oData) = (*vec.oData);
	return *this;
}
inline kmu::vec3 & kmu::vec3::operator+=(const vec3 & vec)
{
	oData->x += vec.oData->x;
	oData->y += vec.oData->y;
	oData->z += vec.oData->z;
	return *this;
}
inline kmu::vec3 & kmu::vec3::operator-=(const vec3 & vec)
{
	oData->x -= vec.oData->x;
	oData->y -= vec.oData->y;
	oData->z -= vec.oData->z;
	return *this;
}
inline kmu::vec3 & kmu::vec3::operator*=(float n)
{
	oData->x *= n;
	oData->y *= n;
	oData->z *= n;
	return *this;
}
inline kmu::vec3 & kmu::vec3::operator/=(float n)
{
	n = (n == 0) ? 0.000001f : n;
	oData->x /= n;
	oData->y /= n;
	oData->z /= n;
	return *this;
}
inline kmu::vec3 kmu::operator+(const vec3 &v, const vec3 & vec)
{
	return vec3(v.oData->x + vec.oData->x,
		v.oData->y + vec.oData->y,
		v.oData->z + vec.oData->z);
}
inline kmu::vec3 kmu::operator-(const vec3 &v, const vec3 & vec)
{
	return vec3(v.oData->x - vec.oData->x,
		v.oData->y - vec.oData->y,
		v.oData->z - vec.oData->z);
}
inline kmu::vec3 kmu::operator*(const vec3 &v, float n)
{
	return vec3(v.oData->x * n,
		v.oData->y * n,
		v.oData->z * n);
}
inline kmu::vec3 kmu::operator/(const vec3 &v, float n)
{
	n = (n == 0) ? 0.000001f : n;
	return vec3(v.oData->x / n,
		v.oData->y / n,
		v.oData->z / n);
}

kmu::vec3 kmu::lerp(const vec3 & a, const vec3 & b, float t)
{
	return a*t - b*(1-t);
}
