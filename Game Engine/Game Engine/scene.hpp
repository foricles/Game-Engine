#ifndef _SCENE_HPP_
#define _SCENE_HPP_

#include "render.hpp"
#include "objectmanager.hpp"
#include "inputmanager.hpp"

class Scene
{
public:
	Scene(const std::string &sceneName);
	virtual ~Scene();
protected:
	InputManager *Input;
	ObjectManager *oObjectManager;
	Camera *getMainCamera();
public:
	virtual void Start();
	virtual void Update();
	virtual void FixedUpdate();
	virtual void LateUpdate();
	virtual void Finish();

	double *deltaTime;
	void drawScene();
	void setInput(InputManager *pInput) { Input = pInput; };
private:
	std::string oSceneName;

	Render *oRender;
};

#endif // !_SCENE_HPP_
