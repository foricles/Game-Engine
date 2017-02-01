#include "System.h"


System::System(std::string Name, EngSys engineSystem)
	: BaseObj(Name)
	, m_EngineSystem(engineSystem)
{
}

System::~System()
{
}
