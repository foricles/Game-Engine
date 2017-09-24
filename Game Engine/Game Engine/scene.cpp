#include "scene.hpp"

Scene::Scene(const std::string &sceneName)
	: oSceneName(sceneName)
{
	oObjectManager = new ObjectManager();
	oRender = new Render(oObjectManager);
}

Scene::~Scene()
{
	delete oRender;
	delete oObjectManager;
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
