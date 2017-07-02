#ifndef _MATRICES_H_
#define _MATRICES_H_

#include "vectors.h"

namespace kmu
{
	class SquareMatrix
	{
	public:
		SquareMatrix(size_t power, float diagonal = 0.0f);
		SquareMatrix(const SquareMatrix &mtx);
		virtual ~SquareMatrix();

		virtual inline float &element(size_t i, size_t j);
		virtual inline float at(size_t i, size_t j);
		virtual inline size_t bytes();
		virtual inline const float *get();

		const SquareMatrix &operator=(const SquareMatrix &mtx);
		const SquareMatrix &operator*=(const SquareMatrix &mtx);

		std::string toString();

		static SquareMatrix mult(const SquareMatrix &mtx1, const SquareMatrix &mtx2);
	private:
		size_t oSize;
		float *oData;
	};

	class mat4 : public SquareMatrix
	{
	public:
		mat4(float n = 1.0f);
		mat4(const mat4 &mat);
		~mat4();

		const mat4 &operator*(const mat4 &right);

		static mat4 mat4::Translation(float x, float y, float z)
		{
			mat4 result(1.0f);
			result.element(0, 3) = x;
			result.element(1, 3) = y;
			result.element(2, 3) = z;
			return result;
		}
		static mat4 mat4::Rotation(float x, float y, float z)
		{
			mat4 mx(1.0f);
			mat4 my(1.0f);
			mat4 mz(1.0f);
			float c_mx(cosf(x)), s_mx(sinf(x));
			float c_my(cosf(y)), s_my(sinf(y));
			float c_mz(cosf(z)), s_mz(sinf(z));

			mx.element(1, 1) =  c_mx;
			mx.element(2, 2) =  c_mx;
			mx.element(1, 2) = -s_mx;
			mx.element(2, 1) =  s_mx;

			my.element(0, 0) =  c_my;
			my.element(2, 2) =  c_my;
			my.element(2, 0) = -s_my;
			my.element(0, 2) =  s_my;

			mz.element(0, 0) =  c_mz;
			mz.element(1, 1) =  c_mz;
			mz.element(0, 1) = -s_mz;
			mz.element(1, 0) =  s_mz;

			return mz*(my*mx);
		}

		static mat4 mat4::Rotation(const kmu::quaternion &q)
		{
			kmu::mat4 res(1.0f);

			res.element(0, 0) = powf(q.w, 2) + powf(q.x, 2) - powf(q.y, 2) - powf(q.z, 2);  res.element(0, 1) = 2 * q.x*q.y + 2 * q.w*q.z;  res.element(0, 2) = 2 * q.x*q.z - 2 * q.w*q.y;  res.element(0, 3) = 0;
			res.element(1, 0) = 2 * q.z*q.y - 2 * q.w*q.z;  res.element(1, 1) = powf(q.w, 2) - powf(q.x, 2) + powf(q.y, 2) - powf(q.z, 2);  res.element(1, 2) = 2 * q.y*q.z + 2 * q.w*q.x;  res.element(1, 3) = 0;
			res.element(2, 0) = 2 * q.x*q.z + 2 * q.w*q.y;  res.element(2, 1) = 2 * q.y*q.z - 2 * q.w*q.x;  res.element(2, 2) = powf(q.w, 2) - powf(q.x, 2) - powf(q.y, 2) + powf(q.z, 2);  res.element(2, 3) = 0;
			res.element(3, 0) = 0;  res.element(3, 1) = 0;  res.element(3, 2) = 0;  res.element(3, 3) = powf(q.w, 2) + powf(q.x, 2) + powf(q.y, 2) + powf(q.z, 2);

			return res;
		}

		static mat4 mat4::Scaling(float x, float y, float z)
		{
			mat4 result;
			result.element(0, 0) = x;
			result.element(1, 1) = y;
			result.element(2, 2) = z;
			result.element(3, 3) = 1.0;
			return result;
		}
		static mat4 mat4::CameraMatrix(vec3 target, vec3 up)
		{
			target.normalize();
			up.normalize();
			up = up.cross(target);
			vec3 v = target.cross(up);

			mat4 m(1.0f);

			m.element(0, 0) = up[0]; m.element(0, 1) = up[1]; m.element(0, 2) = up[2];
			m.element(1, 0) = v[0];  m.element(1, 1) = v[1];  m.element(1, 2) = v[2];
			m.element(2, 0) = target[0]; m.element(2, 1) = target[1]; m.element(2, 2) = target[2];
			return m;
		}
		static mat4 mat4::Perspective(float fov, int width, int heigth, float nr, float fr)
		{
			float ar = (float)width / (float)heigth;
			float range = nr - fr;
			fov = tanf(fov / 2);
			mat4 m;
			m.element(0, 0) = 1.0f / (fov * ar);
			m.element(1, 1) = 1.0f / fov;
			m.element(2, 2) = (-nr - fr) / range;
			m.element(2, 3) = 2.0f * fr * nr / range;
			m.element(3, 2) = 1.0f;
			return m;
		}
	};
}

#endif // !_MATRICES_H_
