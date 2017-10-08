#include "render.hpp"


Render::Render(ObjectManager *manager)
	: oManager(manager)
{
	oDefaultMaterial = new Material();
	oDefaultMaterial->getProgram().begin();
	oDefaultMaterial->getProgram().addShader(SHADER::VERTEX, "D:\\Work\\projects\\cpp\\Game-Engine\\Game Engine\\shader\\vrt.vrt");
	oDefaultMaterial->getProgram().addShader(SHADER::FRAGMENT, "D:\\Work\\projects\\cpp\\Game-Engine\\Game Engine\\shader\\frg.frg");
	//oDefaultMaterial->getProgram().addShader(SHADER::VERTEX, "resurses\\shader\\vrt.vrt");
	//oDefaultMaterial->getProgram().addShader(SHADER::FRAGMENT, "resurses\\shader\\frg.frg");
	oDefaultMaterial->getProgram().end();

	oDefaultMaterial->loadTexture("resurses\\box.png");

	oProjMatrix = new kmu::mat4(1);
	*oProjMatrix = kmu::mat4::Perspective(45, 640, 480, 0.03, 1000);

	oMainCamera = new Camera();
	oMainCamera->translate(0, 0, -20);
}

Render::~Render()
{
	delete oDefaultMaterial;
	delete oProjMatrix;
	delete oMainCamera;
}

void Render::draw()
{
	static float time = 0;
	time += 0.01;
	RenderData renderData;
	oManager->getRenderData(&renderData);
	renderData.SortByMaterial();

	oDefaultMaterial->bind();
	oDefaultMaterial->setParametr("worldMatrix", *oProjMatrix);
	oDefaultMaterial->setParametr("camMatrix", oMainCamera->getCameraMatrix());
	oDefaultMaterial->setParametr("gSampler", 0);

	for (register auto obj = renderData.oData.begin(); obj != renderData.oData.end(); ++obj)
	{
		glBindVertexArray(obj->vao);
		oDefaultMaterial->setParametr("selfMatrix", obj->matrix);
		glDrawElements(GL_TRIANGLES, obj->count, GL_UNSIGNED_INT, nullptr);
		//glBindBuffer(GL_ARRAY_BUFFER, 0);
		glBindVertexArray(0);
	}

	oDefaultMaterial->unbind();
}

const Camera * Render::getMainCam() const
{
	return oMainCamera;
}

Camera * Render::getMainCam()
{
	return oMainCamera;
}
