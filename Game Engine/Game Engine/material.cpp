#include "material.hpp"

Material::Material()
	:oShader(new GLProgram())
	, oSelfId(0)
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
	if (oTextures.size() > 0)
	{
		for (auto it = std::begin(oTextures); it != std::end(oTextures); ++it)
		{
			(*it)->renderBind();
		}
	}
}
void Material::unbind() const
{
	if (oTextures.size() > 0)
	{
		for (auto it = std::begin(oTextures); it != std::end(oTextures); ++it)
		{
			(*it)->renderUnbind();
		}
	}
	oShader->unbind();
}

unin Material::getMaterialId() const
{
	return oSelfId;
}

void Material::addTextureAsParametr(Texture * txtr)
{
	auto fnd = std::find(oTextures.begin(), oTextures.end(), txtr);
	if (fnd == oTextures.end())
	{
		oTextures.push_back(txtr);
	}
}

void Material::setId(unin id)
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

void Material::setParametr(const std::string & name, kmu::vec4 & value)
{
	UniformData * uni = nullptr;
	findValue(&uni, name);
	glUniform4f(uni->Location, value.x, value.y, value.z, value.w);
}

void Material::setParametr(const std::string &name, kmu::mat4 &value)
{
	UniformData * uni = nullptr;
	findValue(&uni, name);
	glUniformMatrix4fv(uni->Location, 1, GL_TRUE, &value.at(0,0));
}

void Material::setTexturesSamples()
{
	if (oTextures.size() > 0)
	{
		int i{ 0 };
		for (register auto it = std::begin(oTextures); it != std::end(oTextures); ++it)
		{
			setParametr((*it)->getSampleName(), i++);
		}
	}
}

#pragma endregion
