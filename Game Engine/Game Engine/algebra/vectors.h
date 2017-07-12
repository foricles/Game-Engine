#ifndef _MATH_VECTORS_H_
#define _MATH_VECTORS_H_

#include "definedtype.h"

namespace kmu
{
	class vec2
	{
	public:
		float x;
		float y;

		vec2();
		vec2(float _x, float _y);
		vec2(float _x, float _y, float _x1, float _y1);
		vec2(const vec2 &vec);
		~vec2();

		float magnitude();
		float sqrMagnitude();
		float angle();
		float dot(const vec2 &vec);
		float cross(const vec2 &vec);
		vec2 &normalize();
		vec2 normalized();
		std::string toString();

		float &operator[](size_t id);
		vec2 &operator+=(const vec2 &vec);
		vec2 &operator-=(const vec2 &vec);
		vec2 &operator*=(float n);
		vec2 &operator/=(float n);
		vec2 operator+(const vec2 &vec);
		vec2 operator-(const vec2 &vec);
		vec2 operator*(float n);
		vec2 operator/(float n);
	};

	class vec3
	{
	public:
		float x;
		float y;
		float z;

		vec3();
		vec3(float X, float Y, float Z);
		vec3(const vec2 &vec, float Z);
		vec3(const vec3 &vec);
		~vec3();

		float magnitude();
		float sqrMagnitude();
		float dot(const vec3 &vec);
		vec3 cross(const vec3 &vec);
		vec3 &normalize();
		vec3 normalized();
		std::string toString();

		float &operator[](size_t id);
		vec3 &operator+=(const vec3 &vec);
		vec3 &operator-=(const vec3 &vec);
		vec3 &operator*=(float n);
		vec3 &operator/=(float n);
		vec3 operator+(const vec3 &vec);
		vec3 operator-(const vec3 &vec);
		vec3 operator*(float n);
		vec3 operator/(float n);
	};

	class vec4
	{
	public:
		float x;
		float y;
		float z;
		float w;

		vec4();
		vec4(float X, float Y, float Z, float W);
		vec4(const vec2 &vec, float Z, float W);
		vec4(const vec3 &vec, float W);
		vec4(const vec2 &vec_1, const vec2 &vec_2);
		vec4(const vec4 &vec);
		~vec4();

		float dot(const vec4 &vec);
		float magnitude();
		vec4 &normalize();
		vec4 normalized();
		std::string toString();

		float &operator[](size_t id);
		vec4 &operator+=(const vec4 &vec);
		vec4 &operator-=(const vec4 &vec);
		vec4 &operator*=(float n);
		vec4 &operator/=(float n);
		vec4 operator+(const vec4 &vec);
		vec4 operator-(const vec4 &vec);
		vec4 operator*(float n);
		vec4 operator/(float n);
	};

	class quaternion : public vec4
	{
	public:
		quaternion();
		quaternion(float X, float Y, float Z, float W);
		quaternion(const vec2 &vec, float Z, float W);
		quaternion(const vec3 &vec, float W);
		quaternion(const vec2 &vec_1, const vec2 &vec_2);
		quaternion(const vec4 &vec);
		quaternion(const quaternion &qut);
		~quaternion();
		quaternion &conjugate();
		quaternion operator*(const quaternion &qut);
		quaternion operator*(const vec3 &vec);

		static quaternion euler(float angle, float X, float Y, float Z);
		static quaternion euler(float angle, const vec3 &axes);
	};
}

#define VEC2_RIGHT (kmu::vec2(1.0f, 0.0f))
#define VEC2_UP    (kmu::vec2(0.0f, 1.0f))
#define VEC2_IDENT (kmu::vec2(1.0f, 1.0f))
#define VEC2_PI    (kmu::vec2(MY_PI, MY_PI))

#define VEC3_RIGHT (kmu::vec3(1.0f, 0.0f, 0.0f))
#define VEC3_UP    (kmu::vec3(0.0f, 1.0f, 0.0f))
#define VEC3_FRONT (kmu::vec3(0.0f, 0.0f, 1.0f))
#define VEC3_IDENT (kmu::vec3(1.0f, 1.0f, 1.0f))
#define VEC3_PI    (kmu::vec3(MY_PI, MY_PI, MY_PI))

#define VEC4_IDENT (kmu::vec4(1.0f, 1.0f, 1.0f, 1.0f))
#define VEC4_PI    (kmu::vec4(MY_PI, MY_PI, MY_PI, MY_PI)  )

#endif // !_MATH_VECTORS_H_