#include "system_menu.h"

void Display::SetCursorPosition(int x, int y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void Display::ShowMenu()
{
	CleanDisplay();
	SetCursorPosition(0, 0);
	std::cout << "------------Menu-------------" << std::endl;
	std::cout << "1. 고객관리" << std::endl;
	std::cout << "2. 마일리지 관리" << std::endl;
	std::cout << "3. 통계" << std::endl;

	SetCursorPosition(0, 5);
	std::cout << "---------오늘의 일정----------" << std::endl;
	std::cout << "┌";
	for (int i = 0; i < box_x; i++)
		std::cout << "─";
	std::cout << "┐";

	for (int i = 7; i < box_y + 10; i++)
	{
		SetCursorPosition(0, i);
		std::cout << "│";
		SetCursorPosition(box_x + 1, i);
		std::cout << "│";
	}

	SetCursorPosition(0, box_y + 9);
	std::cout << "└";
	for (int i = 0; i < box_x; i++)
		std::cout << "─";
	std::cout << "┘";
}

void Display::ShowMemMenu()
{

}

void Display::ShowDsnMenu()
{

}

void Display::Register()
{

}