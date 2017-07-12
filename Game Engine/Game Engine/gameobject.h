#ifndef _RENDERMODEL_H_
#define _RENDERMODEL_H_

#include "mesh.h"
#include "transform.h"
#include "utils.h"

#include <GLEW\glew.h>

class GameObject
{
public:
	GameObject();
	virtual ~GameObject();

	void bind();
	void unbind();
	void draw();
	void loadModel(const char* filepath);

	Transform &transform() { return oTransform; }
	kmu::mat4 transMatrix() { return oTransform.transMatrix(); }
private:
	GLuint oVBO;
	GLuint oIBO;
	Transform oTransform;
	size_t oDrawQuant;
};

#endif // !_RENDERMODEL_H_