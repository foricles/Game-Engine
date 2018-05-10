#version 330

in vec3 pixPos;

out vec4 Color;

uniform samplerCube gSkySampler;

void main()
{
	Color = texture(gSkySampler, pixPos) + vec4(0.0, 0.0, 0.0, 1.0);
}