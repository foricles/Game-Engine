#ifndef _MYGAME_HPP_
#define _MYGAME_HPP_

#include "scene.hpp"

using namespace kmu;
using namespace utils;

class Fly : public Scene
{
private:
	GameObject* cube1;
	GameObject* cube2;
	GameObject* cube3;
	float angle;

	float xAx;
	float yAx;
public:
	Fly() :Scene("Fly")
	{
		angle = 0;
		xAx = 0;
		yAx = 0;
	}
	virtual ~Fly() {}

	virtual void Start() override
	{
		auto textrRock = materialManager->New();
		textrRock->getProgram().begin();
		textrRock->getProgram().addShader(SHADER::VERTEX, "resurses\\shader\\vrt.vrt");
		textrRock->getProgram().addShader(SHADER::FRAGMENT, "resurses\\shader\\frg.frg");
		textrRock->loadTexture("resurses\\textures\\BrickJapanese0123.jpeg");
		textrRock->getProgram().end();

		std::string modelPath("resurses\\models\\");
		std::string textrPath("resurses\\textures\\");

		auto obj = objectManager->getObject();
		obj->getMesh().loadModel((modelPath + "Terrain.fbx").c_str());
		obj->setPosition(100,0,0);
		obj->getMesh().bindModel();

		obj = objectManager->getObject();
		obj->getMesh().loadModel((modelPath + "Colons.fbx").c_str());
		obj->setPosition(0, 0, 0);
		obj->getMesh().setMaterial(textrRock);
		obj->getMesh().bindModel();

		obj = objectManager->getObject();
		obj->getMesh().loadModel((modelPath + "Stones.fbx").c_str());
		obj->setPosition(0, 0, 0);
		obj->getMesh().bindModel();

		obj = objectManager->getObject();
		obj->getMesh().loadModel((modelPath + "Place.fbx").c_str());
		obj->setPosition(0, 0, 0);
		obj->getMesh().bindModel();

		/*const char* cube = "resurses\\woodBox.fbx";
		int s = 25;
		for (register int i(0); i < 10; i++)
		{
			for (register int j(0); j < 10; j++)
			{
				for (register int k(0); k < 10; k++)
				{
					auto obj = objectManager->getObject();
					obj->getMesh().loadModel(cube);
					obj->setPosition(i*s, j*s, k*s);
				}
			}
		}
		*/
	}

	virtual void Update() override
	{
		if (Input->isKeyPressed(KeyCode::Q))
		{
			window->close();
		}

		static int c(0);
		double dt = (*deltaTime);
		kmu::vec2 mouse = Input->getMouseDeltaPos() * 0.01;

		xAx = math::lerp(xAx, mouse.x + xAx, 0.1f);
		yAx = math::lerp(yAx, mouse.y + yAx, 0.1f);

		getMainCamera()->setRotation(kmu::quaternion::euler(xAx, VEC3_FRONT) * kmu::quaternion::euler(yAx, VEC3_RIGHT));
		
		float speed = 30 * dt;

		if (Input->isKeyPressed(KeyCode::W))
			getMainCamera()->move(0, 0, speed);
		else if (Input->isKeyPressed(KeyCode::S))
			getMainCamera()->move(0, 0, -speed);

		if (Input->isKeyPressed(KeyCode::D))
			getMainCamera()->move(-speed, 0, 0);
		else if (Input->isKeyPressed(KeyCode::A))
		getMainCamera()->move(speed, 0, 0);
	}
};

#endif // !_MYGAME_HPP_
