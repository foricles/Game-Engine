#version 330

in vec2 pixPos;
in vec4 pixCol;

out vec4 Color;

uniform float time;

void main()
{
	float r = (cos(pixPos.x * time)+1.0)/2.0;
	float g = (sin(time)+1.0)/2.0;
	float b = (cos(time)+1.0)/2.0;
	Color = vec4(r, g, b, 1.0);
}