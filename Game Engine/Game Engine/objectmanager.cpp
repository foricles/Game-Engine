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

void ObjectManager::getRenderData(RenderData *renderData)
{
	renderData->oData.resize(oAllObjects.size());
	int i(0);
	for (register auto obj = oAllObjects.begin(); obj != oAllObjects.end(); obj++)
	{
		renderData->oData[i].vao		= (*obj)->getMesh().vaoId();
		renderData->oData[i].count		= (*obj)->getMesh().getIndexCount();
		renderData->oData[i].matrix		= (*obj)->globalMatrix();
		renderData->oData[i].material	= (*obj)->getMesh().getMaterialId();
		i++;
	}
	
}
