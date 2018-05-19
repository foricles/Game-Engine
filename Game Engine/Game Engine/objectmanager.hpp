#ifndef _OBJECTMANAGER_H_
#define _OBJECTMANAGER_H_

#include "gameobject.h"

class ObjectManager
{
	friend class Render;
  public:
	ObjectManager();
	~ObjectManager();

	GameObject *getObject();
	void retObject(GameObject **obj);

	GameObject *findAllGameObject(int id);
	GameObject *findAllGameObject(const  std::string &name);

	GameObject *findActiveGameObject(int id);
	GameObject *findActiveGameObject(const std::string &name);

	std::vector<GameObject*> findAllGameObjects(const std::string &name);
	std::vector<GameObject*> findActiveGameObjects(const std::string &name);

	const std::deque<GameObject*> &getRenderObjects() const;
  private:
	std::deque <GameObject*>oPool;
	std::deque <GameObject*>oAllObjects;
};

#endif // _OBJECTMANAGER_H_