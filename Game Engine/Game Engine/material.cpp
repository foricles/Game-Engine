#include "material.hpp"

Material::Material()
	:oShader(new GLProgram())
	, oSelfId(0)
{
}

Material::~Material()
{
	delete oShader;
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

int Material::findUniformValue(const std::string & value)
{
	if (uniformValues.find(value) != uniformValues.end())
	{
		return uniformValues[value];
	}
	int id = oShader->getUniform(value.c_str());
	if (id > 0)
	{
		uniformValues.insert(std::pair<std::string, GLuint>(value, id));
	}
	return id;
}


#pragma region setters

void Material::setParametr(const std::string &name, int value)
{
	int location = findUniformValue(name);
	if (location > 0)
	{
		glUniform1i(location, value);
	}
}

void Material::setParametr(const std::string &name, float value)
{
	int location = findUniformValue(name);
	if (location > 0)
	{
		glUniform1f(location, value);
	}
}

void Material::setParametr(const std::string &name, kmu::vec2 &value)
{
	int location = findUniformValue(name);
	if (location > 0)
	{
		glUniform2f(location, value.x, value.y);
	}
}

void Material::setParametr(const std::string &name, kmu::vec3 &value)
{
	int location = findUniformValue(name);
	if (location > 0)
	{
		glUniform3f(location, value.x, value.y, value.z);
	}
}

void Material::setParametr(const std::string & name, kmu::vec4 & value)
{
	int location = findUniformValue(name);
	if (location > 0)
	{
		glUniform4f(location, value.x, value.y, value.z, value.w);
	}
}

void Material::setParametr(const std::string &name, kmu::mat4 &value)
{
	int location = findUniformValue(name);
	if (location > 0)
	{
		glUniformMatrix4fv(location, 1, GL_TRUE, &value.at(0, 0));
	}
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
