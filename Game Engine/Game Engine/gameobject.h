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
	Mesh &getMesh();
	kmu::mat4 transMatrix();

	GameObject *findObjectInChildren(size_t id);
	GameObject *findObjectInChildren(const std::string &name);

	std::vector<GameObject*> findObjectsInChildren(const std::string &name);

	GameObject *getParent();

protected:
	virtual void update();
private:
	size_t oId;
	Transform oTransform;
	Mesh oMesh;

	GameObject *oParent;
	std::deque <GameObject*>oChildren;
private:
	void notify();
};

#endif // !_RENDERMODEL_H_