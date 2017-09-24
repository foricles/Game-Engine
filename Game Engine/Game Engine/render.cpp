#include "render.hpp"


Render::Render(ObjectManager *manager)
	: oManager(manager)
{
	oDefaultShader = new GLProgram();
	oDefaultShader->begin();
	oDefaultShader->addShader(SHADER::VERTEX, "D:\\Work\\projects\\cpp\\Game-Engine\\Game Engine\\shader\\vrt.vrt");
	oDefaultShader->addShader(SHADER::FRAGMENT, "D:\\Work\\projects\\cpp\\Game-Engine\\Game Engine\\shader\\frg.frg");
	oDefaultShader->end();

	oProjMatrix = new kmu::mat4(1);
	*oProjMatrix = kmu::mat4::Perspective(45, 860, 640, 0.03, 1000);
	//*oWorldMatrix *= kmu::mat4::Translation(0, 0, 3.5);

	oMainCamera = new Camera();
	oMainCamera->translate(0, 0, -20);
}

Render::~Render()
{
	delete oDefaultShader;
	delete oProjMatrix;
	delete oMainCamera;
}

void Render::draw()
{
	oMainCamera->rotate(VEC3_RIGHT, 0.00001f);

	RenderData renderData;
	oManager->getRenderData(&renderData);
	renderData.SortByMaterial();

	auto matx = oMainCamera->getMatrix();

	oDefaultShader->bind();
	glUniformMatrix4fv(oDefaultShader->getUniform("worldMatrix"), 1, GL_TRUE, &oProjMatrix->at(0, 0));
	glUniformMatrix4fv(oDefaultShader->getUniform("camMatrix"),  1, GL_TRUE,  &matx.at(0, 0));
	glUniform1f(oDefaultShader->getUniform("time"), 1); 

	for (register auto obj = renderData.oData.begin(); obj != renderData.oData.end(); ++obj)
	{
		glBindVertexArray(obj->id);
		glUniformMatrix4fv(oDefaultShader->getUniform("selfMatrix"), 1, GL_TRUE, &obj->matrix.at(0, 0));
		glDrawElements(GL_TRIANGLES, obj->count, GL_UNSIGNED_INT, nullptr);
		glBindVertexArray(0);
	}

	oDefaultShader->unbind();
}