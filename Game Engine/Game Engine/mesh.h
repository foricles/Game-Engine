#ifndef _MESH_H_
#define _MESH_H_

#include <vectors.h>

#include <vector>
#include <algorithm>

struct vertex
{
	kmu::vec3 point;
	kmu::vec3 normal;
	kmu::vec4 color;
	vertex() {}
	vertex(const kmu::vec3 &pos, const kmu::vec3 &nrm, const kmu::vec4 &clr)
		: point(pos)
		, normal(nrm)
		, color(clr)
	{}
};

class Mesh
{
public:
	Mesh();
	Mesh(size_t vq, size_t iq);
	Mesh(const Mesh &mesh);
	~Mesh();

	void setVertexes(const std::vector<vertex> &vrtx);
	void setIndexes(const std::vector<size_t> &indx);

	void addVertexes(vertex &vrtx);;
	void addIndexes(size_t indx);

	//void addVertexes(const std::vector<vertex> &vrtx);
	//void addIndexes(const std::vector<size_t> &indx);

	void resizeVertexes(size_t size);
	void resizeIndexes(size_t size);

	size_t vQuant()const { return oVertexes.size(); }
	size_t iQuant()const { return oIndexes.size(); }

	const vertex *getVertexes()const { return &oVertexes.at(0); }
	const uint32_t *getIndexes()const { return &oIndexes[0]; }
private:
	std::vector<vertex> oVertexes;
	std::vector<size_t> oIndexes;
	size_t oVadd;
	size_t oIadd;
};

#endif // !_MESH_H_