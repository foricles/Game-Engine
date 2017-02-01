#include "BaseObj.h"

int BaseObj::m_Count = 0;

BaseObj::BaseObj()
{
	m_Name = "BaseObject" + std::to_string(m_Id);
	m_Id = m_Count;
	m_Count++;
}

BaseObj::BaseObj(std::string Name)
{
	m_Name = Name;
	m_Id = m_Count;
	m_Count++;
}

BaseObj::BaseObj(const BaseObj &baseObj)
{
	m_Id = m_Count;
	m_Count++;

	m_Name = baseObj.m_Name;
}

BaseObj::~BaseObj()
{
	
}



int BaseObj::getId()
{
	return m_Id;
}

std::string BaseObj::getName()
{
	return m_Name;
}
