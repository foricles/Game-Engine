#include "gameobject.h"


GameObject::GameObject()
{
	
}

GameObject::~GameObject()
{
	
}

Transform &GameObject::transform()
{
	return oTransform;
}

Mesh & GameObject::getMesh()
{
	return oMesh;
}

kmu::mat4 GameObject::transMatrix()
{
	return oTransform.transMatrix();
}

void GameObject::update()
{
}

void GameObject::notify()
{
	for (auto it{ oChildren.begin() }; it != oChildren.end(); ++it)
		(*it)->update();
}
