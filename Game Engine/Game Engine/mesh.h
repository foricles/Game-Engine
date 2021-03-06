#ifndef _MESH_H_
#define _MESH_H_

#include "utils.h"
#include "opengl.h"
#include "glprogram.h"
#include "material.hpp"

#include <string>

class Mesh
{
public:
	Mesh();
	virtual~Mesh();

	void draw();

	void loadModel(const char* filepath);
	void loadModel(const MeshData &meshData);

	void setMaterial(const Material *material);
	size_t getMaterialId() { return oMaterial; }

	inline GLuint vboId(){return oVBO;}
	inline GLuint iboId(){return oIBO;}
	inline GLuint vaoId(){return oVAO;}

	inline size_t getIndexCount() { return oMeshData.oVertexes.size(); }
private:
	GLuint oVBO;
	GLuint oIBO;
	GLuint oVAO;

	size_t oMaterial;
	MeshData oMeshData;
public:
	void bindModel();
};

#endif // !_MESH_H_