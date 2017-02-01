#ifndef _TIMER_H
#define _TIMER_H

#include <time.h>
#include "..\GlutEngine\System.h"

class Timer : private System
{
	friend class Engine;
public:
	static double deltaTime;
	static int FPS;
private:
	Timer();
	~Timer();

	static double m_PrevClock;

	static double prevTime;
	static int Frames;

	static void Update();
	static void UpdateFPS();
};


#endif // !_TIMER_H
