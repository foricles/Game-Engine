#include "skybox.hpp"

SkyBox::SkyBox()
	: vboID(0)
	, skyBoxMaterial(nullptr)
{
	float SIZE = 1;
	float skyboxVertices[] = 
	{
		-SIZE,  SIZE, -SIZE,
		-SIZE, -SIZE, -SIZE,
		SIZE, -SIZE, -SIZE,
		SIZE, -SIZE, -SIZE,
		SIZE,  SIZE, -SIZE,
		-SIZE,  SIZE, -SIZE,

		-SIZE, -SIZE,  SIZE,
		-SIZE, -SIZE, -SIZE,
		-SIZE,  SIZE, -SIZE,
		-SIZE,  SIZE, -SIZE,
		-SIZE,  SIZE,  SIZE,
		-SIZE, -SIZE,  SIZE,

		SIZE, -SIZE, -SIZE,
		SIZE, -SIZE,  SIZE,
		SIZE,  SIZE,  SIZE,
		SIZE,  SIZE,  SIZE,
		SIZE,  SIZE, -SIZE,
		SIZE, -SIZE, -SIZE,

		-SIZE, -SIZE,  SIZE,
		-SIZE,  SIZE,  SIZE,
		SIZE,  SIZE,  SIZE,
		SIZE,  SIZE,  SIZE,
		SIZE, -SIZE,  SIZE,
		-SIZE, -SIZE,  SIZE,

		-SIZE,  SIZE, -SIZE,
		SIZE,  SIZE, -SIZE,
		SIZE,  SIZE,  SIZE,
		SIZE,  SIZE,  SIZE,
		-SIZE,  SIZE,  SIZE,
		-SIZE,  SIZE, -SIZE,

		-SIZE, -SIZE, -SIZE,
		-SIZE, -SIZE,  SIZE,
		SIZE, -SIZE, -SIZE,
		SIZE, -SIZE, -SIZE,
		-SIZE, -SIZE,  SIZE,
		SIZE, -SIZE,  SIZE
	};

	glGenBuffers(1, &vboID);
	glBindBuffer(GL_ARRAY_BUFFER, vboID);
	glBufferData(GL_ARRAY_BUFFER, sizeof(skyboxVertices), skyboxVertices, GL_STATIC_DRAW);
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	skyBoxMaterial = new Material;
	skyBoxMaterial->getProgram().begin();
	skyBoxMaterial->getProgram().addShader(SHADER::VERTEX, "resources\\shader\\skybox\\sky_vrt.vrt");
	skyBoxMaterial->getProgram().addShader(SHADER::FRAGMENT, "resources\\shader\\skybox\\sky_frg.frg");
	skyBoxMaterial->getProgram().end();
}

SkyBox::~SkyBox()
{
	glDeleteBuffers(1, &vboID);
	delete skyBoxMaterial;
}

void SkyBox::setSkyCubemap(CubeMap * map)
{
	map->setSampleName("gSkySampler");
	skyBoxMaterial->addTextureAsParametr(map);
}

void SkyBox::drawSky(kmu::mat4 & camMatrix, kmu::mat4 & worldMatrix)
{
	GLint OldCullFaceMode;
	glGetIntegerv(GL_CULL_FACE_MODE, &OldCullFaceMode);
	GLint OldDepthFuncMode;
	glGetIntegerv(GL_DEPTH_FUNC, &OldDepthFuncMode);

	glCullFace(GL_FRONT);
	glDepthFunc(GL_LEQUAL);

	glBindBuffer(GL_ARRAY_BUFFER, vboID);
	skyBoxMaterial->bind();

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_TRUE, sizeof(float) * 3, 0);
	glEnableVertexAttribArray(0);

	skyBoxMaterial->setParametr("camMatrix", camMatrix);
	skyBoxMaterial->setParametr("worldMatrix", worldMatrix);
	skyBoxMaterial->setTexturesSamples();

	glDrawArrays(GL_TRIANGLES, 0, 36);
	glDisableVertexAttribArray(0);

	skyBoxMaterial->unbind();
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	glCullFace(OldCullFaceMode);
	glDepthFunc(OldDepthFuncMode);
	Logger::CheckGLErrors("SkyBox::drawSky");
}
