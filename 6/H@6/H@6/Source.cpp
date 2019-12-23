#include <iostream>
#include <iomanip>
#include <time.h>
#include <stdlib.h>

using namespace std;

int main()
{
	char taskNum{};

	while (true || taskNum != '0')
	{
		system("cls");
		cout << "Choise your task: \n";
		cout << "1 - 33 to 127 \n";
		cout << "2 - Drawing \n";
		cout << "3 - All without 3,6\n";
		cout << "4 - MassRevers\n";
		cout << "4 - Calculator\n";
		cout << "5 - Difference in array\n";
		cout << "6 - MaxNum x%3 == 0\n"; //Корректно назвать
		cout << "0 - Exit\n";

		cin >> taskNum;
		if (taskNum == '0') break;

		switch (taskNum)
		{
			case '1':
			{
				
			}
		}
	}

	return 0;
}