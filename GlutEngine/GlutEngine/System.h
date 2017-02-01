#ifndef _SYSTEM_H
#define _SYSTEM_H

#include <string>

#include "../GlutEngine/BaseObj.h"
#include "../GlutEngine/EngSys.h"



class System : protected BaseObj
{
protected:
	EngSys m_EngineSystem;

public:
	System(std::string Name, EngSys engineSystem);
	~System();
};

#endif // !_SYSTEM_H

