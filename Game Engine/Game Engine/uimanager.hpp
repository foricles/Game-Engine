#ifndef _UIMANAGER_HPP_
#define _UIMANAGER_HPP_

#include "uiobject.hpp"
#include <deque>

#define MAX_UI_OBJECTS 1024

class UIManager
{
public:
	UIManager();
	virtual ~UIManager();

	template<class T>
	T * getUIObject();

	void releseObject(UIObject *& uio);

	inline void getRenderDataArray(std::vector<vertex> &renderedData) const;
private:
	std::deque<UIObject*> uiObjArray;
private:
	static bool depthCmp(const UIObject &f, const UIObject &s);
};

#endif // !_UIMANAGER_HPP_
