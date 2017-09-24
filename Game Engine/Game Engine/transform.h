#ifndef _TRANSFORM_H_
#define _TRANSFORM_H_

#include <vec3.hpp>
#include <vec4.hpp>
#include <quaternion.hpp>
#include <matrices.hpp>

#include <deque>
#include "object.hpp"

class GameObject;

class Transform
{
public:
	Transform();
	virtual ~Transform();

	kmu::mat4 transMatrix();
	kmu::mat4 selfMatrix();

	void attachToObject(Object *object);
	void setParent(Transform *parent);
	void setChild(Transform *child);

	void setPosition(const kmu::vec3 &pos);
	void setScaling(const kmu::vec3 &scl);
	void setRotation(const kmu::quaternion &rot);

	void setPosition(float X, float Y, float Z);
	void setScaling(float X, float Y, float Z);

	const kmu::vec3 & getPosition() const;
	const kmu::vec3 & getScaling() const;
	const kmu::quaternion &getRotation() const;

	const Transform *getParentTransform();
	const Transform *getParentTransform()const;

	void translate(const kmu::vec3 &dir);
	void translate(float X, float Y, float Z);

	void rotate(float angle, const kmu::vec3 axis);
	void rotate(const kmu::quaternion &quat);
	void rotateX(float angle);
	void rotateY(float angle);
	void rotateZ(float angle);

	void scale(const kmu::vec3 &scl);
	void scale(float X, float Y, float Z);

	GameObject *gameObject() { return (GameObject*)oObject; }

	//?????????
	size_t getObjectId() { if (oObject == nullptr) return 0; else return oObject->getId(); }
private:
	Object *oObject;

	kmu::vec3 oPos;
	kmu::vec3 oScl;
	kmu::quaternion oRot;

	Transform *oParent;
	std::deque <Transform*>oChildren;

};

#endif // !_TRANSFORM_H_