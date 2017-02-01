#ifndef _UI_H
#define _UI_H

#include <string>

#include "Settings.h"
#include "../GlutEngine/Renderable.h"
#include "../GlutEngine/RectTransform.h"
#include "../GlutEngine/VertexArray.h"
#include "../GlutEngine/Tags.h"
#include "../GlutEngine/Colors.h"

class UI : public Renderable
{
	friend class Render;
public:
	RectTransform rectTransform;

	UI();
	UI(std::string name);
	~UI();

	bool isActive();
	void setActive(bool active);

	std::string getText();
	void setText(std::string text);
	void eraseLast();

	void setBackgroundColor(const Color &color);

	Color getTextColor();
	void setTextColor(const Color &color);

	void setPosition(const vec2 &vec);
	void setPosition(int x, int y);
	void setWidth(int w);
	void setHeight(int h);
private:
	Color m_TextColor;
	bool m_IsActive;
	std::string m_Value;

	VertexArray m_Bord;

	inline void set()
	{
		int x = rectTransform.getPosition().x;
		int y = rectTransform.getPosition().y;
		int w = rectTransform.getWidth();
		int h = rectTransform.getHeight();
		m_Bord.AddVertex(x, y);
		m_Bord.AddVertex(x, h);
		m_Bord.AddVertex(w, h);
		m_Bord.AddVertex(w, y);


		x += w*0.1;
		y += h*0.1;
		w -= w*0.1;
		h -= h*0.1;
		m_Bord.AddVertex(x, y);
		m_Bord.AddVertex(x, h);
		m_Bord.AddVertex(w, h);
		m_Bord.AddVertex(w, y);
	}
	inline void change()
	{
		int x = rectTransform.getPosition().x;
		int y = rectTransform.getPosition().y;
		int w = x + rectTransform.getWidth();
		int h = y + rectTransform.getHeight();
		m_Bord.ChangeVertex(0, x, y);
		m_Bord.ChangeVertex(1, x, h);
		m_Bord.ChangeVertex(2, w, h);
		m_Bord.ChangeVertex(3, w, y);

		int ws = Settings::Window_Widght;
		int hs = Settings::Window_Height;
		double l = sqrt(pow(hs, 2) + pow(ws, 2));

		ws = (ws / l) * 5;
		hs = (hs / l) * 5;

		x += ws;
		y += hs;
		w -= ws;
		h -= hs;
		m_Bord.ChangeVertex(4, x, y);
		m_Bord.ChangeVertex(5, x, h);
		m_Bord.ChangeVertex(6, w, h);
		m_Bord.ChangeVertex(7, w, y);
	}
};

#endif // !_UI_H
