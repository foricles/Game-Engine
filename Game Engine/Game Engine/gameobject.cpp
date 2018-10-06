#include "gameobject.h"


GameObject::GameObject()
	: oMesh(nullptr)
{
	oName = "GameObject" + std::to_string(oId);
	oMesh = new Mesh;
}

GameObject::~GameObject()
{
	delete oMesh;
}

Mesh *GameObject::getMesh()
{
	return oMesh;
}