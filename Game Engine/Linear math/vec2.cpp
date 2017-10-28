#include "vec2.hpp"

kmu::vec2::vec2()
	: vec2(0.0f, 0.0f)
{
}
kmu::vec2::vec2(float a, float b)
	: oData(new Point2f(a, b))
	, x(oData->x)
	, y(oData->y)
	, u(oData->x)
	, w(oData->y)
{
}
kmu::vec2::vec2(const vec2 & vec)
	: vec2(vec.oData->x, vec.oData->y)
{
}
kmu::vec2::~vec2()
{
	delete oData;
}
inline float kmu::vec2::magnitude()const
{
	return sqrtf(this->sqrMagnitude());
}
inline float kmu::vec2::sqrMagnitude()const
{
	return (oData->x*oData->x + oData->y*oData->y);
}
inline float kmu::vec2::angle()const
{
	return atan2f(oData->y, oData->x);
}
inline float kmu::vec2::dot(const vec2 & vec)const
{
	return (oData->x*vec.oData->x +
		oData->y*vec.oData->y);
}
inline float kmu::vec2::cross(const vec2 & vec)const
{
	return (oData->x*vec.oData->y -
		vec.oData->x*oData->y);
}
inline kmu::vec2 & kmu::vec2::normalize()
{
	float len = this->magnitude();
	if (len != 0)
	{
		oData->x /= len;
		oData->y /= len;
	}
	return *this;
}
inline kmu::vec2::operator Point2f() const
{
	return *oData;
}
inline kmu::vec2 kmu::vec2::normalized()const
{
	float len = this->magnitude();
	if (len == 0)
		len = 0.000001f;
	return vec2(oData->x / len, oData->y / len);
}
inline Point2f kmu::vec2::point()const
{
	return *oData;
}
inline std::string kmu::vec2::toString()const
{
	return std::string('(' + std::to_string(oData->x) + ", " + std::to_string(oData->y) + ')');
}
inline void kmu::vec2::set(float x, float y)
{
	oData->x = x;
	oData->y = y;
}
inline float & kmu::vec2::operator[](size_t id)
{
	if (id == 1)
		return oData->y;
	return oData->x;
}
inline const kmu::vec2 &kmu::vec2::operator=(const vec2 & vec)
{
	(*oData) = (*vec.oData);
	return *this;
}
inline kmu::vec2 & kmu::vec2::operator+=(const vec2 & vec)
{
	oData->x += vec.oData->x;
	oData->y += vec.oData->y;
	return *this;
}
inline kmu::vec2 & kmu::vec2::operator-=(const vec2 & vec)
{
	oData->x -= vec.oData->x;
	oData->y -= vec.oData->y;
	return *this;
}
inline kmu::vec2 & kmu::vec2::operator*=(float n)
{
	oData->x *= n;
	oData->y *= n;
	return *this;
}
inline kmu::vec2 & kmu::vec2::operator/=(float n)
{
	if (n == 0)
		n = 0.00001f;
	oData->x /= n;
	oData->y /= n;
	return *this;
}

inline kmu::vec2 kmu::operator+(const vec2 & v, const vec2 & vec)
{
	return vec2(v.oData->x + vec.oData->x,
		v.oData->y + vec.oData->y);
}
inline kmu::vec2 kmu::operator-(const vec2 & v, const vec2 & vec)
{
	return vec2(v.oData->x - vec.oData->x,
		v.oData->y - vec.oData->y);
}
inline kmu::vec2 kmu::operator*(const vec2 & v, float n)
{
	return vec2(v.oData->x*n, v.oData->y*n);
}
inline kmu::vec2 kmu::operator/(const vec2 & v, float n)
{
	if (n == 0)
		n = 0.000001f;
	return vec2(v.oData->x / n, v.oData->y / n);
}

inline kmu::vec2 kmu::lerp(const vec2 & a, const vec2 & b, float t)
{
	return a*t - b*(1 - t);
}