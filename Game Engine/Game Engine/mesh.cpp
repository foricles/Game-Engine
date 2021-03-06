#include "mesh.h"


Mesh::Mesh()
	: oVBO(0)
	, oIBO(0)
	, oVAO(0)
	, oMaterial(EMPTY_MATERIAL)
{
	glGenVertexArrays(1, &oVAO);
	glGenBuffers(1, &oVBO);
	glGenBuffers(1, &oIBO);
}

Mesh::~Mesh()
{
	glDeleteVertexArrays(1, &oVAO);
	glDeleteBuffers(1, &oVBO);
	glDeleteBuffers(1, &oIBO);
}

void Mesh::loadModel(const char* filepath)
{
	std::vector<MeshData> pModel = utils::file::loadModel(filepath);
	bool isSingle{ pModel.size() == 1 };

	if (!isSingle)
	{

	}
	else
	{
		oMeshData = pModel[0];
	}
}

void Mesh::loadModel(const MeshData &meshData)
{
	oMeshData = meshData;
}

void Mesh::setMaterial(const Material *material)
{
	oMaterial = material->getMaterialId();
}

void Mesh::bindModel()
{
	glBindVertexArray(oVAO);

	glBindBuffer(GL_ARRAY_BUFFER, oVBO);
	glBufferData(GL_ARRAY_BUFFER,
					sizeof(vertex)*oMeshData.oVertexes.size(),
					oMeshData.oVertexes.begin()._Ptr,
					GL_STATIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, oIBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER,
					sizeof(size_t)*oMeshData.oIndexes.size(),
					oMeshData.oIndexes.begin()._Ptr,
					GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(vertex), (void*)offsetof(vertex, pPos));
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(vertex), (void*)offsetof(vertex, pNor));
	glVertexAttribPointer(2, 4, GL_FLOAT, GL_FALSE, sizeof(vertex), (void*)offsetof(vertex, pCol));
	glVertexAttribPointer(3, 2, GL_FLOAT, GL_FALSE, sizeof(vertex), (void*)offsetof(vertex, pUV));

	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);
	glEnableVertexAttribArray(2);
	glEnableVertexAttribArray(3);

	glBindVertexArray(0);
	Logger::CheckGLErrors("Mesh::bindModel");
}

void Mesh::draw()
{
	glBindVertexArray(oVAO);
	glDrawElements(GL_TRIANGLES, getIndexCount(), GL_UNSIGNED_INT, nullptr);
	glBindVertexArray(0);
	Logger::CheckGLErrors("Mesh::draw");
}