#ifndef _CAMERA_HPP_
#define _CAMERA_HPP_

#include "transform.h"

enum class Projection
{
	PERSPECTIVE,
	ORTHOGRAPHIC
};

class Camera
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
	const kmu::quaternion &getRotation();
	const kmu::quaternion &getRotation() const;
public:
	const kmu::vec3 &getPosition();
	const kmu::vec3 &getPosition() const;
public:
	void setRotation(const kmu::quaternion &qua);
	void setRotation(const kmu::vec3 axis, float radAngl);
	void setRotation(float x, float y, float z);
public:
	void rotate(const kmu::quaternion &qua);
	void rotate(const kmu::vec3 axis, float radAngl);
	void rotate(float x, float y, float z);
public:
	void translate(const kmu::vec3 &pos);
	void translate(float x, float y, float z);
	void translate(const kmu::vec3 &axis, float len);
public:
	void setPosition(const kmu::vec3 &pos);
	void setPosition(float x, float y, float z);
public:
	void move(const kmu::vec3 &vec);
	void move(const kmu::vec3 &axis, float len);
	void move(float X, float Y, float Z);

private:
	Projection oProjection;
	ProjectionData oProjData;

	kmu::vec3 oPosition;
	kmu::quaternion oRotation;

	kmu::mat4 *oTransMatrix;
	kmu::mat4 *oProjMatrix;
private:
	bool transChange;
	bool projChange;
};

#endif // !_CAMERA_HPP_
