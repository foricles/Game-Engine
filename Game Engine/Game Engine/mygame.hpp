#ifndef _MYGAME_HPP_
#define _MYGAME_HPP_

#include "scene.hpp"

class Fly : public Scene
{
private:
	GameObject* cube1;
	GameObject* cube2;
	GameObject* cube3;
	float angle;
public:
	Fly() :Scene("Fly")
	{
		angle = 0;
	}
	virtual ~Fly() {}

	virtual void Start() override
	{
		////C:\\Users\\foricles\\Desktop\\Cathedral.fbx
		////C:\\Users\\foricles\\Desktop\\man.fbx
		cube1 = oObjectManager->getObject();
		cube1->getMesh().loadModel("D:\\Work\\projects\\cpp\\Game-Engine\\Game Engine\\shader\\cube.fbx");

		cube2 = oObjectManager->getObject();
		cube2->getMesh().loadModel("D:\\Work\\projects\\cpp\\Game-Engine\\Game Engine\\shader\\cube.fbx");

		cube3 = oObjectManager->getObject();
		cube3->getMesh().loadModel("D:\\Work\\projects\\cpp\\Game-Engine\\Game Engine\\shader\\cube.fbx");

		cube2->transform().setPosition(-3, 0, 0);
		cube2->transform().setParent(&cube1->transform());

		cube3->transform().setPosition(-5, 0, 0);
		cube3->transform().setParent(&cube2->transform());
	}

	virtual void Update() override
	{
		float degr = 0.1;
		angle += utils::math::to_radian(degr);

		cube1->transform().setRotation(kmu::quaternion::euler(+angle, VEC3_FRONT));
		cube2->transform().setRotation(kmu::quaternion::euler(-angle * 2, VEC3_FRONT));

		auto t = Input->getMouseDeltaPos();
		getMainCamera()->rotate(VEC3_RIGHT, -(t.y / 480)/10 );
		getMainCamera()->rotate(VEC3_UP, -(t.x / 640) / 10);
	}
};

#endif // !_MYGAME_HPP_
