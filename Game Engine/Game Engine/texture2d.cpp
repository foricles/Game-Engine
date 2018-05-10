#include "texture2d.hpp"

Texture2D::Texture2D()
	: Texture(TextrType::TEXTR_2D)
{
}

Texture2D::~Texture2D()
{
}

void Texture2D::loadTexture(std::string & filepath)
{
	FIBITMAP *dib = loadTextureData(filepath);
	if (dib != nullptr)
	{
		BYTE* bits = FreeImage_GetBits(dib);
		m_property.with = FreeImage_GetWidth(dib);
		m_property.height = FreeImage_GetHeight(dib);
		//auto bpp = FreeImage_GetBPP(dib);

		this->bind();
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, m_property.with, m_property.height, 0, GL_BGRA, GL_UNSIGNED_BYTE, bits);
		this->unbind();

		freeTextureData(dib);
	}
}
