#ifndef _MATERIAL_HPP_
#define _MATERIAL_HPP_

#include <algorithm>
#include <vec2.hpp>
#include <vec3.hpp>
#include <vec4.hpp>
#include <matrices.hpp>
#include <map>

#include "glprogram.h"
#include "texturebase.hpp"


#define EMPTY_MATERIAL 0xffffff
typedef unsigned int unin;

class Material
{
	friend class MaterialManager;
public:
	Material();
	virtual ~Material();

	GLProgram &getProgram();
	void bind() const;
	void unbind() const;

	unin getMaterialId() const;
	void addTextureAsParametr(Texture *txtr);
public: 
	void setParametr(const std::string &name, int value);
	void setParametr(const std::string &name, float value);
	void setParametr(const std::string &name, kmu::vec2 &value);
	void setParametr(const std::string &name, kmu::vec3 &value);
	void setParametr(const std::string &name, kmu::vec4 &value);
	void setParametr(const std::string &name, kmu::mat4 &value);
	void setTexturesSamples();
private:
	unin oSelfId;
	GLProgram *oShader;

	std::vector<Texture*> oTextures;
	std::map<std::string, GLuint> uniformValues;

private:
	void setId(unin id);
	int findUniformValue(const std::string &value);
};

#endif // !_MATERIAL_HPP_