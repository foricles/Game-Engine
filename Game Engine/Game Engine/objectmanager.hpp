#ifndef _OBJECTMANAGER_H_
#define _OBJECTMANAGER_H_

#include "gameobject.h"

class RenderData
{
public:
	struct Data
	{
		GLuint vao;
		GLuint vbo;
		GLuint ibo;
		GLuint material;
		size_t count;
		kmu::mat4 matrix;
	};
	std::vector<Data> oData;



	inline void SortByMaterial()
	{
		std::stable_sort(oData.begin(), oData.end(), cmp);
	}
private:
	inline static bool cmp(const RenderData::Data &d1, const RenderData::Data &d2)
	{
		return d1.material < d2.material;
	}
};

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

	void getRenderData(RenderData *renderData);
  private:
	std::deque <GameObject*>oPool;
	std::deque <GameObject*>oAllObjects;
};

#endif // _OBJECTMANAGER_H_