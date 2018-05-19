#ifndef _MYGAME_HPP_
#define _MYGAME_HPP_

#include "scene.hpp"
#include "texture2d.hpp"

using namespace kmu;
using namespace utils;

class Fly : public Scene
{
private:
	GameObject* cube1;

	float cX;
	float cY;
public:
	Fly() :Scene("Fly")
	{
		cX = 0;
		cY = 0;
	}
	virtual ~Fly() {}

	virtual void Start() override
	{
		std::string modelPath("resources\\models\\obj\\");
		std::string textrPath("resources\\textures\\");

		Texture2D *floor = new Texture2D;
		floor->loadTexture(std::string("resources\\font\\FontanTexture.png"));
		floor->settings().filter = TextrFilter::LINEAR;
		floor->settings().wrapMode = TextrWrapMode::REPEAT;
		floor->setSampleName("gSampler");
		floor->applySettings();

		auto textrRock = materialManager->New();
		textrRock->getProgram().begin();
		textrRock->getProgram().addShader(SHADER::VERTEX, "resources\\shader\\vrt.vrt");
		textrRock->getProgram().addShader(SHADER::FRAGMENT, "resources\\shader\\frg.frg");
		textrRock->addTextureAsParametr(floor);
		textrRock->getProgram().end();

		for (float j(0); j < 2 * MY_PI; j += 2 * MY_PI / 5)
		{
			for (float i(0); i < 2 * MY_PI; i += 2 * MY_PI / 25)
			{
				float dx = cos(j) * 500;
				float dy = sin(j) * 500;
				auto obj = objectManager->getObject();
				obj->getMesh()->loadModel("resources\\font\\Fontan.FBX");
				obj->setRotation(kmu::quaternion::euler(-MY_PI / 2, VEC3_RIGHT));
				obj->setPosition(200 * cos(i) + dx, 200 * i, 200 * sin(i) + dy);
				obj->getMesh()->setMaterial(textrRock);
				obj->getMesh()->bindModel();
			}

		CubeMap *cubeMap = new CubeMap;
		cubeMap->settings().wrapMode = TextrWrapMode::EDGE_CLAMP;
		cubeMap->settings().filter = TextrFilter::LINEAR;
		cubeMap->applySettings();

		cubeMap->begin();
		cubeMap->loadPosiX(textrPath + "skybox\\posX.png");
		cubeMap->loadNegaX(textrPath + "skybox\\negX.png");
	
		cubeMap->loadPosiY(textrPath + "skybox\\posY.png");
		cubeMap->loadNegaY(textrPath + "skybox\\negY.png");
	
		cubeMap->loadPosiZ(textrPath + "skybox\\posZ.png");
		cubeMap->loadNegaZ(textrPath + "skybox\\negZ.png");
		cubeMap->end();

		customizeSkybox()->setSkyCubemap(cubeMap);
	}

	virtual void Update() override
	{
		if (Input->isKeyPressed(KeyCode::Q))
		{
			window->close();
		}

		float l = 100;
		vec3 dir;
		if (Input->isKeyPressed(KeyCode::W))
		{
			dir.z = l;
		}
		else if (Input->isKeyPressed(KeyCode::S))
		{
			dir.z = -l;
		}

		if (Input->isKeyPressed(KeyCode::A))
		{
			dir.x = l;
		}
		else if (Input->isKeyPressed(KeyCode::D))
		{
			dir.x = -l;
		}

		cX = -math::lerp(cX, cX + Input->getMouseDeltaPosX() / 100, 0.4);
		cY = math::lerp(cY, cY + Input->getMouseDeltaPosY() / 100, 0.4);

		auto rot = quaternion::euler(cX, VEC3_UP) * quaternion::euler(cY, VEC3_RIGHT);
		getMainCamera()->setRotation(rot);

		getMainCamera()->move(dir * deltaTime);
	}
};

#endif // !_MYGAME_HPP_
