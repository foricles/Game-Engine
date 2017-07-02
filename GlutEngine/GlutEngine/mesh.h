#ifndef _MESH_H_
#define _MESH_H_

#include <vectors.h>

#include <vector>
#include <algorithm>

class vertex
{
public:
	kmu::vec3 point;
	kmu::vec4 color;
};

class Mesh
{
public:
	Mesh();
	Mesh(size_t vq, size_t iq);
	Mesh(const Mesh &mesh);
	~Mesh();

	void setVertexes(const std::vector<vertex*> &vrtx);
	void setIndexes(const std::vector<size_t> &indx);

	void addVertexes(vertex *vrtx);;
	void addIndexes(size_t indx);

	void addVertexes(const std::vector<vertex*> &vrtx);
	void addIndexes(const std::vector<size_t> &indx);

	void resizeVertexes(size_t size);
	void resizeIndexes(size_t size);

	const vertex *getVertexes() { return oVertexes[0]; }
	const uint32_t *getIndexes() { return &oIndexes[0]; }
private:
	std::vector<vertex*> oVertexes;
	std::vector<size_t> oIndexes;
	size_t oVadd;
	size_t oIadd;

	struct EntryMesh
	{
		std::vector<vertex> oVertexes;
		std::vector<size_t> oIndexes;
	};
};

#endif // !_MESH_H_