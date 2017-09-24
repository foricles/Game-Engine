#ifndef _VEC3_H_
#define _VEC3_H_

#include "point.hpp"
#include <string>
#define MY_PI 3.1415926535897932f
namespace kmu
{
	class vec3
	{
	private:
		Point3f *oData;
	public:
		float &x;
		float &y;
		float &z;

		float &r;
		float &g;
		float &b;
	public:
		vec3();
		vec3(float a, float b, float c);
		vec3(const vec3 &vec);
		virtual ~vec3();

		virtual inline float magnitude()const;
		virtual inline float sqrMagnitude()const;
		virtual inline float dot(const vec3 &vec)const;
		virtual inline vec3 cross(const vec3 &vec)const;
		virtual inline vec3 &normalize();
		virtual inline vec3 normalized()const;
		virtual inline std::string toString()const;

		virtual inline void set(float X, float Y, float Z);

		virtual inline Point3f point()const;
		virtual inline operator Point3f()const;

		virtual inline float &operator[](size_t id);
		virtual inline const vec3 &operator=(const vec3 &vec);
		virtual inline vec3 &operator+=(const vec3 &vec);
		virtual inline vec3 &operator-=(const vec3 &vec);
		virtual inline vec3 &operator*=(float n);
		virtual inline vec3 &operator/=(float n);

		friend inline vec3 operator+(const vec3 &v, const vec3 &vec);
		friend inline vec3 operator-(const vec3 &v, const vec3 &vec);
		friend inline vec3 operator*(const vec3 &v, float n);
		friend inline vec3 operator/(const vec3 &v, float n);
	};
#define VEC3_RIGHT (kmu::vec3(1.0f, 0.0f, 0.0f))
#define VEC3_UP    (kmu::vec3(0.0f, 1.0f, 0.0f))
#define VEC3_FRONT (kmu::vec3(0.0f, 0.0f, 1.0f))
#define VEC3_IDENT (kmu::vec3(1.0f, 1.0f, 1.0f))
#define VEC3_PI    (kmu::vec3(MY_PI, MY_PI, MY_PI))
}
#endif // !_VEC3_H_