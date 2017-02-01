#ifndef _ENGINE_H
#define _ENGINE_H

#include <map>
#include <GL\glut.h>

#include "../GlutEngine/System.h"
#include "../GlutEngine/Input.h"
#include "../GlutEngine/Window.h"
#include "../GlutEngine/Render.h"
#include "../GlutEngine/Timer.h"
#include "../GlutEngine/EngSys.h"


class Engine
{
public:
	Engine(int *Argc, char **Argv, void(*Initialize)(void));
	~Engine();

	bool GetEngine();

	//Инициализация настроек
	void SetAwakeFunk     (void (*Awake)(void));
	void SetRunableFunc   (void(*Runable)(void));
	void SetShutDownFunc  (void(*ShutDown)(void));
private:
	std::map<EngSys, System*> m_Systems;

	//Указатели на фкнкции-процесы
	static void (*m_pAwake)(void);
	static void (*m_pRunable)(void);
	static void (*m_pShutDown)(void);

	//Указатели на фкнкции-процесы opengl
	static void timer(int t = 0);
	static void renderer();

};

#endif // !_ENGINE_H

