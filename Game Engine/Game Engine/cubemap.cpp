#include "cubemap.hpp"

CubeMap::CubeMap()
	: Texture(TextrType::TEXTR_CUBE)
{
}

CubeMap::~CubeMap()
{
}

void CubeMap::begin()
{
	this->bind();
}

void CubeMap::end()
{
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_R, GL_CLAMP_TO_EDGE);
	this->unbind();
}

void CubeMap::loadPosiX(const std::string & filePath)
{
	loadCubeSide(filePath, GL_TEXTURE_CUBE_MAP_POSITIVE_X);
	Logger::CheckGLErrors("CubeMap::loadPosiX");
}

void CubeMap::loadNegaX(const std::string & filePath)
{
	loadCubeSide(filePath, GL_TEXTURE_CUBE_MAP_NEGATIVE_X);
	Logger::CheckGLErrors("CubeMap::loadNegaX");
}

void CubeMap::loadPosiY(const std::string & filePath)
{
	loadCubeSide(filePath, GL_TEXTURE_CUBE_MAP_POSITIVE_Y);
	Logger::CheckGLErrors("CubeMap::loadPosiY");
}

void CubeMap::loadNegaY(const std::string & filePath)
{
	loadCubeSide(filePath, GL_TEXTURE_CUBE_MAP_NEGATIVE_Y);
	Logger::CheckGLErrors("CubeMap::loadNegaY");
}

void CubeMap::loadPosiZ(const std::string & filePath)
{
	loadCubeSide(filePath, GL_TEXTURE_CUBE_MAP_POSITIVE_Z);
	Logger::CheckGLErrors("CubeMap::loadPosiZ");
}

void CubeMap::loadNegaZ(const std::string & filePath)
{
	loadCubeSide(filePath, GL_TEXTURE_CUBE_MAP_NEGATIVE_Z);
	Logger::CheckGLErrors("CubeMap::loadNegaZ");
}

void CubeMap::loadCubeSide(const std::string & path, GLenum side)
{
	FIBITMAP *dib = loadTextureData(path);
	if (dib != nullptr)
	{
		BYTE* bits = FreeImage_GetBits(dib);
		m_property.with = FreeImage_GetWidth(dib);
		m_property.height = FreeImage_GetHeight(dib);

		glTexImage2D(side, 0, GL_RGBA, m_property.with, m_property.height, 0, GL_BGRA, GL_UNSIGNED_BYTE, bits);

		freeTextureData(dib);
	}
}
