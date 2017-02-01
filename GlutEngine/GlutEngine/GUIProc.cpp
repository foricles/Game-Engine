#include "GUIProc.h"

std::vector<UI*> GUIProc::m_GuiList;
std::mutex GUIProc::m_Mutex;
std::thread *GUIProc::m_Thread = nullptr;
UI *GUIProc::m_SelectedUI = nullptr;

void GUIProc::Proces()
{
	auto ms = std::chrono::milliseconds(50);
	while (true)
	{
		std::this_thread::sleep_for(ms);

		if (Input::MouseButton(0))
				Selected(Input::MouseX(), Input::MouseY());

		if (m_SelectedUI != nullptr)
			if (Input::EnyButton())
			{
				if ((int)Input::getKey() == 8)
					m_SelectedUI->eraseLast();
				else
					if ((Input::getKey() != '\0') &&
						(*(m_SelectedUI->getText().end() - 1) != Input::getKey()))
						m_SelectedUI->setText(m_SelectedUI->getText() + Input::getKey());
			}

	}
}

GUIProc::GUIProc()
{
	m_Thread = new std::thread(Proces);
	m_Thread->detach();
}

GUIProc::~GUIProc()
{
	delete m_Thread;
}

void GUIProc::Register(UI * ui)
{
	m_GuiList.push_back(ui);
}

void GUIProc::Selected(int x, int y)
{
	for (auto ui = m_GuiList.begin(); ui != m_GuiList.end(); ui++)	
		if ((*ui)->rectTransform.Contain(x, y))
		{
			std::cout << "Selected" << std::endl;
			m_SelectedUI = (*ui);
			return;
		}
		
		m_SelectedUI = nullptr;	
		std::cout << "Unselected" << std::endl;
}


//-----------------------------------
void GUIProc::Selected(const vec2 & vec)
{
	return Selected(vec.x, vec.y);
}