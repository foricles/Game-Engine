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

		virtual inline void conjugate();
		virtual inline quaternion conjugated() const;
		virtual inline const quaternion &operator=(const quaternion &qut);

		virtual inline kmu::vec3 rotate(const kmu::vec3 &vect) const;

		static quaternion euler(float X, float Y, float Z);
		static quaternion angleAxis(float angle, const vec3 &axes);

		friend inline quaternion operator*(const quaternion &q1, const quaternion &q2);
		friend inline quaternion operator*(const quaternion &q1, const vec3 &vec);
	};
}
#endif // !_QUATERNION_H_