#include "UI.h"
#include "../GlutEngine/GUIProc.h"
UI::UI()
	: Renderable("UI", Tags::USERINTERFACE, 0)
	, m_TextColor(Colors::Black())
	, m_IsActive(false)
	, m_Bord(8)
	, rectTransform(0.0, 0.0, 150, 50)
{
	set();
	m_Value = m_Name;
	GUIProc::Register(this);
}
UI::UI(std::string name)
	: Renderable(name, Tags::USERINTERFACE, 0)
	, m_TextColor(Colors::Black())
	, m_IsActive(false)
	, m_Bord(8)
	, rectTransform(0.0, 0.0, 150, 50)
{
	set();
	m_Value = m_Name;
	GUIProc::Register(this);
}

UI::~UI()
{}

bool UI::isActive()
{
	return m_IsActive;
}
void UI::setActive(bool active)
{
	m_IsActive = active;
}

std::string UI::getText()
{
	return m_Value;
}
void UI::setText(std::string text)
{
	m_Value = text;
}

void UI::setBackgroundColor(const Color & color)
{
	for (int i(0); i < 4; i++)
		m_Bord.SetVertexColor(i, color);
	Color cl = color;
	cl.Red   += cl.Red   * 0.75;
	cl.Blue  += cl.Blue  * 0.75;
	cl.Green += cl.Green * 0.75;
	for (int i(4); i < 8; i++)
		m_Bord.SetVertexColor(i, cl);

}

Color UI::getTextColor()
{
	return m_TextColor;
}
void UI::setTextColor(const Color & color)
{
	m_TextColor = color;
}

void UI::setPosition(const vec2 & vec)
{
	rectTransform.setPosition(vec);
	change();
}

void UI::setPosition(int x, int y)
{
	rectTransform.setPosition(x, y);
	change();
}

void UI::setWidth(int w)
{
	rectTransform.setWidth(w);
	change();
}

void UI::setHeight(int h)
{
	rectTransform.setHeight(h);
	change();
}

void  UI::eraseLast()
{
	if(m_Value.length() > 0)
	m_Value.pop_back();
}