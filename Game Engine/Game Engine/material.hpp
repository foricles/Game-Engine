#ifndef _MATERIAL_HPP_
#define _MATERIAL_HPP_

#include "opengl.h"
#include "glprogram.h"
#include <algorithm>
#include <vec2.hpp>
#include <vec3.hpp>
#include <vec4.hpp>
#include <matrices.hpp>
#include <FreeImage.h>

#define EMPTY_MATERIAL 0xffffff

struct UniformData
{
	std::string Name;
	GLuint Location;
	UniformData() : UniformData("", 0){}
	UniformData(const std::string &name, GLuint lok): Name(name), Location(lok){}
};

class Material
{
	friend class MaterialManager;
public:
	Material();
	virtual ~Material();

	GLProgram &getProgram();
	void bind() const;
	void unbind() const;

	size_t getMaterialId() const;

	void loadTexture(const std::string &path);
public: 
	void setParametr(const std::string &name, int value);
	void setParametr(const std::string &name, float value);
	void setParametr(const std::string &name, kmu::vec2 &value);
	void setParametr(const std::string &name, kmu::vec3 &value);
	void setParametr(const std::string &name, kmu::vec4 &value);
	void setParametr(const std::string &name, kmu::mat4 &value);
private:
	size_t oSelfId;
	GLuint oTextId;
	GLProgram *oShader;

	std::vector<UniformData*> oUniformValues;

private:
	void setId(size_t id);
	void findValue(UniformData **ret, const std::string &name);
};

#endif // !_MATERIAL_HPP_