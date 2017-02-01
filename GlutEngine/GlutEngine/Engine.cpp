#include "Engine.h"
#include "GUIProc.h"

//Обнуление статических переменных
void (*Engine::m_pAwake)(void)      = nullptr;
void (*Engine::m_pRunable)(void)    = nullptr;
void (*Engine::m_pShutDown)(void)   = nullptr;
/////////////////////////////////////////////

Engine::Engine(int *Argc, char** Argv, void(*Initialize)(void))
{
	GUIProc proc;

	//Инициализация настроек
	Initialize();

	//Подключить подсистему окна
	Window *wnd = new Window(Argc, Argv);
	m_Systems.insert(
		std::pair<EngSys, System*>
		(
			EngSys::WINDOW,
			dynamic_cast<System*>(wnd)
		));

	//Подключить подсистему рендера
	Render *rnd = new Render();
	m_Systems.insert(
		std::pair<EngSys, System*>
		(
			EngSys::RENDER,
			dynamic_cast<System*>(rnd)
		));

	//Подключить подсистему ввода
	Input *inp = new Input();
	m_Systems.insert(
		std::pair<EngSys, System*>
		(
			EngSys::INPUTS,
			dynamic_cast<System*>(inp)
		));

	//Подключить таймер
	Timer *timer = new Timer();
	m_Systems.insert(
		std::pair<EngSys, System*>
		(
			EngSys::TIMER,
			dynamic_cast<System*>(timer)
		));

	//Установить координатную сетку
	rnd->SetGrid2D(
		0, (float)Settings::Window_Widght,
		0, (float)Settings::Window_Height
	);
}

Engine::~Engine()
{

	m_pShutDown();
	for (auto sys = m_Systems.begin(); sys != m_Systems.end(); sys++)
		delete sys->second;
	m_Systems.clear();
}

bool Engine::GetEngine()
{
	if (
		(m_pAwake == nullptr)    ||
		(m_pRunable == nullptr)  ||
		(m_pShutDown == nullptr)   
		)
		return false;

	m_pAwake();

	glutDisplayFunc(renderer);
	glutTimerFunc(10, timer, 0);
	glutMainLoop();

	return true;
}


void Engine::SetAwakeFunk   (void(*Awake)(void))   {m_pAwake = Awake;}
void Engine::SetRunableFunc (void(*Runable)(void)) {m_pRunable = Runable;}
void Engine::SetShutDownFunc(void(*ShutDown)(void)){m_pShutDown = ShutDown;}

void Engine::timer(int t)
{
	Timer::Update();
	m_pRunable();
	glutPostRedisplay();
	glutTimerFunc(5, timer, 0);
}

void Engine::renderer()
{
	Timer::UpdateFPS();
	glClear(GL_COLOR_BUFFER_BIT);
	Render::Flush();
	glutSwapBuffers();
}
