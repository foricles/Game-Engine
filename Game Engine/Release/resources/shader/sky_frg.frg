#version 330

in vec2 pixPos;
in vec2 uvCoord;

out vec4 Color;

uniform sampler2D gSampler;
uniform vec3 lightDirection;

void main()
{
	Color = texture2D(gSampler, uvCoord.st);
}