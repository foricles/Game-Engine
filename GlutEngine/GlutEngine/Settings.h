#ifndef _SETTING_H
#define _SETTING_H

#include <string>

class Settings
{
public:
	//������ ����
	static int Window_Widght;

	//������ ����
	static int Window_Height;

	//������� ���� �� �������� �� ��� �
	static int Window_Position_X;

	//������� ���� �� �������� �� ��� Y
	static int Window_Position_Y;

	//��� ����
	static std::string Window_Name;

	//�� ���� �����
	static bool Fullscreen;


	//�����������
	static bool Antialissing;

	//������������
	static bool Alfa_Chanel;

	Settings();
	~Settings();
};

#endif