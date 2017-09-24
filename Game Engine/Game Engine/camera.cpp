#include "camera.hpp"

Camera::Camera() : Camera(65, 0.03f, 1000.0f, 800, 600)
{

}

Camera::Camera(const ProjectionData & data)
{
	oProjData = data;
}

Camera::Camera(float Fov, float Near, float Far, size_t Wight, size_t Height)
	: oPosition(0, 0, 0)
	, oRotation(0, 0, 0, 1)
	, oProjMatrix()
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
}

kmu::mat4 Camera::getMatrix()
{
	kmu::vec3 U = oRotation.rotate(VEC3_UP);
	kmu::vec3 F = oRotation.rotate(VEC3_FRONT);

	return kmu::mat4::CameraMatrix(F, U) * kmu::mat4::Translation(-oPosition.x, -oPosition.y, -oPosition.z);
}

const kmu::quaternion & Camera::getRotation()
{
	return oRotation;
}

const kmu::quaternion & Camera::getRotation() const
{
	return oRotation;
}

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

void Camera::translate(const kmu::vec3 & pos)
{
	oPosition += pos;
}

void Camera::translate(float x, float y, float z)
{
	oPosition += kmu::vec3(x, y, z);
}
