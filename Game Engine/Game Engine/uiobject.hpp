#ifndef _UIOBJECT_HPP_
#define _UIOBJECT_HPP_

#include "object.hpp"
#include "vertexdata.hpp"
#include "uitransform.hpp"

class UIObject : public Object, public UITransform
{
public:
	UIObject();
	virtual ~UIObject();

	MeshData getRenderData() const;
};

#endif // !_UIOBJECT_HPP_
