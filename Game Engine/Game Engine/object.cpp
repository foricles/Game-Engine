#include "object.hpp"

size_t Object::oQuant = 0;

Object::Object()
	: oId(++oQuant)
	, oName("Object" + std::to_string(oId))
	, oTag("untagged")
{
}

Object::~Object()
{
}

inline const std::string & Object::getName() const
{
	return oName;
}

inline const std::string & Object::getTag() const
{
	return oTag;
}

inline size_t Object::getId() const
{
	return oId;
}
