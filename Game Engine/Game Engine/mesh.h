#ifndef _MESH_H_
#define _MESH_H_

#include "utils.h"
#include "opengl.h"

class Mesh
{
public:
	Mesh();
	virtual~Mesh();

	void bind();
	void unbind();
	void draw();
	void loadModel(const char* filepath);
private:
	GLuint oVBO;
	GLuint oIBO;
	size_t oDrawQuant;
};

#endif // !_MESH_H_