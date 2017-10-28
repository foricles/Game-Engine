#include "material.hpp"

Material::Material()
	:oShader(new GLProgram())
	, oTextId(EMPTY_MATERIAL)
	, oSelfId(EMPTY_MATERIAL)
{
}

Material::~Material()
{
	delete oShader;

	for (register int i(0); i < oUniformValues.size(); ++i)
		if (oUniformValues[i] != nullptr)
			delete oUniformValues[i];
	oUniformValues.clear();
}

GLProgram & Material::getProgram()
{
	return (*oShader);
}

void Material::bind() const
{
	oShader->bind();
	if (oTextId != EMPTY_MATERIAL)
	{
		glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_2D, oTextId);
	}
}
void Material::unbind() const
{
	if (oTextId != EMPTY_MATERIAL)
		glBindTexture(GL_TEXTURE_2D, 0);
	oShader->unbind();
}

void Material::loadTexture(const std::string &path)
{
	if (oTextId == EMPTY_MATERIAL)
	{
		FREE_IMAGE_FORMAT fif = FIF_UNKNOWN;
		FIBITMAP *dib(0);
		BYTE* bits(0);
		unsigned int width(0), height(0);

		fif = FreeImage_GetFileType(path.c_str(), 0);
		if (FreeImage_FIFSupportsReading(fif))
		{
			dib = FreeImage_Load(fif, path.c_str());
		}
		else
		{
			Logger::Log("Can`t load image:" + path, LogType::ERR);
			return;
		}

		bits = FreeImage_GetBits(dib);
		width = FreeImage_GetWidth(dib);
		height = FreeImage_GetHeight(dib);
		auto bpp = FreeImage_GetBPP(dib);

		glGenTextures(1, &oTextId);
		glBindTexture(GL_TEXTURE_2D, oTextId);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_BGRA, GL_UNSIGNED_BYTE, bits);
		glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glBindTexture(GL_TEXTURE_2D, 0);

		FreeImage_Unload(dib);
	}
}

size_t Material::getMaterialId() const
{
	return oSelfId;
}

void Material::setId(size_t id)
{
	oSelfId = id;
}

void Material::findValue(UniformData **ret, const std::string & name)
{
	*ret = nullptr;
	for (register int i(0); i < oUniformValues.size(); ++i)
	{
		if (oUniformValues[i]->Name._Equal(name))
		{
			*ret = oUniformValues[i];
			break;
		}
	}

	if (*ret == nullptr)
	{
		GLuint id = oShader->getUniform(name.c_str());
		*ret = new UniformData(name, id);
		oUniformValues.push_back(*ret);
	}
}

#pragma region setters

void Material::setParametr(const std::string &name, int value)
{
	UniformData * uni = nullptr;
	findValue(&uni, name);
	glUniform1i(uni->Location, value);
}

void Material::setParametr(const std::string &name, float value)
{
	UniformData * uni = nullptr;
	findValue(&uni, name);
	glUniform1f(uni->Location, value);
}

void Material::setParametr(const std::string &name, kmu::vec2 &value)
{
	UniformData * uni = nullptr;
	findValue(&uni, name);
	glUniform2f(uni->Location, value.x, value.y);
}

void Material::setParametr(const std::string &name, kmu::vec3 &value)
{
	UniformData * uni = nullptr;
	findValue(&uni, name);
	glUniform3f(uni->Location, value.x, value.y, value.z);
}

void Material::setParametr(const std::string &name, kmu::mat4 &value)
{
	UniformData * uni = nullptr;
	findValue(&uni, name);
	glUniformMatrix4fv(uni->Location, 1, GL_TRUE, &value.at(0,0));
}

#pragma endregion
