#ifndef _GLPROGRAM_H_
#define _GLPROGRAM_H_

#include <GLEW\glew.h>
#include <vector>

#include "utils.h"

enum class SHADER
{
	VERTEX,
	GEOMETRY,
	FRAGMENT
};

struct Shader
{
	SHADER type;
	GLuint id;
	const char *path;
	Shader(SHADER t, GLuint i, const char *p) : type(t), id(i), path(p) {}
};

class GLProgram
{
public:
	GLProgram();
	~GLProgram();

	void addShader(SHADER type, const char *path);
	void begin();
	void end();

	void bind();
	void unbind();

	GLuint getUniform(const char *name);
private:
	std::vector<Shader> oShaders;
	GLuint oProgramId;
};


#endif //!_GLPROGRAM_H_