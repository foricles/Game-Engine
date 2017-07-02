#ifndef _MESHLOADER_H_
#define _MESHLOADER_H_

#include "mesh.h"
#include "Logger.h"

#include <ASSIMP\Importer.hpp>
#include <ASSIMP\postprocess.h>
#include <ASSIMP\scene.h>

class MeshLoader
{
public:
	MeshLoader();
	~MeshLoader();

	void load(const char* filename);
	const std::vector<Mesh*> &getMeshes() { return oMeshes; }
private:
	std::vector<Mesh*> oMeshes;
};

#endif // !_MESHLOADER_H_