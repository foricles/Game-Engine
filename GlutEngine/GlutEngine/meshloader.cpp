#include "meshloader.h"



MeshLoader::MeshLoader()
{
}


MeshLoader::~MeshLoader()
{
}

void MeshLoader::load(const char * filename)
{
	Assimp::Importer importer;

	register const aiScene *scene = importer.ReadFile(filename, aiProcess_Triangulate);
	if (scene)
	{
		oMeshes.resize(scene->mNumMeshes);
		for (register size_t i(0); i < scene->mNumMeshes; ++i)
		{
			const aiMesh* paiMesh = scene->mMeshes[i];

			//Load vertexes
			Mesh *mesh = new Mesh(paiMesh->mNumVertices, paiMesh->mNumFaces * 3);
			for (register size_t j = 0; j < paiMesh->mNumVertices; j++)
			{
				const aiVector3D* pPos = &(paiMesh->mVertices[j]);
				vertex *vtx = new vertex();
				vtx->point = kmu::vec3(pPos->x, pPos->y, pPos->z);
				mesh->addVertexes(vtx);
			}

			//Load indexes
			for (register size_t j = 0; j < paiMesh->mNumFaces; j++)
			{
				const aiFace& Face = paiMesh->mFaces[j];
				mesh->addIndexes(Face.mIndices[0]);
				mesh->addIndexes(Face.mIndices[1]);
				mesh->addIndexes(Face.mIndices[2]);
			}

			oMeshes[i] = mesh;
		}
	}
	else
		Logger::Log("Mesh: '" + std::string(filename) + "' can`t be loaded!", LogType::ERR);
}
