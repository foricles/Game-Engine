#include "camera.hpp"

Camera::Camera() : Camera(MY_PI/4, 0.03f, 1000, 1920, 1080)
{

}

Camera::Camera(const ProjectionData & data)
{
	oProjData = data;
}

Camera::Camera(float Fov, float Near, float Far, size_t Wight, size_t Height)
	: Transform()
	, oProjection(Projection::PERSPECTIVE)
	, oTransMatrix(new kmu::mat4())
	, oProjMatrix(new kmu::mat4())
	, transChange(true)
	, projChange(true)
{
	oProjData.Wight = Wight;
	oProjData.Height = Height;
	oProjData.Far = Far;
	oProjData.Near = Near;
	oProjData.Fov = Fov;
}

Camera::Camera(float left, float right, float top, float bottom)
{
}

Camera::~Camera()
{
	delete oTransMatrix;
	delete oProjMatrix;
}

kmu::mat4 Camera::getCameraMatrix()
{
	kmu::vec3 U = oRot.rotate(VEC3_UP);
	kmu::vec3 F = oRot.rotate(VEC3_FRONT);

	return kmu::mat4::CameraMatrix(F, U) * kmu::mat4::Translation(-oPos.x, -oPos.y, -oPos.z);
}

kmu::mat4 &Camera::getProjectionMatrix()
{
	switch (oProjection)
	{
	case Projection::PERSPECTIVE:
		if (projChange)
		{
			*oProjMatrix = kmu::mat4::Perspective(oProjData.Fov,
				oProjData.Wight,
				oProjData.Height,
				oProjData.Near,
				oProjData.Far);
			projChange = false;
		}
		break;
	case Projection::ORTHOGRAPHIC:
		break;
	}
	return *oProjMatrix;
}

void Camera::move(const kmu::vec3 &vec)
{
	kmu::vec3 U = oRot.rotate(VEC3_UP);
	kmu::vec3 F = oRot.rotate(VEC3_FRONT);
	kmu::vec3 R = F.cross(U);

	kmu::vec3 dr = (U * vec.y) + (F * vec.z) + (R * vec.x);
	oPos += dr;
}

void Camera::move(const kmu::vec3 &axis, float len)
{
	kmu::vec3 U = oRot.rotate(VEC3_UP);
	kmu::vec3 F = oRot.rotate(VEC3_FRONT);
	kmu::vec3 R = F.cross(U);

	auto t = axis * len;
	kmu::vec3 dr = (U * t.y) + (F * t.z) + (R * t.x);
	oPos += dr;
}

void Camera::move(float X, float Y, float Z)
{
	kmu::vec3 U = oRot.rotate(VEC3_UP);
	kmu::vec3 F = oRot.rotate(VEC3_FRONT);
	kmu::vec3 R = F.cross(U);

	kmu::vec3 dr = (U * Y) + (F * Z) + (R * X);
	oPos += dr;
}