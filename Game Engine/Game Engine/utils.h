#ifndef _UTILS_H_
#define _UTILS_H_

#include "mesh.h"
#include "Logger.h"

#include <ASSIMP\Importer.hpp>
#include <ASSIMP\postprocess.h>
#include <ASSIMP\scene.h>

namespace utils
{
#define MY_PI 3.1415926535897932f
	namespace file
	{
		inline const char *load_file(const char *filepath, const char* mode = "rt")
		{
			FILE *file = fopen(filepath, mode);
			if (file == nullptr)
			{
				Logger::Log("Can not open " + std::string(filepath), LogType::ERR);
				return nullptr;
			}
			fseek(file, 0, SEEK_END);
			unsigned int length = ftell(file);
			char* text = new char[length + 1];
			memset(text, 0, length + 1);
			fseek(file, 0, SEEK_SET);
			fread(text, sizeof(char), length, file);
			fclose(file);
			return text;
		}

		inline std::vector<Mesh*> loadModel(const char* filename)
		{
			std::vector<Mesh*> oMeshes;
			Assimp::Importer importer;

			auto set = aiProcess_Triangulate 
					 | aiProcess_CalcTangentSpace 
					 | aiProcess_GenNormals;
			register const aiScene *scene = importer.ReadFile(filename, set);
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
						const aiVector3D* pNor = &(paiMesh->mNormals[j]);

						vertex vtx;
					//set coordinates
						vtx.point = kmu::vec3(pPos->x, pPos->y, pPos->z);
					//set colors
						vtx.color = kmu::vec4(1.0f, 0.0f, 1.0f, 1.0f);
					//set normals
						vtx.normal = kmu::vec3(pNor->x, pNor->y, pNor->z);

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
			return oMeshes;
		}
	}

	namespace math
	{
		inline float to_radian(float x) { return ( x * MY_PI / 180.0f); }
		inline float to_degree(float x) { return ( x * 180.0f / MY_PI); }
	}
}

#endif // !_UTILS_H_
