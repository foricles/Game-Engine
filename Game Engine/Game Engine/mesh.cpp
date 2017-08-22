#include "mesh.h"


Mesh::Mesh()
	: oVBO(0)
	, oIBO(0)
{
	glGenBuffers(1, &oVBO);
	glGenBuffers(1, &oIBO);
}

Mesh::~Mesh()
{
	glDeleteBuffers(1, &oVBO);
	glDeleteBuffers(1, &oIBO);
}

void Mesh::loadModel(const char* filepath)
{
	std::vector<Mesh> pModel = utils::file::loadModel(filepath);
	bool isSingle{ pModel.size() == 1 };
	Mesh singleModel;

	if (!isSingle)
	{

	}
	else
	{
		singleModel = pModel[0];
	}
	oDrawQuant = singleModel.oIndexes.size();

	glBindBuffer(GL_ARRAY_BUFFER, oVBO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, oIBO);

	glBufferData(GL_ARRAY_BUFFER, sizeof(vertex)*singleModel.oVertexes.size(), &singleModel.oVertexes[0], GL_STATIC_DRAW);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(size_t)*singleModel.oIndexes.size(), &singleModel.oIndexes[0], GL_STATIC_DRAW);

	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);
	glEnableVertexAttribArray(2);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(vertex), (void*)offsetof(vertex, pPos));
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(vertex), (void*)offsetof(vertex, pNor));
	glVertexAttribPointer(2, 4, GL_FLOAT, GL_FALSE, sizeof(vertex), (void*)offsetof(vertex, pCol));

	glDisableVertexAttribArray(2);
	glDisableVertexAttribArray(1);
	glDisableVertexAttribArray(0);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void Mesh::bind()
{
	glBindBuffer(GL_ARRAY_BUFFER, oVBO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, oIBO);

	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);
	glEnableVertexAttribArray(2);
}
void Mesh::unbind()
{
	glDisableVertexAttribArray(2);
	glDisableVertexAttribArray(1);
	glDisableVertexAttribArray(0);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void Mesh::draw()
{
	bind();
	glDrawElements(GL_TRIANGLES, oDrawQuant, GL_UNSIGNED_INT, nullptr);
	unbind();
}