#ifndef _DIRECTIONAL_LIGHT_HPP_
#define _DIRECTIONAL_LIGHT_HPP_

#include "lightbase.hpp"

class DirectionalLight : public LightBase
{
public:
	DirectionalLight();
	DirectionalLight(const kmu::vec4 &color);
	DirectionalLight(float r, float g, float b, float a = 1.0f);
	~DirectionalLight();

	kmu::vec3 getLightDirection();
};

#endif // !_DIRECTIONAL_LIGHT_HPP_