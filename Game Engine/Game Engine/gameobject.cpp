#include "gameobject.h"


GameObject::GameObject()
{
	oName = "GameObject" + std::to_string(oId);
}

GameObject::~GameObject()
{
	
}

Mesh & GameObject::getMesh()
{
	return oMesh;
}