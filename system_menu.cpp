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

	char selection = 0;
	while (true)
	{
		while (!_kbhit()) { }
		selection = _getch();

		switch (selection)
		{
		case '1':
			ShowClientMenu();
			break;
		case '2':
			ShowMileageMenu();
			break;
		case '3':
			ShowHistoryMenu();
			break;
		case '4':
			DailyMenu();
			break;
		default:
			std::cout << "�߸��� �����Դϴ�. �ٽ� �õ��ϼ���." << std::endl;
			Sleep(1000);
		}
	}
}

void Display::ShowClientMenu()
{
	CleanDisplay();
	std::cout << "------------������-------------" << std::endl;
	std::cout << "1. ��ã��" << std::endl;
	std::cout << "2. ���߰�" << std::endl;
	std::cout << std::endl;
	
	int repeat = -1;
	char selection = 0;
	while (repeat == -1)
	{
		while (!_kbhit()) {}
		selection = _getch();

		std::string birthday;
		switch (selection)
		{
		case '1':
			std::cout << "---------------------------------" << std::endl;
			std::cout << "ã������ ���� ��������� �Է����ּ���!!" << std::endl;
			std::cout << "-> �������� ���ư����� \'m\'�� �Է��ϼ���" << std::endl;
			while (repeat == -1)
			{
				std::cout << "\n";
				std::cout << ">> ";
				std::cin >> birthday;
				if (birthday == "m")
				{
					repeat = 0;
					continue;
				}
				std::cout << std::endl;
				repeat = DB.FindClient(birthday);
				if (repeat != -1)
				{
					std::cout << "\n";
					std::cout << "�������� ���ư����� \'m\'�� �Է��ϼ���>> ";
					std::cin >> birthday;
					if (birthday == "m") ShowMenu();
					else repeat = -1;
				}
			}
			break;
		case '2':
			std::cout << "---------------------------------" << std::endl;
			std::cout << "�߰��Ϸ��� ���� ������ �Է����ּ���!!" << std::endl;
			DB.AddClient();
			ShowMenu();
		default:
			std::cout << "�߸��� �����Դϴ�. �ٽ� �õ��ϼ���." << std::endl;
			Sleep(1000);
		}
	}
	ShowMenu();
}

void Display::ShowMileageMenu()
{
	CleanDisplay();
	std::cout << "----------���ϸ��� ����-----------" << std::endl;
	std::cout << "1. ���ϸ��� �߰�" << std::endl;
	std::cout << "2. ���ϸ��� ���" << std::endl;
	std::cout << std::endl;

	int repeat = -1;
	char selection = 0;
	while (repeat == -1)
	{
		while (!_kbhit()) {}
		selection = _getch();

		std::string birthday;
		switch (selection)
		{
		case '1':
			std::cout << "---------------------------------" << std::endl;
			std::cout << "ã������ ���� ��������� �Է����ּ���!!" << std::endl;
			std::cout << "-> �������� ���ư����� \'m\'�� �Է��ϼ���" << std::endl;
			while (repeat == -1)
			{
				std::cout << "\n";
				std::cout << ">> ";
				std::cin >> birthday;
				if (birthday == "m")
				{
					repeat = 0;
					continue;
				}
				std::cout << std::endl;
				repeat = DB.FindClient(birthday);
				std::cout << std::endl;
				std::cout << "---------------------------------" << std::endl;
				int cost = 0;
				std::cout << "����� �Է����ּ��� >> ";
				std::cin >> cost;
				DB.ModifyClientMileage(repeat, cost, 0);
			}
			break;
		case '2':
			std::cout << "---------------------------------" << std::endl;
			std::cout << "ã������ ���� ��������� �Է����ּ���!!" << std::endl;
			std::cout << "-> �������� ���ư����� \'m\'�� �Է��ϼ���" << std::endl;
			while (repeat == -1)
			{
				std::cout << "\n";
				std::cout << ">> ";
				std::cin >> birthday;
				if (birthday == "m")
				{
					repeat = 0;
					continue;
				}
				std::cout << std::endl;
				repeat = DB.FindClient(birthday);
				std::cout << std::endl;
				std::cout << "---------------------------------" << std::endl;
				int cost = 0;
				std::cout << "����� �Է����ּ��� >> ";
				std::cin >> cost;
				DB.ModifyClientMileage(repeat, cost, 1);
			}
			break;
		default:
			std::cout << "�߸��� �����Դϴ�. �ٽ� �õ��ϼ���." << std::endl;
			Sleep(1000);
		}
	}
	ShowMenu();
}

void Display::ShowHistoryMenu()
{
	int repeat = -1;
	std::string birthday;
	std::cout << "---------------------------------" << std::endl;
	std::cout << "ã������ ���� ��������� �Է����ּ���!!" << std::endl;
	std::cout << "-> �������� ���ư����� \'m\'�� �Է��ϼ���" << std::endl;
	while (repeat == -1)
	{
		std::cout << "\n";
		std::cout << ">> ";
		std::cin >> birthday;
		if (birthday == "m")
		{
			repeat = 0;
			continue;
		}
		std::cout << std::endl;
		repeat = DB.FindClient(birthday);
		if (repeat != -1)
		{
			std::cout << "\n";
			std::cout << "�������� ���ư����� \'m\'�� �Է��ϼ���>> ";
			std::cin >> birthday;
			if (birthday == "m") ShowMenu();
			else repeat = -1;
		}
	}
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

int Display::GetSize(std::string filename)
{
	std::ifstream file(filename);
	if (!file.is_open())
	{
		std::cerr << "Unable to open file" << std::endl;
		return 0;
	}

	int size = 0;
	std::string line;
	while (getline(file, line))
	{
		size++;
	}

	file.close();
	return size + 10;
}