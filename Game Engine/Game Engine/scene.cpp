#include "scene.hpp"

Scene::Scene(const std::string &sceneName)
	: oSceneName(sceneName)
	, objectManager(   new ObjectManager()   )
	, materialManager( new MaterialManager() )
	, oRender(nullptr)
{
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
