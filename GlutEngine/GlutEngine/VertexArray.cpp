#include "VertexArray.h"


bool VertexArray::IsOverflow()
{
	//переполнено ли?
	if(m_Add < m_Size)return false;//нет
	return true;//да
}

VertexArray::VertexArray(int size)
{
	m_Size = size;
	m_Add  = 0;

	//Создание масивов
	m_Vertexes = new GLfloat[m_Size*m_VCount] {0};
	m_Colors   = new GLfloat[m_Size*m_CCount] {1};
	m_Index    = new GLubyte[m_Size]{0};
}


VertexArray::~VertexArray()
{
	delete[] m_Vertexes;
	delete[] m_Colors;
	delete[] m_Index;
}

bool VertexArray::AddVertex(GLfloat x, GLfloat y, const Color & color)
{
	if (IsOverflow())return false;

	m_Vertexes[m_Add*m_VCount + 0] = x;
	m_Vertexes[m_Add*m_VCount + 1] = y;
	m_Vertexes[m_Add*m_VCount + 2] = 0;

	SetVertexColor(m_Add,
		color.Red,
		color.Green,
		color.Blue,
		color.Alpha);

	m_Index[m_Add] = m_Add;

	++m_Add;
	return true;
}

bool VertexArray::SetVertexColor(int index, GLfloat r, GLfloat g, GLfloat b, GLfloat a)
{
	if ( (index < 0) || (index > m_Size-1))
	return false;

	m_Colors[index*m_CCount + 0] = r;
	m_Colors[index*m_CCount + 1] = g;
	m_Colors[index*m_CCount + 2] = b;
	m_Colors[index*m_CCount + 3] = a;

	return true;
}

void VertexArray::ChangeVertex(int index, GLfloat x, GLfloat y)
{
	if ((index < 0) || (index > m_Size - 1))
		return;
	m_Vertexes[index*m_VCount + 0] = x;
	m_Vertexes[index*m_VCount + 1] = y;
}

vec2 VertexArray::getVertex(int index)
{
	if ((index < 0) || (index > m_Size - 1))
		return VNULL;

	return vec2(
		m_Vertexes[index*m_VCount + 0],
		m_Vertexes[index*m_VCount + 1]);
}

vec2 VertexArray::getVertexNeighbor(int index, int neighbor)
{
	if ((index < 0) || (index > m_Size - 1))return VNULL;

	if (neighbor == CLOCKWISE)
	{
			if (index == m_Size - 1)
			{
				return vec2(
					m_Vertexes[0*m_VCount + 0],
					m_Vertexes[0*m_VCount + 1]);
			}
			else
			{
				return vec2(
					m_Vertexes[(index+1)*m_VCount + 0],
					m_Vertexes[(index+1)*m_VCount + 1]);
			}
	}
	else if (neighbor == CONTER_CLOCKWISE)
	{
		if (index == 0)
		{
			return vec2(
				m_Vertexes[(m_Size - 1) * m_VCount + 0],
				m_Vertexes[(m_Size - 1) * m_VCount + 1]);
		}
		else
		{
			return vec2(
				m_Vertexes[(index - 1)*m_VCount + 0],
				m_Vertexes[(index - 1)*m_VCount + 1]);
		}
	}
		else return VNULL;
}

Color VertexArray::getVertexColor(int index)
{
	if ((index < 0) || (index > m_Size - 1))
		return Color(0.0f, 0.0f, 0.0f, 0.0f);
	
	return Color(
		m_Colors[index*m_CCount + 0],
		m_Colors[index*m_CCount + 1],
		m_Colors[index*m_CCount + 2],
		m_Colors[index*m_CCount + 3]);

}

//--------------------------------------------------------------------------------------------------------
int VertexArray::getVertexCount() { return m_VCount; }
int VertexArray::getColorCount() { return m_CCount; }
int VertexArray::getSize() { return m_Size; }

const GLfloat * VertexArray::getVertexArray() { return m_Vertexes; }
const GLfloat * VertexArray::getColorArray() { return m_Colors; }
const GLubyte * VertexArray::getIndexArray() { return m_Index; }
//--------------------------------------------------------------------------------------------------------
void VertexArray::ChangeVertex(int index, const vec2 & value) { ChangeVertex(index, value.x, value.y); }
bool VertexArray::AddVertex(GLfloat x, GLfloat y) { return AddVertex(x, y, Color(1.0f, 1.0f, 1.0f, 1.0f)); }
bool VertexArray::AddVertex(const vec2 & point) { return AddVertex(point.x, point.y); }
bool VertexArray::AddVertex(const vec2 & point, const Color & color) { return AddVertex(point.x, point.y, color); }
bool VertexArray::SetVertexColor(int index, const Color & color) { return SetVertexColor(index, color.Red, color.Green, color.Blue, color.Alpha); }