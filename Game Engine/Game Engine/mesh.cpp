#include "mesh.h"

Mesh::Mesh()
	: oVadd(0)
	, oIadd(0)
{
}

Mesh::Mesh(size_t vq, size_t iq)
	: oVadd(0)
	, oIadd(0)
{
	oVertexes.resize(vq);
	oIndexes.resize(iq);
}

Mesh::Mesh(const Mesh & mesh)
	: oVertexes(mesh.oVertexes)
	, oIndexes(mesh.oIndexes)
	, oVadd(mesh.oVertexes.size())
	, oIadd(mesh.oIndexes.size())
{
}

Mesh::~Mesh()
{
}

void Mesh::setVertexes(const std::vector<vertex> &vrtx)
{
	oVertexes.clear();
	oVertexes = vrtx;
	oVadd = oVertexes.size();
}

void Mesh::setIndexes(const std::vector<size_t>& indx)
{
	oIndexes.clear();
	oIndexes = indx;
	oIadd = oIndexes.size();
}

void Mesh::addVertexes(vertex &vrtx)
{
	if (oVadd == oVertexes.size())
		oVertexes.emplace_back(vrtx);
	else
		oVertexes.at(oVadd) = vrtx;
	oVadd++;
}

void Mesh::addIndexes(size_t indx)
{
	if (oIadd == oIndexes.size())
		oIndexes.push_back(indx);
	else
		oIndexes[oIadd] = indx;
	oIadd++;
}

//void Mesh::addVertexes(const std::vector<vertex> &vrtx)
//{
//	std::vector<vertex> mrg;
//	mrg.resize(oVertexes.size() + vrtx.size());
//	std::merge(oVertexes.begin(), oVertexes.end(), vrtx.begin(), vrtx.end(), mrg.begin());
//	oVertexes.clear();
//	oVertexes = mrg;
//}
//
//void Mesh::addIndexes(const std::vector<size_t>& indx)
//{
//	std::vector<size_t> mrg;
//	mrg.resize(oIndexes.size() + indx.size());
//	std::merge(oIndexes.begin(), oIndexes.end(), indx.begin(), indx.end(), mrg.begin());
//	oIndexes.clear();
//	oIndexes = mrg;
//}

void Mesh::resizeVertexes(size_t size)
{
	oVertexes.resize(size);
	oVadd = size;
}

void Mesh::resizeIndexes(size_t size)
{
	oIndexes.resize(size);
	oIadd = size;
}