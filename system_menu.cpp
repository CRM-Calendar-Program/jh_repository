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
	std::cout << "1. ������" << std::endl;
	std::cout << "2. ���ϸ��� ����" << std::endl;
	std::cout << "3. ���� �����丮" << std::endl;
	// std::cout << "4. ��������" << std::endl;

	SetCursorPosition(0, 5);
	std::cout << "---------������ ����----------" << std::endl;

	SetCursorPosition(0, 6);
	// ������ �����κ� ���

	while (true)
	{
		if (_kbhit)
		{
			int ch = _getch();

		}
	}
}

void Display::ShowClientMenu()
{
	CleanDisplay();
	std::cout << "------------������-------------" << std::endl;
	std::cout << "1. ��ã��" << std::endl;
	std::cout << "2. ���߰�" << std::endl;

	// �Է� �ް� �׿� �ش��ϴ� ��� �߰�
}

void Display::ShowMileageMenu()
{
	std::string birthday;

	CleanDisplay();
	std::cout << "----------���ϸ��� ����-----------" << std::endl;
	std::cout << "�� ������� : ";
	std::cin >> birthday;

	
}

void Display::ShowHistoryMenu()
{
	
}

void Display::DailyMenu()
{
	// �߰��� �κ�
}

void Display::Register()
{
	SetCursorPosition(0, 5);
	std::cout << "---------������ ����----------" << std::endl;
	std::cout << "��";
	for (int i = 0; i < box_x; i++)
		std::cout << "��";
	std::cout << "��";

	for (int i = 7; i < box_y + 10; i++)
	{
		SetCursorPosition(0, i);
		std::cout << "��";
		SetCursorPosition(box_x + 1, i);
		std::cout << "��";
	}

	SetCursorPosition(0, box_y + 9);
	std::cout << "��";
	for (int i = 0; i < box_x; i++)
		std::cout << "��";
	std::cout << "��";
}