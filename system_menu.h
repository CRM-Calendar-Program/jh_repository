#ifndef SYSTEM_MENU_H
#define SYSTEM_MENU_H
#include <iostream>
#include <windows.h>
#include <conio.h>
#include <string>
#include "data_handler.h"
#include "client.h"

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
	void ShowMileageMenu();
	void ShowHistoryMenu();
	void DailyMenu();
	void Register();

	void CleanDisplay() { system("cls"); }
};

#endif