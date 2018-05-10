#include "render.hpp"


Render::Render(ObjectManager *manager, MaterialManager *matManager, DirectionalLight *light, SkyBox *skybox)
	: oMatManager(*matManager)
	, oObjManager(*manager)
	, oCurrentMaterial(-1)
	, oLight(*light)
	, oSkybox(skybox)
{
	oMainCamera = new Camera();
	oMainCamera->translate(0, 0, -20);
}

Render::~Render()
{
	delete oMainCamera;
}

void Render::draw()
{
	RenderData renderData;
	oObjManager.getRenderData(&renderData);
	renderData.SortByMaterial();

	auto rendermat = oMatManager.findMaterialById(oCurrentMaterial);
	for (register auto obj = renderData.oData.begin(); obj != renderData.oData.end(); ++obj)
	{
		unin material = obj->material;
		if (material == EMPTY_MATERIAL)
			material = oMatManager.getDefaultMaterial()->getMaterialId();

		if (material != oCurrentMaterial)
		{
			if (rendermat)
			{
				rendermat->unbind();
			}

			oCurrentMaterial = material;
			rendermat = oMatManager.findMaterialById(oCurrentMaterial);
			rendermat->bind();
		}
		rendermat->setParametr("worldMatrix", oMainCamera->getProjectionMatrix());
		rendermat->setParametr("camMatrix", oMainCamera->getCameraMatrix());
		rendermat->setParametr("lightDirection", oLight.getLightDirection());
		rendermat->setParametr("selfMatrix", obj->matrix);
		rendermat->setTexturesSamples();

		glBindVertexArray(obj->vao);
		glDrawElements(GL_TRIANGLES, obj->count, GL_UNSIGNED_INT, nullptr);
		glBindVertexArray(0);
	}
	rendermat->unbind();

	if (oSkybox != nullptr)
	{
		oSkybox->drawSky(oMainCamera->getCameraMatrix(), oMainCamera->getProjectionMatrix());
	}
}

const Camera * Render::getMainCam() const
{
	return oMainCamera;
}

Camera * Render::getMainCam()
{
	return oMainCamera;
}

void Render::setSkybox(SkyBox * skyBox)
{
	oSkybox = skyBox;
}
