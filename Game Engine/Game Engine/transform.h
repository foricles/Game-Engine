#ifndef _TRANSFORM_H_
#define _TRANSFORM_H_

#include <vec3.hpp>
#include <vec4.hpp>
#include <quaternion.hpp>
#include <matrices.hpp>

#include <deque>

#include "Logger.h"

class Transform
{
public:
	Transform();
	virtual ~Transform();

	kmu::mat4 globalMatrix();
	kmu::mat4 localMatrix();

	void setParent(Transform *parent);
	void setChild(Transform *child);

	void setPosition(const kmu::vec3 &pos);
	void setPosition(float X, float Y, float Z);

	void setScale(const kmu::vec3 &scl);
	void setScale(float X, float Y, float Z);

	void setRotation(const kmu::quaternion &rot);
	
	const kmu::vec3 & getLocalPosition() const;
	const kmu::quaternion &getLocalRotation() const;

	const kmu::vec3 getGlobalPosition() const;
	const kmu::quaternion getGlobalRotation() const;

	const kmu::vec3 & getScaling() const;

	void translate(const kmu::vec3 &dir);
	void translate(float X, float Y, float Z);

	void rotate(float angle, const kmu::vec3 axis);
	void rotate(const kmu::quaternion &quat);

	kmu::vec3 transformDirection(const kmu::vec3 &dir);
protected:
	kmu::vec3 oPos;
	kmu::vec3 oScl;
	kmu::quaternion oRot;
private:
	Transform *oParent;
	std::deque <Transform*>oChildren;

};

#endif // !_TRANSFORM_H_