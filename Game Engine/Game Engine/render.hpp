#ifndef _RENDER_HPP_
#define _RENDER_HPP_

#include "camera.hpp"
#include "material.hpp"
#include "objectmanager.hpp"
#include "materialmanager.hpp"

class Render
{
public:
	Render(ObjectManager *manager, MaterialManager *matManager);
	~Render();
	void draw();

	const Camera *getMainCam() const;
	Camera *getMainCam();
private:
	Camera *oMainCamera;
	ObjectManager &oObjManager;
	MaterialManager &oMatManager;
private:
	int oCurrentMaterial;
};

#endif //_RENDER_HPP_