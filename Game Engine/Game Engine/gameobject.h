#ifndef _RENDERMODEL_H_
#define _RENDERMODEL_H_

#include "object.hpp"
#include "mesh.h"
#include "transform.h"
#include "managernode.hpp"

class GameObject : public Object, public Transform, public Node<GameObject>
{
	friend class ObjectManager;
public:
	GameObject();
	virtual ~GameObject();

	Mesh &getMesh();
private:
	Mesh oMesh;
};

#endif // !_RENDERMODEL_H_