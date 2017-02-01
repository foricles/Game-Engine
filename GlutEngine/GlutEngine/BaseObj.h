#ifndef _BASE_OBJ
#define _BASE_OBJ

#include <string>

class BaseObj
{
protected:
	static int m_Count;
	int m_Id;
	std::string m_Name;
private:
	
public:
	BaseObj();
	BaseObj(std::string Name);
	BaseObj(const BaseObj &baseObj);
	virtual ~BaseObj();

	int getId();
	std::string getName();
};


#endif // !_BASE_OBJ

