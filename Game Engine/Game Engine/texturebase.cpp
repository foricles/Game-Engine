#include "texturebase.hpp"

Texture::Texture(TextrType type)
	: m_glID(0)
	, m_glTarget(GL_TEXTURE0)
	, m_glType(type)
{
	glGenTextures(1, &m_glID);
}

Texture::~Texture()
{
	if (m_glID != TEXTR_NONE)
	{
		glDeleteTextures(1, &m_glID);
	}
}

void Texture::bind()
{
	if (m_glID == TEXTR_NONE)
	{
		Logger::Log("Bind not created texture buffer", LogType::ERR);
		return;
	}
	glBindTexture((GLenum)m_glType, m_glID);
	Logger::CheckGLErrors("Texture::bind()");
}

void Texture::unbind()
{
	if (m_glID != TEXTR_NONE)
	{
		glBindTexture((GLenum)m_glType, 0);
	}
	Logger::CheckGLErrors("Texture::unbind()");
}

FIBITMAP * Texture::loadTextureData(const std::string & filePath)
{
	FREE_IMAGE_FORMAT fif = FIF_UNKNOWN;
	FIBITMAP *dib(0);
	BYTE* bits(0);

	fif = FreeImage_GetFileType(filePath.c_str(), 0);
	if (FreeImage_FIFSupportsReading(fif))
	{
		dib = FreeImage_Load(fif, filePath.c_str());
	}
	else
	{
		Logger::Log("Can`t load image:" + filePath, LogType::ERR);
		return nullptr;
	}

	return dib;
}

void Texture::freeTextureData(FIBITMAP *& ptr)
{
	FreeImage_Unload(ptr);
}

void Texture::renderBind()
{
	if (m_glID == TEXTR_NONE)
	{
		Logger::Log("Bind not created texture buffer", LogType::ERR);
		return;
	}
	glActiveTexture(m_glTarget);
	glBindTexture((GLenum)m_glType, m_glID);
	Logger::CheckGLErrors("Texture::renderBind()");
}

void Texture::renderUnbind()
{
	if (m_glID != TEXTR_NONE)
	{
		glBindTexture((GLenum)m_glType, 0);
	}
	Logger::CheckGLErrors("Texture::renderUnbind()");
}

void Texture::applySettings()
{
	this->bind();

	
	
	GLuint wrapMode = (GLuint)m_property.wrapMode;
	GLuint filter = (GLuint)m_property.filter;

	glTexParameteri((GLenum)m_glType, GL_TEXTURE_WRAP_S, wrapMode);
	glTexParameteri((GLenum)m_glType, GL_TEXTURE_WRAP_T, wrapMode);
	if (m_glType == TextrType::TEXTR_CUBE)
		glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_R, wrapMode);

	glTexParameterf((GLenum)m_glType, GL_TEXTURE_MIN_FILTER, filter);
	glTexParameterf((GLenum)m_glType, GL_TEXTURE_MAG_FILTER, filter);
	//glGenerateMipmap(GL_TEXTURE_2D);
	
	Logger::CheckGLErrors("Texture::applySettings()");

	this->unbind();
}

void Texture::setTargetUnit(GLuint unit)
{
	m_glTarget = unit;
}

TextrProperty & Texture::settings()
{
	return m_property;
}

GLuint Texture::getTextureUnit() const
{
	return m_glTarget;
}

void Texture::setSampleName(const std::string & name)
{
	m_SampleName = name;
}

const std::string & Texture::getSampleName() const
{
	return m_SampleName;
}
