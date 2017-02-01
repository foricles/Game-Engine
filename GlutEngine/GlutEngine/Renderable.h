#ifndef _RENDERABLE_H
#define _RENDERABLE_H

#include <string>

#include "../GlutEngine/BaseObj.h"
#include "../GlutEngine/Tags.h"

class Renderable : public BaseObj
{
public:
	Renderable();
	Renderable(Tags, unsigned int layer);
	Renderable(std::string name);
	Renderable(std::string name, Tags, unsigned int layer);
	virtual ~Renderable();
	
	void setLayer(unsigned int newLayer);

	Tags getTag();
	unsigned int getLayer();
private:
	Tags m_Tag;
	unsigned int m_Layer;
};


#endif // !_RENDERABLE_H

