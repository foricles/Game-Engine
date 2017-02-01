#ifndef _GUIPROC_H
#define _GUIPROC_H

#include <vector>
#include <thread>
#include <mutex>
#include <condition_variable>

#include "../GlutEngine/System.h"
#include "../GlutEngine/UI.h"
#include "../GlutEngine/Input.h"

class GUIProc
{
	friend class Engine;
public:
	static void Register(UI *ui);
	static void Selected(const vec2 &vec);
	static void Selected(int x, int y);
private:
	static UI* m_SelectedUI;
	static std::mutex m_Mutex;
	static std::vector<UI*> m_GuiList;
	static std::thread *m_Thread;

	GUIProc();
	~GUIProc();
	static void Proces();
};

#endif // !_GUIPROC_H

