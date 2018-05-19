#include "objectmanager.hpp"



ObjectManager::ObjectManager()
{
}

ObjectManager::~ObjectManager()
{
	for (auto i{ oAllObjects.begin() }; i != oAllObjects.end(); ++i)
	{
		delete *i;
	}
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

	oAllObjects.push_back(gm);
	return gm;
}

void ObjectManager::retObject(GameObject ** obj)
{
	oPool.push_back(*obj);
	*obj = nullptr;
}

const std::deque<GameObject*>& ObjectManager::getRenderObjects() const
{
	return oAllObjects;
}
