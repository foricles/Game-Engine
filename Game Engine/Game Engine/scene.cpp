#include "scene.hpp"

Scene::Scene(const std::string &sceneName)
	: oSceneName(sceneName)
	, materialManager(nullptr)
	, objectManager(nullptr)
	, oRender(nullptr)
	, deltaTime(1)
{
	materialManager = new MaterialManager();
	objectManager = new ObjectManager();
	oRender = new Render(objectManager, materialManager, &oLight);
}

Scene::~Scene()
{
	delete oRender;
	delete objectManager;
	delete materialManager;
}

void Scene::drawScene()
{
	oRender->draw();
}

Camera * Scene::getMainCamera()
{
	return oRender->getMainCam();
}

SkyBox *Scene::customizeSkybox()
{
	return oRender->customizeSkybox();
}

void Scene::Start()
{
}

void Scene::Update()
{
}

void Scene::FixedUpdate()
{
}

void Scene::LateUpdate()
{
}

void Scene::Finish()
{
}
