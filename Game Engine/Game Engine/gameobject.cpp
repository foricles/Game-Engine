#include "gameobject.h"


GameObject::GameObject()
	: oVBO(0)
	, oIBO(0)
	, oDrawQuant(0)
{
	glGenBuffers(1, &oVBO);
	glGenBuffers(1, &oIBO);
}

GameObject::~GameObject()
{
}

void GameObject::setData(Mesh mesh)
{
	oDrawQuant = mesh.iQuant();
	this->bind();
	glBufferData(GL_VERTEX_ARRAY, sizeof(vertex) * mesh.vQuant(), mesh.getVertexes(), GL_STATIC_DRAW);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(size_t) * mesh.iQuant(), mesh.getIndexes(), GL_STATIC_DRAW);
	
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(vertex), (void*)offsetof(vertex, point));
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(vertex), (void*)offsetof(vertex, normal));
	glVertexAttribPointer(2, 4, GL_FLOAT, GL_FALSE, sizeof(vertex), (void*)offsetof(vertex, color));
	
	this->unbind();
}

void GameObject::bind()
{
	glBindBuffer(GL_VERTEX_ARRAY, oVBO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, oIBO);
	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);
	glEnableVertexAttribArray(2);
}
void GameObject::unbind()
{
	glDisableVertexAttribArray(2);
	glDisableVertexAttribArray(1);
	glDisableVertexAttribArray(0);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	glBindBuffer(GL_VERTEX_ARRAY, 0);
}

void GameObject::draw()
{
	this->bind();

	glDrawElements(GL_TRIANGLES, oDrawQuant, GL_UNSIGNED_INT, nullptr);

	this->unbind();
}
