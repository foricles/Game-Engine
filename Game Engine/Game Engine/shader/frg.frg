#version 330

in vec2 pixPos;
in vec4 pixCol;

out vec4 Color;
void main()
{
	Color = pixCol;
}