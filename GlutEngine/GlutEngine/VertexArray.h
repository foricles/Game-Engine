#ifndef _VERTEXTARRAY_H
#define _VERTEXTARRAY_H

#include <GL\glut.h>
#include "../GlutEngine/Vector2.h"
#include "../GlutEngine/Color.h"

#define CLOCKWISE 0
#define CONTER_CLOCKWISE 1

class VertexArray
{
protected:
	//Размер масивов
	int m_Size;
	int m_Add;

	//Количество координат в масиве
	const int m_VCount = 3;
	const int m_CCount = 4;

	bool IsOverflow();

	GLfloat *m_Vertexes;
	GLfloat *m_Colors;
	GLubyte *m_Index;
public:
	VertexArray(int size);
	virtual ~VertexArray();

	int getVertexCount();
	int getColorCount();
	int getSize();

	bool AddVertex(GLfloat x, GLfloat y);
	bool AddVertex(const vec2 &point);

	bool AddVertex(GLfloat x, GLfloat y, const Color &color);
	bool AddVertex(const vec2 &point, const Color &color);

	bool SetVertexColor(int index, GLfloat r, GLfloat g,GLfloat b, GLfloat a=1 );
	bool SetVertexColor(int index, const Color &color);

	void ChangeVertex(int index, const vec2 &value);
	void ChangeVertex(int index, GLfloat x, GLfloat y);

	const GLfloat *getVertexArray();
	const GLfloat *getColorArray();
	const GLubyte *getIndexArray();

	vec2 getVertex(int index);
	vec2 getVertexNeighbor(int index, int neighbor = 0);
	Color getVertexColor(int index);

	void operator==(VertexArray &varray)
	{
		if (m_Size != varray.getSize())return;

		for (int i(0); i < m_Size; i++)
		{
			m_Vertexes[i] = varray.m_Vertexes[i];
			m_Colors[i] = varray.m_Colors[i];
			m_Index[i]  = varray.m_Index[i];
		}
	}

	void PrintMass()
	{
		for (int i(0); i < m_Size*m_VCount; i++)
			std::cout << m_Vertexes[i] << " ";
		std::cout << std::endl;
		for (int i(0); i < m_Size*m_CCount; i++)
			std::cout << m_Colors[i] << " ";
		std::cout << std::endl;
		for (int i(0); i < m_Size; i++)
			std::cout << (int)m_Index[i] << " ";
		std::cout << std::endl;
	}
};

#endif // !_VERTEXTARRAY_H