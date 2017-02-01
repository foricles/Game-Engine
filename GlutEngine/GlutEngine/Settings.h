#ifndef _SETTING_H
#define _SETTING_H

#include <string>

class Settings
{
public:
	//Ширина окна
	static int Window_Widght;

	//Высота окна
	static int Window_Height;

	//Позиция окна на мониторе по оси Х
	static int Window_Position_X;

	//Позиция окна на мониторе по оси Y
	static int Window_Position_Y;

	//Имя окна
	static std::string Window_Name;

	//На весь екран
	static bool Fullscreen;


	//Сглаживание
	static bool Antialissing;

	//Прозрачность
	static bool Alfa_Chanel;

	Settings();
	~Settings();
};

#endif