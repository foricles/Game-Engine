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
		const char* cube = "resurses\\woodBox.fbx";
		int s = 20;
		for (register int i(0); i < 10; i++)
		{
			for (register int j(0); j < 10; j++)
			{
				for (register int k(0); k < 10; k++)
				{
					auto obj = oObjectManager->getObject();
					obj->getMesh().loadModel(cube);
					obj->transform().setPosition(i*s, j*s, k*s);
				}
			}
		}
	}

	virtual void Update() override
	{
		static int c(0);
		double dt = (*deltaTime);
		kmu::vec2 mouse = Input->getMouseDeltaPos() * dt;
		auto axis = VEC3_UP;

		xAx += mouse.x;
		yAx += mouse.y;

		getMainCamera()->setRotation(kmu::quaternion::euler(xAx, VEC3_UP) * kmu::quaternion::euler(yAx, VEC3_RIGHT));
		
		if (Input->isKeyPressed(KeyCode::W))
			getMainCamera()->move(0, 0, 5*dt);
		else if (Input->isKeyPressed(KeyCode::S))
			getMainCamera()->move(0, 0, -5 * dt);

		if (Input->isKeyPressed(KeyCode::D))
			getMainCamera()->move(-5*dt, 0, 0);
		else if (Input->isKeyPressed(KeyCode::A))
		getMainCamera()->move(5*dt, 0, 0);
	}
};

#endif // !_MYGAME_HPP_
