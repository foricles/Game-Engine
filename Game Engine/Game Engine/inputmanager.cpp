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

#pragma region Mouse Getters
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
#pragma endregion

inline bool InputManager::isKeyDown(KeyCode key)
{
	GLuint code = (GLuint)key;
	if (oKeys.find(code) != oKeys.end())
	{
		return oKeys[code] == GLFW_PRESS;
	}
	else
	{
		oKeys.insert(std::pair<GLuint, GLuint>(code, GLFW_RELEASE));
		return false;
	}
}

inline bool InputManager::isKeyPressed(KeyCode key)
{
	GLuint code = (GLuint)key;
	if (oKeys.find(code) != oKeys.end())
	{
		return oKeys[code] == GLFW_REPEAT || oKeys[code] == GLFW_PRESS;
	}
	else
	{
		oKeys.insert(std::pair<GLuint, GLuint>(code, GLFW_RELEASE));
		return false;
	}
}

#pragma region Callbacks
void InputManager::keyCallback(int key, int scancode, int action, int mods)
{
	if (oKeys.find(key) == oKeys.end())
		oKeys.insert(std::pair<GLuint, GLuint>(key, action));
	else
		oKeys[key] = action;
}

void InputManager::characterCallback(unsigned int codepoint, int mods)
{
	//Logger::Log(conv(codepoint));
}

void InputManager::cursorPositionCallback(double xpos, double ypos)
{
	oMouseInfo->prevPos		= oMouseInfo->currPos;
	oMouseInfo->currPos		= kmu::vec2(xpos, ypos);
	oMouseInfo->deltaPos	= oMouseInfo->currPos - oMouseInfo->prevPos;
}

void InputManager::mouseButtonCallback(int button, int action, int mods)
{
	//GLFW_MOUSE_BUTTON_LEFT	= GLFW_MOUSE_BUTTON_1
	//GLFW_MOUSE_BUTTON_MIDDLE	= GLFW_MOUSE_BUTTON_3
	//GLFW_MOUSE_BUTTON_RIGHT	= GLFW_MOUSE_BUTTON_2
	if(button <= 3)
		oMouseButtons[button] == action;
}

void InputManager::scrollCallback(double xoffset, double yoffset)
{
}
#pragma endregion