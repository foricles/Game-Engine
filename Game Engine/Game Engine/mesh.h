#ifndef _MESH_H_
#define _MESH_H_

#include "utils.h"
#include "opengl.h"
#include "glprogram.h"

#include <string>

class Mesh
{
public:
	Mesh();
	virtual~Mesh();

	void bind();
	void unbind();
	void draw();

	void loadModel(const char* filepath);
	void setMaterial(const char *filepath);

	inline GLuint vboId(){return oVBO;}
	inline GLuint iboId(){return oIBO;}
	inline GLuint vaoId(){return oVAO;}

	inline size_t getIndexCount() { return oDrawQuant; }
private:
	GLuint oVBO;
	GLuint oIBO;
	GLuint oVAO;

	size_t oDrawQuant;
	MeshData oMeshData;
private:
	void bindModel();
};

#endif // !_MESH_H_