#ifndef _INPUTMANAGER_HPP_
#define _INPUTMANAGER_HPP_

#include <map>
#include "opengl.h"
#include "Logger.h"
#include "keycodes.hpp"
#include <vec2.hpp>
#include <vec3.hpp>

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

	virtual inline bool isKeyDown(KeyCode key);
	virtual inline bool isKeyPressed(KeyCode key);
private:
	MouseInfo *oMouseInfo;
	kmu::vec3 oMouseButtons;
	std::map<GLuint, GLuint> oKeys;
private:
	void keyCallback(int key, int scancode, int action, int mods);
	void characterCallback(unsigned int codepoint, int mods);
	void cursorPositionCallback(double xpos, double ypos);
	void mouseButtonCallback(int button, int action, int mods);
	void scrollCallback(double xoffset, double yoffset);
};
#endif // !_INPUTMANAGER_HPP_
