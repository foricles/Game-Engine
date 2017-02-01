#include "Timer.h"

double Timer::deltaTime = 0.0;
double Timer::m_PrevClock = 0.0;
double Timer::prevTime=0.0;

int Timer::FPS = 0;
int Timer::Frames = 0;


Timer::Timer()
	: System("Timer",EngSys::TIMER)
{
	m_PrevClock = (double)clock();
	prevTime = (double)clock();
}

void Timer::Update()
{
	deltaTime = ((double)clock()-m_PrevClock) / 100;
	m_PrevClock = (double)clock();
}

void Timer::UpdateFPS()
{
	if ((((double)clock() - prevTime) / CLOCKS_PER_SEC) >= 1)
	{
		FPS = Frames;
		Frames = 0;
		prevTime = (double)clock();
	}
	++Frames;
}

Timer::~Timer()
{
}
