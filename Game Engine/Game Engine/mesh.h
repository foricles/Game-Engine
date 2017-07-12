#ifndef _MESH_H_
#define _MESH_H_

#include <vectors.h>

#include <vector>
#include <algorithm>

struct vertex
{
	kmu::vec3 pPos;
	kmu::vec3 pNor;
	kmu::vec4 pCol;
};

struct Mesh
{
	std::vector<vertex> oVertexes;
	std::vector<size_t> oIndexes;
};

#endif // !_MESH_H_