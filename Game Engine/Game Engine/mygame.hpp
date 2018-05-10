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
	GameObject* cube2;
	GameObject* cube3;
	GameObject* plane;
	GameObject* wint;
	float angle;

	float xAx;
	float yAx;

	float lAx;
public:
	Fly() :Scene("Fly")
	{
		angle = 0;
		xAx = 0;
		yAx = 0;

		lAx = 0;
	}
	virtual ~Fly() {}

	virtual void Start() override
	{
		std::string modelPath("resources\\models\\obj\\");
		std::string textrPath("resources\\textures\\");

		Texture2D *floor = new Texture2D;
		floor->loadTexture(textrPath + "Floor.png");
		floor->settings().filter = TextrFilter::LINEAR;
		floor->settings().wrapMode = TextrWrapMode::REPEAT;
		floor->setSampleName("gSampler");
		floor->applySettings();

		Texture2D *yak = new Texture2D;
		yak->loadTexture(textrPath + "YAK3.png");
		yak->settings().filter = TextrFilter::LINEAR;
		yak->settings().wrapMode = TextrWrapMode::REPEAT;
		yak->setSampleName("gSampler");
		yak->applySettings();

		Texture2D *grass = new Texture2D;
		grass->loadTexture(textrPath + "YAK3.png");
		grass->settings().filter = TextrFilter::LINEAR;
		grass->settings().wrapMode = TextrWrapMode::REPEAT;
		grass->setSampleName("gSampler");
		grass->applySettings();

		auto textrRock = materialManager->New();
		textrRock->getProgram().begin();
		textrRock->getProgram().addShader(SHADER::VERTEX, "resources\\shader\\vrt.vrt");
		textrRock->getProgram().addShader(SHADER::FRAGMENT, "resources\\shader\\frg.frg");
		textrRock->addTextureAsParametr(floor);
		textrRock->getProgram().end();


		auto obj = objectManager->getObject();
		obj->getMesh().loadModel((modelPath + "terra.obj").c_str());
		obj->setPosition(0, 0, 0);
		obj->getMesh().setMaterial(textrRock);
		obj->getMesh().bindModel();

		obj = objectManager->getObject();
		obj->getMesh().loadModel((modelPath + "columns.obj").c_str());
		obj->setPosition(0, 0, 0);
		obj->getMesh().setMaterial(textrRock);
		obj->getMesh().bindModel();

		obj = objectManager->getObject();
		obj->getMesh().loadModel((modelPath + "stones.obj").c_str());
		obj->setPosition(0, 0, 0);
		obj->getMesh().setMaterial(textrRock);
		obj->getMesh().bindModel();

		obj = objectManager->getObject();
		obj->getMesh().loadModel((modelPath + "stairs.obj").c_str());
		obj->setPosition(0, 0, 0);
		obj->getMesh().setMaterial(textrRock);
		obj->getMesh().bindModel();

		auto yaktxt = materialManager->New();
		yaktxt->getProgram().begin();
		yaktxt->getProgram().addShader(SHADER::VERTEX, "resources\\shader\\vrt.vrt");
		yaktxt->getProgram().addShader(SHADER::FRAGMENT, "resources\\shader\\frg.frg");
		yaktxt->addTextureAsParametr(yak);
		yaktxt->getProgram().end();

		plane = objectManager->getObject();
		plane->getMesh().loadModel((modelPath + "PlaneBody.obj").c_str());
		plane->setPosition(0, 0, 0);
		plane->setScaling(0.2f, 0.2f, 0.2f);
		plane->getMesh().setMaterial(yaktxt);
		plane->getMesh().bindModel();

		wint = objectManager->getObject();
		wint->getMesh().loadModel((modelPath + "PlaneWint.obj").c_str());
		wint->setParent(plane);
		wint->setPosition(0, 0, 0);
		wint->getMesh().setMaterial(yaktxt);
		wint->getMesh().bindModel();

		getMainCamera()->setRotation(kmu::quaternion::euler(MY_PI/2, VEC3_UP));

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



		SkyBox *skyBox = new SkyBox;
		skyBox->setSkyCubemap(cubeMap);

		setSkybox(skyBox);
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

		getMainCamera()->setRotation(kmu::quaternion::euler(xAx, VEC3_UP));
		
		float speed = 30 * dt;

		if (Input->isKeyPressed(KeyCode::L))
		{
			lAx += dt;
			oLight.setRotation(kmu::quaternion::euler(lAx, VEC3_RIGHT));
		}
		else if (Input->isKeyPressed(KeyCode::K))
		{
			lAx -= dt;
			oLight.setRotation(kmu::quaternion::euler(lAx, VEC3_RIGHT));
		}

		if (Input->isKeyPressed(KeyCode::W))
			plane->translate(0, speed, 0);
		else if (Input->isKeyPressed(KeyCode::S))
			plane->translate(0, -speed, 0);

		if (Input->isKeyPressed(KeyCode::D))
			plane->rotate(0.001f, VEC3_UP);
		else if (Input->isKeyPressed(KeyCode::A))
			plane->rotate(-0.001f, VEC3_UP);

		vec3 dir = vec3(0, 30, -150);
		dir = plane->transformDirection(dir);
		getMainCamera()->setPosition(plane->getPosition() + dir);
		getMainCamera()->setRotation(plane->getRotation());
		
		static float wintAng = 0;
		wint->setRotation(kmu::quaternion::euler(wintAng, VEC3_FRONT));
		wintAng += 0.06f;

		plane->translate(plane->transformDirection(VEC3_FRONT) * 45 * dt);
	}
};

#endif // !_MYGAME_HPP_
