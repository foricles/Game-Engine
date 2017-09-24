#ifndef _OBJECT_HPP_
#define _OBJECT_HPP_

#include <string>
#include "Logger.h"

class Object
{
public:
	Object();
	virtual ~Object();

	virtual inline const std::string &getName()const;
	virtual inline const std::string &getTag()const;
	virtual inline size_t getId()const;

protected:
	std::string oName;
	std::string oTag;
	size_t oId;
private:
	static size_t oQuant;
};

#endif // !_OBJECT_HPP_