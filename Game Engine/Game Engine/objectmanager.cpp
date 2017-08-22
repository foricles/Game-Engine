#include "objectmanager.hpp"



ObjectManager::ObjectManager()
	: oQuant(0)
{
}

ObjectManager::~ObjectManager()
{
	for (auto i{ oAllObjects.begin() }; i != oAllObjects.end(); ++i)
		delete *i;
}

GameObject *ObjectManager::getObject()
{
	if (oPool.size() > 0)
	{
		GameObject *obj = oPool.front();
		oPool.pop_front();
		return obj;
	}
	GameObject *gm = new GameObject();
	gm->oId = oQuant++;
	oAllObjects.push_back(gm);
	return gm;
}

void ObjectManager::retObject(GameObject ** obj)
{
	oPool.push_back(*obj);
	*obj = nullptr;
}