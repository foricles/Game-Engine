#ifndef _RENDERMODEL_H_
#define _RENDERMODEL_H_

#include <deque>

#include "mesh.h"
#include "transform.h"

class GameObject
{
	friend class ObjectManager;
public:
	GameObject();
	virtual ~GameObject();

	Transform &transform();
	kmu::mat4 transMatrix();
private:
	size_t oId;
	Transform oTransform;
	Mesh oMesh;
	GameObject *oParent;
	std::deque <GameObject*>oChildren;
};

#endif // !_RENDERMODEL_H_