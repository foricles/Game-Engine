#ifndef _MYGAME_HPP_
#define _MYGAME_HPP_

#include "scene.hpp"
#include "texture2d.hpp"

class Fly : public Scene
{
private:
	GameObject * seaHawk;
	GameObject * anchor;
	GameObject * propeler;
	GameObject * bomb;

	GameObject * cameraTarget;
	float cX;
	float cY;
	bool bombSpawned;
	kmu::vec3 bombSpeed;
	kmu::vec3 turnAngles;
public:
	Fly() :Scene("Fly")
	{
		cX = 0;
		cY = 0;
	}
	virtual ~Fly() {}

	virtual void Start() override
	{
		using namespace std;
		using namespace kmu;
		using namespace utils;

		string modelPath("resources\\models\\obj\\");
		string textrPath("resources\\textures\\");

		map<string, string> modelData;
		modelData.insert(pair<string, string>("m1_house.obj",		"t1_house.png"));
		modelData.insert(pair<string, string>("m2_house.obj",		"t2_house.png"));
		modelData.insert(pair<string, string>("m3_house.obj",		"t3_house.png"));
		modelData.insert(pair<string, string>("m4_house.obj",		"t4_house.png"));
		modelData.insert(pair<string, string>("m5_tower.obj",		"t5_tower.png"));
		modelData.insert(pair<string, string>("m6_budka.obj",		"t6_budka.png"));
		modelData.insert(pair<string, string>("m7_parnik.obj",		"t7_parnik.png"));
		modelData.insert(pair<string, string>("m8_target.obj",		"t8_target.png"));
		modelData.insert(pair<string, string>("m9_bus_stoper.obj",	"t9_bus_stoper.png"));
		modelData.insert(pair<string, string>("m10_garage.obj",		"t10_garage.png"));
		modelData.insert(pair<string, string>("m11_terrain.obj",	"t11_terrain.png"));
		modelData.insert(pair<string, string>("m12_pallet.obj",		"t12_pallet.png"));
		modelData.insert(pair<string, string>("m13_cable.obj",		"t13_cable.png"));
		modelData.insert(pair<string, string>("m14_angar.obj",		"t14_angar.png"));

		Material *tempMaterial;
		for (auto model = modelData.begin(); model != modelData.end(); model++)
		{
			string meshName = model->first;
			string textrName = model->second;

			Texture2D *texture = new Texture2D;
			texture->loadTexture(textrPath + textrName);
			texture->settings().filter = TextrFilter::LINEAR;
			texture->settings().wrapMode = TextrWrapMode::REPEAT;
			texture->setSampleName("gSampler");
			texture->applySettings();

			tempMaterial = materialManager->New();
			tempMaterial->getProgram().begin();
			tempMaterial->getProgram().addShader(SHADER::VERTEX, "resources\\shader\\vrt.vrt");
			tempMaterial->getProgram().addShader(SHADER::FRAGMENT, "resources\\shader\\frg.frg");
			tempMaterial->addTextureAsParametr(texture);
			tempMaterial->getProgram().end();

			auto obj = objectManager->getObject();
			obj->getMesh()->loadModel(string(modelPath + meshName).c_str());
			obj->setPosition(0, 0, 0);
			obj->getMesh()->setMaterial(tempMaterial);
			obj->getMesh()->bindModel();
		}

		seaHawk = objectManager->getObject();
		seaHawk->getMesh()->loadModel(string(modelPath + "PlaneBody.obj").c_str());
		seaHawk->setPosition(0, 1000, -2000);
		seaHawk->setScale(0.3, 0.3, 0.3);
		seaHawk->getMesh()->setMaterial(tempMaterial);
		seaHawk->getMesh()->bindModel();

		anchor = objectManager->getObject();
		anchor->getMesh()->loadModel(string(modelPath + "PlaneBody.obj").c_str());
		anchor->getMesh()->setMaterial(tempMaterial);
		anchor->getMesh()->bindModel();
		anchor->setPosition(0, 0, -50);
		anchor->setScale(0.001, 0.001, 0.001);
		anchor->setParent(seaHawk);

		cameraTarget = anchor;

		bomb = objectManager->getObject();
		bomb->getMesh()->loadModel(string(modelPath + "Bomb.obj").c_str());
		bomb->getMesh()->setMaterial(tempMaterial);
		bomb->getMesh()->bindModel();
		bomb->setPosition(0, -100, 0);
		
		propeler = objectManager->getObject();
		propeler->getMesh()->loadModel(string(modelPath + "PlaneGvint.obj").c_str());
		propeler->getMesh()->setMaterial(tempMaterial);
		propeler->getMesh()->bindModel();
		propeler->setPosition(0, 0, 0);
		propeler->setParent(seaHawk);

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
		using namespace std;
		using namespace kmu;
		using namespace utils;

		static float ang = 0;
		static float bombAngl = 0;
		ang += 0.25f;
		if (ang >= 2 * MY_PI) ang = 0;
		propeler->setRotation(quaternion::angleAxis(ang, VEC3_FRONT));

		if (Input->isKeyPressed(KeyCode::Q))
		{
			window->close();
		}

		float l = 500;
		vec3 dir;
		dir.z = 1000;

		if (!bombSpawned && Input->isKeyPressed(KeyCode::F))
		{
			bombSpawned = true;
			bomb->setPosition(anchor->getGlobalPosition());
			cameraTarget = bomb;
			bombSpeed = seaHawk->transformDirection(dir);
		}

		if (bombSpawned)
		{
			if (bomb->getGlobalPosition().y < 0)
			{
				cameraTarget = anchor;
				bombSpawned = false;
				bombAngl = 0;
				bomb->setPosition(0, -100, 0);
			}
			else
			{
				bombSpeed += VEC3_UP * -9.7f;
				bombAngl += 0.01f;
				bomb->translate(bombSpeed * deltaTime);
				bomb->setRotation(quaternion::angleAxis(bombAngl, VEC3_UP));
			}
		}
		else
		{
			if (Input->isKeyPressed(KeyCode::W))
			{
				turnAngles.y += 0.01f;
			}
			else if (Input->isKeyPressed(KeyCode::S))
			{
				turnAngles.y -= 0.01f;
			}
			else
			{
				turnAngles.y += (turnAngles.y > 0) ? -0.01f : 0.01f;
				if (abs(turnAngles.y) <= 0.01f)
				{
					turnAngles.y = 0;
				}
			}

			if (Input->isKeyPressed(KeyCode::A))
			{
				turnAngles.x -= 0.01f;
				turnAngles.z += 0.01f;
			}
			else if (Input->isKeyPressed(KeyCode::D))
			{
				turnAngles.x += 0.01f;
				turnAngles.z -= 0.01f;
			}
			else
			{
				turnAngles.z += (turnAngles.z > 0) ? -0.01f : 0.01f;
				if (abs(turnAngles.z) <= 0.01f)
				{
					turnAngles.z = 0;
				}
			}
		}
		cX += Input->getMouseDeltaPosX() * 0.01f;
		cY += Input->getMouseDeltaPosY() * deltaTime;
		
		cY = math::clamp(cY, -0.2, 0.9);
		turnAngles.x = math::clamp(turnAngles.x, -35.0, 35.0);
		turnAngles.y = math::clamp(turnAngles.y, -0.2, 0.9);
		turnAngles.z = math::clamp(turnAngles.z, -0.5, 0.5);

		auto rot = quaternion::angleAxis(cX, VEC3_UP) * quaternion::angleAxis(cY, VEC3_RIGHT);
		anchor->setRotation(rot);

		seaHawk->setRotation(quaternion::euler(turnAngles.y, turnAngles.x, turnAngles.z));
		dir = seaHawk->transformDirection(dir);
		seaHawk->translate(dir * deltaTime);

		getMainCamera()->setPosition(cameraTarget->getGlobalPosition() + cameraTarget->transformDirection(VEC3_FRONT) * -250);
		getMainCamera()->setRotation(cameraTarget->getLocalRotation());
	}
};

#endif // !_MYGAME_HPP_
