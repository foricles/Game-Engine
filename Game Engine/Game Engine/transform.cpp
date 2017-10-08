#include "transform.h"



Transform::Transform()
	: oPos(0, 0, 0)
	, oScl(1, 1, 1)
	, oRot(0, 0, 0, 1)
	, oParent(nullptr)
	, oObject(nullptr)
{
}


Transform::~Transform()
{
}

kmu::mat4 Transform::transMatrix()
{
	if (oParent == nullptr)
		return selfMatrix();
	else
		return oParent->transMatrix() * selfMatrix();
}

kmu::mat4 Transform::selfMatrix()
{
	oRot.normalize();
	kmu::mat4 trm(kmu::mat4::Translation(oPos.x, oPos.y, oPos.z));
	kmu::mat4 slm(kmu::mat4::Scaling(oScl.x, oScl.y, oScl.z));
	kmu::mat4 rtm(kmu::mat4::Rotation(oRot));

	return trm * (rtm * slm);
}

void Transform::attachToObject(Object * object)
{
	oObject = object;
}

void Transform::setParent(Transform *parent)
{
	if (parent != nullptr)
	{
		if (parent != this)
		{
			std::deque<Transform*> & pChildren = parent->oChildren;

			for (auto it = pChildren.begin(); it != pChildren.end(); ++it)
			{
				if (parent == (*it))
				{
					pChildren.erase(it);
					break;
				}
			}

			pChildren.push_back(this);
			oParent = parent;
		}
		else
		{
			Logger::Log("Try to attach self as parent: " + oObject->getName(), LogType::ATTMP);
		}
	}
}

void Transform::setChild(Transform * child)
{
	if (child != nullptr)
	{
		if (child != this)
		{
			bool contain = false;
			for (auto it = oChildren.begin(); it != oChildren.end(); ++it)
			{
				if (child == (*it))
				{
					contain = true;
				}
			}

			if (!contain)
			{
				oChildren.push_back(child);
				child->oParent = this;
			}
		}
		else
		{
			Logger::Log("Try to attach self as children: " + oObject->getName(), LogType::ATTMP);
		}
	}
}

void Transform::setPosition(const kmu::vec3 &pos)
{
	oPos = pos;
}
void Transform::setScaling(const kmu::vec3 &scl)
{
	oScl = scl;
}
void Transform::setRotation(const kmu::quaternion &rot) 
{
	oRot = rot; 
	oRot.normalize();
}

void Transform::setPosition(float X, float Y, float Z)
{
	oPos = kmu::vec3(X, Y, Z);
}
void Transform::setScaling(float X, float Y, float Z) 
{
	oScl = kmu::vec3(X, Y, Z);
}

const kmu::vec3 & Transform::getPosition() const
{
	return oPos;
}
const kmu::vec3 & Transform::getScaling() const
{
	return oScl;
}
const kmu::quaternion &Transform::getRotation() const
{
	return oRot;
}

const Transform * Transform::getParentTransform()
{
	return oParent;
}

const Transform * Transform::getParentTransform() const
{
	return oParent;
}

void Transform::translate(const kmu::vec3 & dir)
{
	oPos += dir;
}

void Transform::translate(float X, float Y, float Z)
{
	oPos += kmu::vec3(X, Y, Z);
}

void Transform::rotate(float angle, const kmu::vec3 axis)
{
	oRot = oRot * kmu::quaternion::euler(angle, axis);
}

void Transform::rotate(const kmu::quaternion &quat)
{
	oRot = oRot * quat;
}