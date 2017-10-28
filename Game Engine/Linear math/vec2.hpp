#ifndef _VEC2_H_
#define _VEC2_H_

#include "point.hpp"
#include <string>
#define MY_PI 3.1415926535897932f
namespace kmu
{
	class vec2
	{
	private:
		Point2f *oData;
	public:
		float &x;
		float &y;

		float &u;
		float &w;
	public:
		vec2();
		vec2(float a, float b);
		vec2(const vec2 &another);
		virtual ~vec2();

		virtual inline float magnitude() const;
		virtual inline float sqrMagnitude() const;
		virtual inline float angle() const;
		virtual inline float dot(const vec2 &vec) const;
		virtual inline float cross(const vec2 &vec) const;
		virtual inline vec2 &normalize();
		virtual inline vec2 normalized()const;
		virtual inline std::string toString()const;

		virtual inline void set(float x, float y);

		virtual inline Point2f point()const;
		virtual inline operator Point2f()const;

		virtual inline float &operator[](size_t id);
		virtual inline const vec2 &operator=(const vec2 &vec);
		virtual inline vec2 &operator+=(const vec2 &vec);
		virtual inline vec2 &operator-=(const vec2 &vec);
		virtual inline vec2 &operator*=(float n);
		virtual inline vec2 &operator/=(float n);

		extern friend vec2 operator+(const vec2 &v, const vec2 &vec);
		extern friend vec2 operator-(const vec2 &v, const vec2 &vec);
		extern friend vec2 operator*(const vec2 &v, float n);
		extern friend vec2 operator/(const vec2 &v, float n);

		extern friend vec2 lerp(const vec2 &a, const vec2 &b, float t);
	};
#define VEC2_RIGHT (kmu::vec2(1.0f, 0.0f))
#define VEC2_UP    (kmu::vec2(0.0f, 1.0f))
#define VEC2_IDENT (kmu::vec2(1.0f, 1.0f))
#define VEC2_PI    (kmu::vec2(MY_PI, MY_PI))
}
#endif // !_VEC2_H_