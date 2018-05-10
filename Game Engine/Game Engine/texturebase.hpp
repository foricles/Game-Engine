#ifndef _TEXTUREBASE_HPP_
#define _TEXTUREBASE_HPP_

#include <FreeImage.h>
#include "textureprops.hpp"
#include "Logger.h"


class Texture
{
public:
	Texture(TextrType type);
	virtual ~Texture();

	virtual void renderBind();
	virtual void renderUnbind();
	virtual void applySettings();

	virtual void setTargetUnit(GLuint unit);
	virtual TextrProperty &settings();
	virtual GLuint getTextureUnit() const;
	virtual void setSampleName(const std::string &name);
	virtual const std::string & getSampleName() const;
protected:
	virtual void bind();
	virtual void unbind();

	static void freeTextureData(FIBITMAP *& ptr);
	static FIBITMAP *loadTextureData(const std::string &filePath);
protected:
	GLuint m_glID;
	GLuint m_glTarget;
	TextrType m_glType;
	TextrProperty m_property;
	std::string m_SampleName;
};
#endif // !_TEXTUREBASE_HPP_