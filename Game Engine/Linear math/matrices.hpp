#ifndef _MATRICES_H_
#define _MATRICES_H_

#include "vec2.hpp"
#include "vec3.hpp"
#include "vec4.hpp"
#include "quaternion.hpp"

namespace kmu
{
	class mat
	{
	public:
		mat(int n, int m);
		mat(int n, int m, const float *arr);
		mat(int n, float k);
		mat(const mat & mtx);
		virtual ~mat();

		virtual inline float &at(int i, int j) const;
		virtual inline float &at(int i, int j);
				
		virtual inline int getN() const;
		virtual inline int getM() const;
				
		virtual inline const mat & mult(const mat & other);
		virtual inline const mat & operator*=(const mat & other);
		virtual inline const mat & operator=(const mat & other);
		virtual inline mat operator*(const mat & other) const;
				
		virtual inline float &operator[](size_t id);
		virtual inline const float &operator[](size_t id)const;

		virtual inline bool isSquere() const;
		virtual inline std::string toString() const;

	protected:
		int getSize() const;
		int oN;
		int oM;
		float *oData;
	};

	class mat4 : public mat
	{
	public:
		mat4(float n = 1.0f);
		mat4(const mat4 &mat);
		~mat4();

		virtual inline const mat4 &operator*(const mat4 &right);
		virtual inline const mat4 & operator=(const mat4 & other);

		virtual inline const vec4 operator*(const vec4 &right);
		virtual inline const vec3 operator*(const vec3 &right);

		static mat4 Translation(float x, float y, float z);
		static mat4 Translation(const kmu::vec3 &pos);

		static mat4 Rotation(float x, float y, float z);
		static mat4 Rotation(const kmu::quaternion &q);
		static mat4 Scaling(float x, float y, float z);
		static mat4 CameraMatrix(vec3 target, vec3 up);
		static mat4 Perspective(float fov, int width, int heigth, float nr, float fr);

		static quaternion Quaternion(const kmu::mat4 &mtx);
	};
}

#endif // !_MATRICES_H_
