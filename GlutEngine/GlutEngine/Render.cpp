#include "Render.h"

std::vector<Renderable*> *Render::buffer = nullptr;
bool Render::m_Sort = true;

Render::Render()
	: System("Render",EngSys::RENDER)
{
	buffer = new std::vector<Renderable*>;
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	//¬ключить или выключить сглаживание
	if (Settings::Antialissing)
	{
		glEnable(GL_POINT_SMOOTH);
		glHint(GL_POINT_SMOOTH_HINT, GL_LINEAR);

		glEnable(GL_LINE_SMOOTH);
		glHint(GL_LINE_SMOOTH_HINT, GL_LINEAR);

		glEnable(GL_POLYGON_SMOOTH);
		glHint(GL_POLYGON_SMOOTH_HINT, GL_LINEAR);
	}
}

Render::~Render()
{
	delete buffer;
}


void Render::SetGrid2D(float left, float right, float bottom, float top)
{
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glMatrixMode(GL_PROJECTION);
	glOrtho(left, right, bottom, top, -1, 1);
}

bool Render::comp( Renderable * rend1,  Renderable * rend2)
{
	return (rend1->getLayer() > rend2->getLayer());
}

void Render::Add(Renderable * renderable)
{
	buffer->push_back(renderable);
	m_Sort = true;
}

void Render::Flush()
{
	glEnableClientState(GL_COLOR_ARRAY);
	glEnableClientState(GL_VERTEX_ARRAY);

	if (m_Sort == true)
	{
		std::sort(buffer->begin(), buffer->end(), comp);
		m_Sort = false;
	}

	for (auto t = buffer->begin(); t != buffer->end(); t++)
	{

		if((*t)->getTag() == Tags::SOLIDOBJ)
		{
			RenderShape *shape = dynamic_cast<RenderShape*>(*t);

			glPushMatrix();
			glTranslatef(shape->transform.getPosition().x,
				         shape->transform.getPosition().y,
				         0);
			glScalef(shape->transform.getScale().x,
				     shape->transform.getScale().y, 
				     0);
			glRotated(shape->transform.getAngle(), 0.0, 0.0, 1.0);

			glVertexPointer(shape->m_VArray.getVertexCount(), GL_FLOAT, 0, shape->m_VArray.getVertexArray());
			glColorPointer(shape->m_VArray.getColorCount(), GL_FLOAT, 0, shape->m_VArray.getColorArray());
			glDrawElements(GL_LINE_STRIP, shape->m_VArray.getSize(), GL_UNSIGNED_BYTE, shape->m_VArray.getIndexArray());
			glPopMatrix();
		}
		  else
			if ((*t)->getTag() == Tags::USERINTERFACE)
			{
				UI *ui = dynamic_cast<UI*>(*t);

				glVertexPointer(ui->m_Bord.getVertexCount(), GL_FLOAT, 0, ui->m_Bord.getVertexArray());
				glColorPointer(ui->m_Bord.getColorCount(), GL_FLOAT, 0, ui->m_Bord.getColorArray());
				glDrawElements(GL_QUADS, ui->m_Bord.getSize(), GL_UNSIGNED_BYTE, ui->m_Bord.getIndexArray());

				std::string v = ui->getText();

				int x = ui->rectTransform.getPosition().x;
				int y = ui->rectTransform.getPosition().y;
				int w = ui->rectTransform.getWidth()/2;
				int h = ui->rectTransform.getHeight() / 2;

				glPushMatrix();
				glRasterPos2i( (x+w) - (v.length()/2 * 12) + 1,
					           (y+h) -11);

				const char* string = v.c_str();
				while (*string)
				{
					glColor3f(ui->m_TextColor.Red, ui->m_TextColor.Green, ui->m_TextColor.Blue);
					glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *string++);
				}
				glPopMatrix();

			}

	}

	glDisableClientState(GL_COLOR_ARRAY);
	glDisableClientState(GL_VERTEX_ARRAY);
}

