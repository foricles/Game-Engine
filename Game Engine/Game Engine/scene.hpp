#ifndef _SCENE_HPP_
#define _SCENE_HPP_

#include "render.hpp"
#include "objectmanager.hpp"
#include "materialmanager.hpp"
#include "inputmanager.hpp"
#include "window.h"
#include "directlight.hpp"

class Scene
{
	friend class Application;
public:
	Scene(const std::string &sceneName);
	virtual ~Scene();
protected:
	InputManager *Input;
	Camera *getMainCamera();
	Window *window;

	SkyBox *customizeSkybox();
protected:
	MaterialManager *materialManager;
	ObjectManager *objectManager;
	DirectionalLight oLight;
public:
	virtual void Start();
	virtual void Update();
	virtual void FixedUpdate();
	virtual void LateUpdate();
	virtual void Finish();

	double deltaTime;
	void drawScene();
private:
	void setInput(InputManager *pInput) { Input = pInput; };
	void setWindow(Window *pWindow) { window = pWindow; };
private:
	std::string oSceneName;
	Render *oRender;
};

#endif // !_SCENE_HPP_
