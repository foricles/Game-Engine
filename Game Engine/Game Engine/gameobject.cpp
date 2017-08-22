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

kmu::mat4 GameObject::transMatrix()
{
	return oTransform.transMatrix();
}