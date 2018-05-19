#ifndef _CAMERA_HPP_
#define _CAMERA_HPP_

#include "transform.h"

enum class Projection
{
	PERSPECTIVE,
	ORTHOGRAPHIC
};

class Camera
	: public Transform
{
public:
	struct ProjectionData
	{
		size_t Wight;
		size_t Height;
		float Near;
		float Far;
		float Fov;

		ProjectionData & operator=(const ProjectionData &data)
		{
			Wight = data.Wight;
			Height = data.Height;
			Near = data.Near;
			Far = data.Far;
			Fov = data.Fov;
			return *this;
		}
	};
public:
	Camera();
	Camera(const ProjectionData &data);
	Camera(float Fov, float Near, float Far, size_t Wight, size_t Height);
	Camera(float left, float right, float top, float bottom);
	virtual ~Camera();

	kmu::mat4 getCameraMatrix();
	kmu::mat4 &getProjectionMatrix();

public:
	void move(const kmu::vec3 &vec);
	void move(const kmu::vec3 &axis, float len);
	void move(float X, float Y, float Z);

private:
	Projection oProjection;
	ProjectionData oProjData;

	kmu::mat4 *oTransMatrix;
	kmu::mat4 *oProjMatrix;
private:
	bool transChange;
	bool projChange;
};

#endif // !_CAMERA_HPP_
