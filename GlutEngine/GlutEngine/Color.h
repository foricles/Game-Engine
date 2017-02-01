#ifndef _COLOR_H
#define _COLOR_H


struct Color
{
	
	Color();
	Color(float r, float g, float b, float a = 1.0f);
	Color(const Color &color);

	~Color();

	float Red;
	float Blue;
	float Green;
	float Alpha;

	void Identity();
	void UnIdentity();

	static float ToIdentity(int c);
	static int ToUnidentity(float c);

	void operator=(const Color &color);
};

#endif // !_COLOR_H
