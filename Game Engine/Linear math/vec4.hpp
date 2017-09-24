#ifndef _VEC4_H_
#define _VEC4_H_

#include "point.hpp"
#include <string>
#define MY_PI 3.1415926535897932f
namespace kmu
{
	class vec4
	{
	protected:
		Point4f *oData;
	public:
		float &x;
		float &y;
		float &z;
		float &w;

		float &r;
		float &g;
		float &b;
		float &a;
	public:
		vec4();
		vec4(float a, float b, float c, float d);
		vec4(const vec4 &vec);
		virtual ~vec4();

		virtual inline float dot(const vec4 &vec)const;
		virtual inline float magnitude()const;
		virtual inline vec4 &normalize();
		virtual inline vec4 normalized()const;
		virtual inline std::string toString()const;

		virtual inline Point4f point()const;
		virtual inline operator Point4f()const;

		virtual inline float &operator[](size_t id);
		virtual inline const vec4 &operator=(const vec4 &vec);

		virtual inline vec4 &operator+=(const vec4 &vec);
		virtual inline vec4 &operator-=(const vec4 &vec);
		virtual inline vec4 &operator*=(float n);
		virtual inline vec4 &operator/=(float n);

		virtual inline vec4 operator+(const vec4 &vec)const;
		virtual inline vec4 operator-(const vec4 &vec)const;
		virtual inline vec4 operator*(float n)const;
		virtual inline vec4 operator/(float n)const;
	};
#define VEC4_IDENT (kmu::vec4(1.0f, 1.0f, 1.0f, 1.0f))
#define VEC4_PI    (kmu::vec4(MY_PI, MY_PI, MY_PI, MY_PI))
}
#endif // !_VEC4_H_