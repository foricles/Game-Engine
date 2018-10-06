#version 330

in vec2 pixPos;
in vec2 uvCoord;
in vec4 pixCol;
in vec3 normals;

out vec4 Color;

uniform sampler2D gSampler;
uniform vec3 lightDirection;

void main()
{
	vec3 light = normalize(lightDirection);
	vec3 norml = normalize(normals);
	float mul = ((dot(light, norml) + 1.0) / 2.0) * 0.75 + 0.25;

	vec4 col = texture2D(gSampler, uvCoord.st) * mul;
	col.b = 0.0;
	Color = col;
}