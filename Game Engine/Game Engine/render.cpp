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
	auto renderData = oObjManager.getRenderObjects();
	std::stable_sort(renderData.begin(), renderData.end(), [](GameObject* a, GameObject* b) {return a->getMesh()->getMaterialId() > b->getMesh()->getMaterialId(); });
	

	oCurrentMaterial = -1;
	Material *rendermat = nullptr;
	for (register auto obj = renderData.begin(); obj != renderData.end(); ++obj)
	{
		Mesh *mesh = (*obj)->getMesh();
		unin material = mesh->getMaterialId();
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
		rendermat->setParametr("selfMatrix", (*obj)->globalMatrix());
		rendermat->setTexturesSamples();

		mesh->draw();
	}
	if (rendermat != nullptr)
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

SkyBox * Render::customizeSkybox()
{
	if (oSkybox != nullptr)
		delete oSkybox;
	oSkybox = new SkyBox();
	return oSkybox;
}

