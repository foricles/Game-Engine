#ifndef _OBJECTMANAGER_H_
#define _OBJECTMANAGER_H_

#include "gameobject.h"

class ObjectManager
{
  public:
	ObjectManager();
	~ObjectManager();

	GameObject *getObject();
	void retObject(GameObject ** obj);

	GameObject *findAllById(int id);
	GameObject *findActiveById(int id);
  private:
	size_t oQuant;
	std::deque <GameObject*>oPool;
	std::deque <GameObject*>oAllObjects;
};

#endif // _OBJECTMANAGER_H_