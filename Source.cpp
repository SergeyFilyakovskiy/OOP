#include <iostream>
#include <windows.h>
#include "Header.h"

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int Task_Number;
	do
	{
		std::cout << "~~~~~~~~~~~~~Меню:~~~~~~~~~~~~~\n" << "1. Лабораторная работа 1\n2. Лабораторная работа 2\n";
		std::cout << "3. Лабораторная работа 3\n4. Лабораторная работа 4\n" << "5. Лабораторная работа 5\n";
		std::cout << "6. Лабораторная работа 6\n7. Лабораторная работа 7\n8. Лабораторная работа 8\n" << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
		std::cin >> Task_Number;
		switch (Task_Number)
		{
			case(1):
				HeadFunction_1();
				break;

			case(2):
				HeadFunction_2();
				break;

			case(3):
				HeadFunction_3();
				break;

			case(4):

				break;

			case(5):

				break;

			case(6):

				break;

			case(7):

				break;

			case(8):

				break;

			default:
				break;
		}
	} while (Task_Number != 9);

	return 0;
}