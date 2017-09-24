#include "quaternion.hpp"

kmu::quaternion::quaternion() : vec4(0, 0, 0, 1)
{
}
kmu::quaternion::quaternion(float a, float b, float c, float d) : vec4(a, b, c, d)
{
}
kmu::quaternion::quaternion(const vec4 & vec) : vec4(vec.x, vec.y, vec.z, vec.w)
{
}
kmu::quaternion::quaternion(const quaternion & qut) : vec4(qut.x, qut.y, qut.z, qut.w)
{
}
kmu::quaternion::~quaternion()
{
}

inline void kmu::quaternion::conjugate()
{
	oData->x = -oData->x;
	oData->y = -oData->y;
	oData->z = -oData->z;
}

inline kmu::quaternion kmu::quaternion::conjugated() const
{
	return kmu::quaternion(-oData->x, -oData->y, -oData->z, oData->w);
}

inline const kmu::quaternion & kmu::quaternion::operator=(const quaternion & qut)
{
	(*oData) = (*qut.oData);
	return *this;
}

inline kmu::vec3 kmu::quaternion::rotate(const kmu::vec3 & vect) const
{
	//TODO:
	auto temp = ((*this) * vect) * this->conjugated();
	return kmu::vec3(temp.x, temp.y, temp.z);
}

kmu::quaternion kmu::quaternion::euler(float angle, float X, float Y, float Z)
{
	return quaternion::euler(angle, kmu::vec3(X, Y, Z));
}
kmu::quaternion kmu::quaternion::euler(float angle, const vec3 & axes)
{
	float hs = sinf(angle / 2.0f);
	float hc = cosf(angle / 2.0f);
	float X = axes.x * hs;
	float Y = axes.y * hs;
	float Z = axes.z * hs;
	return quaternion(X, Y, Z, hc);
}

inline kmu::quaternion kmu::operator*(const quaternion &q1, const quaternion &q2)
{
	float W = q1.oData->w*q2.oData->w - q1.oData->x*q2.oData->x - q1.oData->y*q2.oData->y - q1.oData->z*q2.oData->z;
	float X = q1.oData->x*q2.oData->w + q1.oData->w*q2.oData->x + q1.oData->y*q2.oData->z - q1.oData->z*q2.oData->y;
	float Y = q1.oData->y*q2.oData->w + q1.oData->w*q2.oData->y + q1.oData->z*q2.oData->x - q1.oData->z*q2.oData->z;
	float Z = q1.oData->z*q2.oData->w + q1.oData->w*q2.oData->z + q1.oData->x*q2.oData->y - q1.oData->y*q2.oData->x;
	return quaternion(X, Y, Z, W);
}
inline kmu::quaternion kmu::operator*(const quaternion &q1, const vec3 & vec)
{
	float W = -q1.oData->x*vec.x - q1.oData->y*vec.y - q1.oData->z*vec.z;
	float X = q1.oData->w*vec.x + q1.oData->y*vec.z - q1.oData->z*vec.y;
	float Y = q1.oData->w*vec.y + q1.oData->z*vec.x - q1.oData->x*vec.z;
	float Z = q1.oData->w*vec.z + q1.oData->x*vec.y - q1.oData->y*vec.x;
	return quaternion(X, Y, Z, W);
}