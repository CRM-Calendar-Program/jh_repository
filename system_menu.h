#ifndef SYSTEM_MENU_H
#define SYSTEM_MENU_H
#include <iostream>
#include <windows.h>

class Display
{
private:
	int center;
	int box_x = 30;
	int box_y = 10;
public:
	void SetCursorPosition(int x, int y);
	void ShowMenu();
	void ShowClientMenu();
	void ShowDsnMenu();
	void Register();

	void CleanDisplay() { system("cls"); }
};

#endif