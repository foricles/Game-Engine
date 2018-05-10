#ifndef _RENDER_HPP_
#define _RENDER_HPP_

#include "camera.hpp"
#include "material.hpp"
#include "objectmanager.hpp"
#include "materialmanager.hpp"
#include "skybox.hpp"

//TODO: make light manager
#include "directlight.hpp"

class Render
{
public:
	//TODO: with light manager
	Render(ObjectManager *manager, MaterialManager *matManager, DirectionalLight *light, SkyBox *skybox = nullptr);
	~Render();
	void draw();

	const Camera *getMainCam() const;
	Camera *getMainCam();
	void setSkybox(SkyBox * skyBox);
private:
	Camera *oMainCamera;
	ObjectManager &oObjManager;
	MaterialManager &oMatManager;
	DirectionalLight &oLight;
	SkyBox *oSkybox;
private:
	int oCurrentMaterial;
};

#endif //_RENDER_HPP_