#version 330

in vec2 pixPos;
in vec2 uvCoord;
in vec4 pixCol;
in vec3 normal;

out vec4 Color;

uniform sampler2D gSampler;

void main()
{
	vec3 light = normalize(vec3(5,1,-8));
	float intens = dot(normal, light);
	Color = (texture2D(gSampler, uvCoord.st) * intens);
}