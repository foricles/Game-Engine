#include "camera.hpp"

Camera::Camera() : Camera(45, 0.03f, 1000, 1366, 768)
{

}

Camera::Camera(const ProjectionData & data)
{
	oProjData = data;
}

Camera::Camera(float Fov, float Near, float Far, size_t Wight, size_t Height)
	: oPosition(0, 0, 0)
	, oRotation(0, 0, 0, 1)
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
	kmu::vec3 U = oRotation.rotate(VEC3_UP);
	kmu::vec3 F = oRotation.rotate(VEC3_FRONT);

	return kmu::mat4::CameraMatrix(F, U) * kmu::mat4::Translation(-oPosition.x, -oPosition.y, -oPosition.z);
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

const kmu::quaternion & Camera::getRotation()
{
	return oRotation;
}

const kmu::quaternion & Camera::getRotation() const
{
	return oRotation;
}

#pragma region setRotation
void Camera::setRotation(const kmu::quaternion & qua)
{
	oRotation = qua;
}

void Camera::setRotation(const kmu::vec3 axis, float radAngl)
{
	oRotation = kmu::quaternion::euler(radAngl, axis);
}

void Camera::setRotation(float x, float y, float z)
{
}
#pragma endregion

#pragma region Rotate
void Camera::rotate(const kmu::quaternion & qua)
{
	oRotation = oRotation * qua;
}

void Camera::rotate(const kmu::vec3 axis, float radAngl)
{
	oRotation = oRotation * kmu::quaternion::euler(radAngl, axis);
}

void Camera::rotate(float x, float y, float z)
{
}
#pragma endregion

const kmu::vec3 & Camera::getPosition() const
{
	return oPosition;
}

const kmu::vec3 & Camera::getPosition()
{
	return oPosition;
}

void Camera::setPosition(const kmu::vec3 & pos)
{
	oPosition = pos;
}

void Camera::setPosition(float x, float y, float z)
{
	oPosition.set(x, y, z);
}

#pragma region Translate
void Camera::translate(const kmu::vec3 & pos)
{
	oPosition += pos;
}

void Camera::translate(float x, float y, float z)
{
	oPosition += kmu::vec3(x, y, z);
}

void Camera::translate(const kmu::vec3 &axis, float len)
{
	oPosition += axis * len;
}
#pragma endregion

void Camera::move(const kmu::vec3 &vec)
{
	kmu::vec3 U = oRotation.rotate(VEC3_UP);
	kmu::vec3 F = oRotation.rotate(VEC3_FRONT);
	kmu::vec3 R = F.cross(U);

	kmu::vec3 dr = (U * vec.y) + (F * vec.z) + (R * vec.x);
	oPosition += dr;
}

void Camera::move(const kmu::vec3 &axis, float len)
{
	kmu::vec3 U = oRotation.rotate(VEC3_UP);
	kmu::vec3 F = oRotation.rotate(VEC3_FRONT);
	kmu::vec3 R = F.cross(U);

	auto t = axis * len;
	kmu::vec3 dr = (U * t.y) + (F * t.z) + (R * t.x);
	oPosition += dr;
}

void Camera::move(float X, float Y, float Z)
{
	kmu::vec3 U = oRotation.rotate(VEC3_UP);
	kmu::vec3 F = oRotation.rotate(VEC3_FRONT);
	kmu::vec3 R = F.cross(U);

	kmu::vec3 dr = (U * Y) + (F * Z) + (R * X);
	oPosition += dr;
}