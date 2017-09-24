#ifndef _RENDERMODEL_H_
#define _RENDERMODEL_H_

#include "object.hpp"
#include "mesh.h"
#include "transform.h"

class GameObject : public Object
{
	friend class ObjectManager;
public:
	GameObject();
	virtual ~GameObject();

	Transform &transform();
	Mesh &getMesh();

	kmu::mat4 transMatrix();

	GameObject *findObjectInChildren(size_t id);
	GameObject *findObjectInChildren(const std::string &name);

	std::vector<GameObject*> findObjectsInChildren(const std::string &name);

	GameObject *getParent();
private:
	Transform oTransform;
	Mesh oMesh;
};

#endif // !_RENDERMODEL_H_