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

inline kmu::quaternion & kmu::quaternion::conjugate()
{
	oData->x = -oData->x;
	oData->y = -oData->y;
	oData->z = -oData->z;
	return *this;
}
inline kmu::quaternion kmu::quaternion::operator*(const quaternion & qut)
{
	float W = oData->w*qut.oData->w - oData->x*qut.oData->x - oData->y*qut.oData->y - oData->z*qut.oData->z;
	float X = oData->x*qut.oData->w + oData->w*qut.oData->x + oData->y*qut.oData->z - oData->z*qut.oData->y;
	float Y = oData->y*qut.oData->w + oData->w*qut.oData->y + oData->z*qut.oData->x - oData->z*qut.oData->z;
	float Z = oData->z*qut.oData->w + oData->w*qut.oData->z + oData->x*qut.oData->y - oData->y*qut.oData->x;
	return quaternion(X, Y, Z, W);
}
inline kmu::quaternion kmu::quaternion::operator*(const vec3 & vec)
{
	float W = -oData->x*vec.x - oData->y*vec.y - oData->z*vec.z;
	float X = oData->w*vec.x + oData->y*vec.z - oData->z*vec.y;
	float Y = oData->w*vec.y + oData->z*vec.x - oData->x*vec.z;
	float Z = oData->w*vec.z + oData->x*vec.y - oData->y*vec.x;
	return quaternion(X, Y, Z, W);
}
inline const kmu::quaternion & kmu::quaternion::operator=(const quaternion & qut)
{
	(*oData) = (*qut.oData);
	return *this;
}

kmu::quaternion kmu::quaternion::euler(float angle, float X, float Y, float Z)
{
	float hs = sinf(angle / 2.0f);
	float hc = cosf(angle / 2.0f);
	X *= hs;
	Y *= hs;
	Z *= hs;
	return quaternion(X, Y, Z, hc);
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