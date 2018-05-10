#ifndef _TEXTUREPROPS_HPP_
#define _TEXTUREPROPS_HPP_

#include "opengl.h"

#define TEXTR_NONE 0x0

enum class TextrType
{
	TEXTR_2D = GL_TEXTURE_2D,
	TEXTR_CUBE = GL_TEXTURE_CUBE_MAP_ARB,
	TEXTR_UNDEF = -1,
};

enum class TextrFilter
{
	LINEAR = GL_LINEAR,
	NEAREST = GL_NEAREST,
};

enum class TextrWrapMode
{
	REPEAT = GL_REPEAT,
	EDGE_CLAMP = GL_CLAMP_TO_EDGE,
	MIROR_REPEAT = GL_MIRRORED_REPEAT,
	BORDER_CLAMP = GL_CLAMP_TO_BORDER,
};

struct TextrProperty
{
	GLuint with;
	GLuint height;

	TextrFilter filter;
	TextrWrapMode wrapMode;

	TextrProperty()
		: with(100)
		, height(100)
		, filter(TextrFilter::LINEAR)
		, wrapMode(TextrWrapMode::REPEAT)
	{
	}
};


#endif // !_TEXTUREPROPS_HPP_