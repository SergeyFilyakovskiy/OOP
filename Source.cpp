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
		std::cout << "~~~~~~~~~~~~~����:~~~~~~~~~~~~~\n" << "1. ������������ ������ 1\n2. ������������ ������ 2\n";
		std::cout << "3. ������������ ������ 3\n4. ������������ ������ 4\n" << "5. ������������ ������ 5\n";
		std::cout << "6. ������������ ������ 6\n7. ������������ ������ 7\n8. ������������ ������ 8\n" << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
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