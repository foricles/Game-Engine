#ifndef _GLUTENGINE_H
#define _GLUTENGINE_H

#include "Vector2.h"
#include "Engine.h"
#include "Settings.h"
#include "RenderShape.h"
#include "CreateShape.h"
#include "Colors.h"

Engine *GlutEngine = nullptr;

inline void PrimitiveMove(RenderShape * shape, float speed)
{
	if (Input::KeyPressed('w')) shape->transform.Translate(VUP * speed * Timer::deltaTime);
	if (Input::KeyPressed('s')) shape->transform.Translate(VDOWN * speed * Timer::deltaTime);
	if (Input::KeyPressed('d')) shape->transform.Translate(VRIGHT * speed * Timer::deltaTime);
	if (Input::KeyPressed('a')) shape->transform.Translate(VLEFT * speed * Timer::deltaTime);
}

#endif // !_GLUTENGINE_H

