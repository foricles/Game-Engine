#ifndef _VERTEXDATA_HPP_
#define _VERTEXDATA_HPP_

#include <vector>
#include <algorithm>
#include <point.hpp>

struct vertex
{
	Point3f pPos;
	Point3f pNor;
	Point4f pCol;
};

struct MeshData
{
	std::vector<vertex> oVertexes;
	std::vector<size_t> oIndexes;
};

#endif // !_VERTEXDATA_HPP_