#ifndef _SKYBOX_HPP_
#define _SKYBOX_HPP_

#include "opengl.h"
#include "cubemap.hpp"
#include "material.hpp"
#include <vec3.hpp>
#include <matrices.hpp>

class SkyBox
{
public:
	SkyBox();
	virtual ~SkyBox();

	virtual void setSkyCubemap(CubeMap *map);
	virtual void drawSky(kmu::mat4 &camMatrix, kmu::mat4 &worldMatrix);
private:
	GLuint vboID;
	Material *skyBoxMaterial;
};

#endif // !_SKYBOX_HPP_
