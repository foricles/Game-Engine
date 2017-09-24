#ifndef _INPUTMANAGER_HPP_
#define _INPUTMANAGER_HPP_

#include <deque>
#include "opengl.h"
#include "Logger.h"
#include <vec2.hpp>

struct MouseInfo
{
	kmu::vec2 prevPos;
	kmu::vec2 currPos;
	kmu::vec2 deltaPos;
};

class InputManager
{
	friend class Application;
public:
	InputManager();
	virtual ~InputManager();

	virtual inline float getMousePosX();
	virtual inline float getMousePosY();
	virtual inline float getMouseDeltaPosX();
	virtual inline float getMouseDeltaPosY();
	virtual inline const kmu::vec2 &getMousePos() const;
	virtual inline const kmu::vec2 &getMouseDeltaPos() const;
private:
	MouseInfo *oMouseInfo;
private:
	void keyCallback(int key, int scancode, int action, int mods);
	void characterCallback(unsigned int codepoint, int mods);
	void cursorPositionCallback(double xpos, double ypos);
	void mouseButtonCallback(int button, int action, int mods);
	void scrollCallback(double xoffset, double yoffset);
};
#endif // !_INPUTMANAGER_HPP_
