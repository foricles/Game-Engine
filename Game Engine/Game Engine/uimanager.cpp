#include "uimanager.hpp"

UIManager::UIManager()
{
	
}

UIManager::~UIManager()
{
	for (auto it = uiObjArray.begin(); it != uiObjArray.end(); ++it)
	{
		UIObject *tmp = *it;
		if (tmp)
		{
			delete tmp;
			tmp = nullptr;
		}
	}
}

void UIManager::releseObject(UIObject *& uio)
{
	std::deque<UIObject *>::iterator elem = std::find(std::begin(uiObjArray), std::end(uiObjArray), uio);
	if (elem != std::end(uiObjArray))
	{
		uiObjArray.erase(elem);
		delete uio;
		uio = nullptr;
	}
}

inline void UIManager::getRenderDataArray(std::vector<vertex>& renderedData) const
{
	renderedData.reserve(uiObjArray.size * 6);
}

template<class T>
inline T * UIManager::getUIObject()
{
	T *temp = new T;

	uiObjArray.push_back(temp);

	return temp;
}

bool UIManager::depthCmp(const UIObject & f, const UIObject & s)
{
	return f.getGlobalPosition().z > s.getGlobalPosition().z;
}
