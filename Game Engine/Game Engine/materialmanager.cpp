#include "materialmanager.hpp"


MaterialManager::MaterialManager()
	: pDefaultMaterial(nullptr)
{
	pDefaultMaterial = this->New();
	pDefaultMaterial->getProgram().begin();
	//oDefaultMaterial->getProgram().addShader(SHADER::VERTEX, "D:\\Work\\projects\\cpp\\Game-Engine\\Game Engine\\shader\\vrt.vrt");
	//oDefaultMaterial->getProgram().addShader(SHADER::FRAGMENT, "D:\\Work\\projects\\cpp\\Game-Engine\\Game Engine\\shader\\frg.frg");
	pDefaultMaterial->getProgram().addShader(SHADER::VERTEX, "resurses\\shader\\vrt.vrt");
	pDefaultMaterial->getProgram().addShader(SHADER::FRAGMENT, "resurses\\shader\\frg.frg");
	pDefaultMaterial->loadTexture("resurses\\textures\\Grass1.png");
	pDefaultMaterial->getProgram().end();
}

MaterialManager::~MaterialManager()
{
}

Material * MaterialManager::findMaterialById(size_t id)
{
	return this->findObject([id](const Material &mat) {return mat.getMaterialId() == id; });
}

std::deque<Material*> MaterialManager::findMaterialsById(size_t id)
{
	return this->findObjects([id](const Material &mat) {return mat.getMaterialId() == id; });
}

Material * MaterialManager::getDefaultMaterial()
{
	return pDefaultMaterial;
}

Material * MaterialManager::newObject()
{
	Material *material = new Material;
	material->setId(this->totalObjectsCount() + 1);
	return material;
}
