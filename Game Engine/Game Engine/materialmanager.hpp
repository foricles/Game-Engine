#ifndef _MATERIALMANAGER_H_
#define _MATERIALMANAGER_H_

#include "objectmanagerbase.hpp"
#include "material.hpp"

class MaterialManager : public ObjectManagerBase<Material>
{
public:
	MaterialManager();
	~MaterialManager();

	Material *findMaterialById(size_t id);
	std::deque<Material*> findMaterialsById(size_t id);

	Material *getDefaultMaterial();
protected:
	virtual Material *newObject() override;
private:
	Material *pDefaultMaterial;
};

#endif // !_MATERIALMANAGER_H_