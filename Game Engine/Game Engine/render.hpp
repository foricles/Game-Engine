#ifndef _RENDER_HPP_
#define _RENDER_HPP_

#include "camera.hpp"
#include "objectmanager.hpp"

class Render
{
public:
	Render(ObjectManager *manager);
	~Render();
	void draw();

	const Camera *getMainCam() const;
	Camera *getMainCam();
private:
	Camera *oMainCamera;

	GLProgram *oDefaultShader;
	kmu::mat4 *oProjMatrix;
	ObjectManager *oManager;
};

#endif //_RENDER_HPP_