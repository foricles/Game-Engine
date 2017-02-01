#include "Renderable.h"

Renderable::Renderable()
	: BaseObj()
	, m_Layer(0)
	, m_Tag(Tags::NONTAG)
{
}

Renderable::Renderable(Tags tag, unsigned int layer)
	: BaseObj()
	, m_Layer(layer)
	, m_Tag(tag)
{
}

Renderable::Renderable(std::string name)
	: BaseObj(name)
{
}

Renderable::Renderable(std::string name, Tags tag, unsigned int layer)
	: BaseObj(name)
	, m_Layer(layer)
	, m_Tag(tag)
{
}

Renderable::~Renderable()
{
}

void Renderable::setLayer(unsigned int newLayer)
{
	m_Layer = newLayer;
}

Tags Renderable::getTag()
{
	return m_Tag;
}

unsigned int Renderable::getLayer()
{
	return m_Layer;
}
