#include "directlight.hpp"

DirectionalLight::DirectionalLight()
	: LightBase()
{
}

DirectionalLight::DirectionalLight(const kmu::vec4 & color)
	:LightBase(color)
{
}

DirectionalLight::DirectionalLight(float r, float g, float b, float a)
	:LightBase(r, g, b, a)
{
}

DirectionalLight::~DirectionalLight()
{
}

kmu::vec3 DirectionalLight::getLightDirection()
{
	return oRot.rotate(VEC3_FRONT);
}
