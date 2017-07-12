#include "vectors.h"

kmu::vec2::vec2() : vec2(0.0f, 0.0f)
{
}
kmu::vec2::vec2(float _x, float _y) : x(_x), y(_y)
{
}
kmu::vec2::vec2(float _x, float _y, float _x1, float _y1) : vec2(_x1 - _x, _y1 - _y)
{
}
kmu::vec2::vec2(const vec2 & vec) : vec2(vec.x, vec.y)
{
}
kmu::vec2::~vec2()
{
}
float kmu::vec2::magnitude()
{
	return sqrtf(this->sqrMagnitude());
}
float kmu::vec2::sqrMagnitude()
{
	return (x*x + y*y);
}
float kmu::vec2::angle()
{
	return atan2f(y, x);
}
float kmu::vec2::dot(const vec2 & vec)
{
	return (x*vec.x + y*vec.y);
}
float kmu::vec2::cross(const vec2 & vec)
{
	return (x*vec.y - vec.x*y);
}
kmu::vec2 & kmu::vec2::normalize()
{
	float len = this->magnitude();
	if (len != 0)
	{
		x /= len;
		y /= len;
	}
	return *this;
}
kmu::vec2 kmu::vec2::normalized()
{
	float len = this->magnitude();
	if (len != 0)
		len = 0.000001f;
	return vec2(x/len, y/len);
}
std::string kmu::vec2::toString()
{
	return std::string('(' + std::to_string(x) + ", " + std::to_string(y) + ')');
}
float & kmu::vec2::operator[](size_t id)
{
	if (id == 1)
		return y;
	return x;
}
kmu::vec2 & kmu::vec2::operator+=(const vec2 & vec)
{
	x += vec.x;
	y += vec.y;
	return *this;
}
kmu::vec2 & kmu::vec2::operator-=(const vec2 & vec)
{
	x -= vec.x;
	y -= vec.y;
	return *this;
}
kmu::vec2 & kmu::vec2::operator*=(float n)
{
	x *= n;
	y *= n;
	return *this;
}
kmu::vec2 & kmu::vec2::operator/=(float n)
{
	if (n == 0) 
		n = 0.00001f;
	x /= n;
	y /= n;
	return *this;
}
kmu::vec2 kmu::vec2::operator+(const vec2 & vec)
{
	return vec2(x + vec.x, y + vec.y);
}
kmu::vec2 kmu::vec2::operator-(const vec2 & vec)
{
	return vec2(x - vec.x, y - vec.y);
}
kmu::vec2 kmu::vec2::operator*(float n)
{
	return vec2(x*n, y*n);
}
kmu::vec2 kmu::vec2::operator/(float n)
{
	if (n == 0)
		n = 0.000001f;
	return vec2(x/n, y/n);
}


//---------------------------------------------------------------------------------------------------------------------------------
kmu::vec3::vec3() : vec3(0.0f, 0.0f, 0.0f)
{
}
kmu::vec3::vec3(float X, float Y, float Z) : x(X), y(Y), z(Z)
{
}
kmu::vec3::vec3(const vec2 & vec, float Z) : vec3(vec.x, vec.y, z)
{
}
kmu::vec3::vec3(const vec3 & vec) : vec3(vec.x, vec.y, vec.z)
{
}
kmu::vec3::~vec3()
{
}
float kmu::vec3::magnitude()
{
	return sqrtf(this->sqrMagnitude());
}
float kmu::vec3::sqrMagnitude()
{
	return (x*x + y*y + z*z);
}
float kmu::vec3::dot(const vec3 & vec)
{
	return (x*vec.x + y*vec.y + z*vec.z);
}
kmu::vec3 kmu::vec3::cross(const vec3 & vec)
{
	return vec3(y * vec.z - z * vec.y,
				z * vec.x - x * vec.z,
				x * vec.y - y * vec.x);
}
kmu::vec3 & kmu::vec3::normalize()
{
	float len = this->magnitude();
	if (len != 0)
	{
		x /= len;
		y /= len;
		z /= len;
	}
	return *this;
}
kmu::vec3 kmu::vec3::normalized()
{
	float len = this->magnitude();
	if (len != 0)
		len = 0.000001f;
	return vec3(x / len, y / len, z / len);
}
std::string kmu::vec3::toString()
{
	return std::string('(' + std::to_string(x) + ", " + std::to_string(y) + ", " + std::to_string(z) + ')');
}
float & kmu::vec3::operator[](size_t id)
{
	switch (id)
	{
	case 1: return y;
	case 2: return z;
	default: return x;
	}
}
kmu::vec3 & kmu::vec3::operator+=(const vec3 & vec)
{
	x += vec.x;
	y += vec.y;
	z += vec.z;
	return *this;
}
kmu::vec3 & kmu::vec3::operator-=(const vec3 & vec)
{
	x -= vec.x;
	y -= vec.y;
	z -= vec.z;
	return *this;
}
kmu::vec3 & kmu::vec3::operator*=(float n)
{
	x *= n;
	y *= n;
	z *= n;
	return *this;
}
kmu::vec3 & kmu::vec3::operator/=(float n)
{
	n = (n == 0) ? 0.000001f : n;
	x /= n;
	y /= n;
	z /= n;
	return *this;
}
kmu::vec3 kmu::vec3::operator+(const vec3 & vec)
{
	return vec3(x + vec.x, y + vec.y, z + vec.z);
}
kmu::vec3 kmu::vec3::operator-(const vec3 & vec)
{
	return vec3(x - vec.x, y - vec.y, z - vec.z);
}
kmu::vec3 kmu::vec3::operator*(float n)
{
	return vec3(x * n, y * n, z * n);
}
kmu::vec3 kmu::vec3::operator/(float n)
{
	n = (n == 0) ? 0.000001f : n;
	return vec3(x / n, y / n, z / n);
}


//------------------------------------------------------------------------------------------------------------

kmu::vec4::vec4() 
	: vec4(0.0f, 0.0f, 0.0f, 0.0f)
{
}
kmu::vec4::vec4(float X, float Y, float Z, float W)
	: x(X), y(Y), z(Z), w(W)
{
}
kmu::vec4::vec4(const vec2 & vec, float Z, float W)
	: vec4(vec.x, vec.y, Z, W)
{
}
kmu::vec4::vec4(const vec3 & vec, float W)
	: vec4(vec.x, vec.y, vec.z, W)
{
}
kmu::vec4::vec4(const vec2 & vec_1, const vec2 & vec_2)
	: vec4(vec_1.x, vec_1.y, vec_2.x, vec_2.y)
{
}
kmu::vec4::vec4(const vec4 & vec)
	: vec4(vec.x, vec.y, vec.z, vec.w)
{
}
kmu::vec4::~vec4()
{
}

float kmu::vec4::dot(const vec4 & vec)
{
	return (x*vec.x
		  + y*vec.y
		  + z*vec.z
		  + w*vec.w);
}
float kmu::vec4::magnitude()
{
	return sqrtf(x*x + y*y + z*z + w*w);
}
kmu::vec4 & kmu::vec4::normalize()
{
	float l(this->magnitude());
	l = (l == 0) ? 0.00001f : l;
	x /= l;
	y /= l;
	z /= l;
	w /= l;
	return *this;
}
kmu::vec4 kmu::vec4::normalized()
{
	float l(this->magnitude());
	l = (l == 0) ? 0.00001f : l;
	return vec4(x / l, y / l, z / l, w / l);
}
std::string kmu::vec4::toString()
{
	return std::string('(' + std::to_string(x) + ", " + std::to_string(y) + ", " + std::to_string(z) + ", " + std::to_string(w) + ')');
}
float & kmu::vec4::operator[](size_t id)
{
	switch (id)
	{
	case 1: return y;
	case 2: return z;
	case 3: return w;
	default: return x;
	}
}
kmu::vec4 & kmu::vec4::operator+=(const vec4 & vec)
{
	x += vec.x;
	y += vec.y;
	z += vec.z;
	w += vec.w;
	return *this;
}
kmu::vec4 & kmu::vec4::operator-=(const vec4 & vec)
{
	x -= vec.x;
	y -= vec.y;
	z -= vec.z;
	w -= vec.w;
	return *this;
}
kmu::vec4 & kmu::vec4::operator*=(float n)
{
	x *= n;
	y *= n;
	z *= n;
	w *= n;
	return *this;
}
kmu::vec4 & kmu::vec4::operator/=(float n)
{
	n = (n == 0) ? 0.00001f : n;
	x /= n;
	y /= n;
	z /= n;
	w /= n;
	return *this;
}
kmu::vec4 kmu::vec4::operator+(const vec4 & vec)
{
	return vec4(x + vec.x, y + vec.y, z + vec.z, w + vec.w);
}
kmu::vec4 kmu::vec4::operator-(const vec4 & vec)
{
	return vec4(x - vec.x, y - vec.y, z - vec.z, w - vec.w);
}
kmu::vec4 kmu::vec4::operator*(float n)
{
	return vec4(x * n, y * n, z * n, w * n);
}

kmu::vec4 kmu::vec4::operator/(float n)
{
	n = (n == 0) ? 0.00001f : n;
	return vec4(x / n, y / n, z / n, w / n);
}

//-------------------------------------------------------------------------------------------------------------------------

kmu::quaternion::quaternion() : vec4()
{
}
kmu::quaternion::quaternion(float X, float Y, float Z, float W) : vec4(X, Y, Z, W)
{
}
kmu::quaternion::quaternion(const vec2 & vec, float Z, float W) : vec4(vec, Z, W)
{
}
kmu::quaternion::quaternion(const vec3 & vec, float W) : vec4(vec, W)
{
}
kmu::quaternion::quaternion(const vec2 & vec_1, const vec2 & vec_2) : vec4(vec_1, vec_2)
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

kmu::quaternion & kmu::quaternion::conjugate()
{
	x = -x;
	y = -y;
	z = -z;
	return *this;
}

kmu::quaternion kmu::quaternion::operator*(const quaternion & qut)
{
	float W = w*qut.w - x*qut.x - y*qut.y - z*qut.z;
	float X = x*qut.w + w*qut.x + y*qut.z - z*qut.y;
	float Y = y*qut.w + w*qut.y + z*qut.x - z*qut.z;
	float Z = z*qut.w + w*qut.z + x*qut.y - y*qut.x;
	return quaternion(X, Y, Z, W);
}

kmu::quaternion kmu::quaternion::operator*(const vec3 & vec)
{
	float W = -x*vec.x - y*vec.y - z*vec.z;
	float X =  w*vec.x + y*vec.z - z*vec.y;
	float Y =  w*vec.y + z*vec.x - x*vec.z;
	float Z =  w*vec.z + x*vec.y - y*vec.x;
	return quaternion(X, Y, Z, W);
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
