#include "gameobject.h"


GameObject::GameObject()
{
	oName = "GameObject" + std::to_string(oId);
	oTransform.attachToObject(this);
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

GameObject * GameObject::findObjectInChildren(size_t id)
{
	//TODO
	return nullptr;
}

GameObject * GameObject::findObjectInChildren(const std::string & name)
{
	//TODO
	return nullptr;
}

std::vector<GameObject*> GameObject::findObjectsInChildren(const std::string & name)
{
	return std::vector<GameObject*>();
}

GameObject * GameObject::getParent()
{
	//TODO
	auto pTrans = this->oTransform.getParentTransform();

	//pTrans->

	return nullptr;
}
