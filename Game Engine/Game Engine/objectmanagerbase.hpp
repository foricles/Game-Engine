#ifndef _OBJECTMANAGERBASE_H_
#define  _OBJECTMANAGERBASE_H_

#include <deque>
#include <algorithm>
#include <functional>

template < class T > 
class ObjectManagerBase
{
  public:
	ObjectManagerBase();
	virtual ~ ObjectManagerBase();
	
	virtual T *New();
	virtual void Delete(T *&obj);

	T *findObject(std::function<bool(const T&)> predicat);
	std::deque<T*> findObjects(std::function<bool(const T&)> predicat);
	
	int totalObjectsCount() const;
protected:
	virtual T *newObject();
  private:
	std::deque < T* >oObjectList;
	std::deque < T* >oPoolObjects;
};

template<class T>
inline ObjectManagerBase<T>::ObjectManagerBase()
{
}

template < class T >
inline ObjectManagerBase<T>::~ObjectManagerBase()
{
	oPoolObjects.clear();
	for (register int i(0); i < totalObjectsCount(); ++i)
	{
		delete oObjectList[i];
		oObjectList[i] = nullptr;
	}
	oObjectList.clear();
}

template < class T >
inline T *ObjectManagerBase<T>::New()
{
	T *obj = nullptr;
	if (oPoolObjects.size() > 0)
	{
		obj = oPoolObjects.front();
		oPoolObjects.pop_front();
	}
	else
	{
		obj = newObject();
		oObjectList.push_back(obj);
	}
	return obj;
}

template < class T >
inline void ObjectManagerBase<T>::Delete(T *&obj)
{
	auto obj1 = std::find(oPoolObjects.begin(), oPoolObjects.end(), obj);
	auto obj2 = std::find(oObjectList.begin(), oObjectList.end(), obj);

	if ((obj1 == oPoolObjects.end()) && (obj2 != oObjectList.end()))
	{
		oPoolObjects.push_back(obj);
		obj = nullptr;
	}
}

template<class T>
inline T * ObjectManagerBase<T>::findObject(std::function<bool(const T&)> predicat)
{
	T *find = nullptr;
	for (register int i(0); i < totalObjectsCount(); ++i)
	{
		if (predicat(*oObjectList[i]))
		{
			find = oObjectList[i];
			break;
		}
	}
	return find;
}

template<class T>
inline std::deque<T*> ObjectManagerBase<T>::findObjects(std::function<bool(const T&)> predicat)
{
	std::deque<T*> bufer;
	for (register int i(0); i < totalObjectsCount(); ++i)
	{
		if (predicat(*oObjectList[i]))
		{
			bufer.push_back(oObjectList[i]);
		}
	}
	return bufer;
}

template < class T >
inline int ObjectManagerBase<T>::totalObjectsCount() const
{
	return oObjectList.size();
}

template<class T>
inline T * ObjectManagerBase<T>::newObject()
{
	return new T;
}

#endif // _OBJECTMANAGERBASE_H_