#include "inputmanager.hpp"

InputManager::InputManager()
	: oMouseInfo(nullptr)
{
	oMouseInfo = new MouseInfo();
}

InputManager::~InputManager()
{
	delete oMouseInfo;
}

inline float InputManager::getMousePosX()
{
	return oMouseInfo->currPos.x;
}
inline float InputManager::getMousePosY()
{
	return oMouseInfo->currPos.y;
}
inline float InputManager::getMouseDeltaPosX()
{
	return oMouseInfo->deltaPos.x;
}
inline float InputManager::getMouseDeltaPosY()
{
	return oMouseInfo->deltaPos.y;
}
inline const kmu::vec2 & InputManager::getMousePos() const
{
	return oMouseInfo->currPos;
}
inline const kmu::vec2 & InputManager::getMouseDeltaPos() const
{
	return oMouseInfo->deltaPos;
}

void InputManager::keyCallback(int key, int scancode, int action, int mods)
{
	
}

void InputManager::characterCallback(unsigned int codepoint, int mods)
{
	
}

void InputManager::cursorPositionCallback(double xpos, double ypos)
{
	oMouseInfo->prevPos		= oMouseInfo->currPos;
	oMouseInfo->currPos		= kmu::vec2(xpos, ypos);
	oMouseInfo->deltaPos	= oMouseInfo->currPos - oMouseInfo->prevPos;
}

void InputManager::mouseButtonCallback(int button, int action, int mods)
{
}

void InputManager::scrollCallback(double xoffset, double yoffset)
{
}
