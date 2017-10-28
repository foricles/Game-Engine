#version 330

in vec2 pixPos;
in vec2 uvCoord;
in vec4 pixCol;

out vec4 Color;

uniform sampler2D gSampler;

void main()
{
	Color = texture2D(gSampler, uvCoord.st);
}