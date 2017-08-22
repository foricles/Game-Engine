#ifndef _QUATERNION_H_
#define _QUATERNION_H_

#include "point.hpp"
#include "vec4.hpp"
#include "vec3.hpp"
#define MY_PI 3.1415926535897932f
namespace kmu
{
	class quaternion : public vec4
	{
	public:
		quaternion();
		quaternion(float a, float b, float c, float d);
		quaternion(const vec4 &vec);
		quaternion(const quaternion &qut);
		virtual ~quaternion();

		virtual inline quaternion &conjugate();
		virtual inline quaternion operator*(const quaternion &qut);
		virtual inline quaternion operator*(const vec3 &vec);
		virtual inline const quaternion &operator=(const quaternion &qut);

		static quaternion euler(float angle, float X, float Y, float Z);
		static quaternion euler(float angle, const vec3 &axes);
	};
}
#endif // !_QUATERNION_H_