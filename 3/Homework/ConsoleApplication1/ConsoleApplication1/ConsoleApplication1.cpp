#include <iostream>
#include <stdlib.h>
#include <iomanip>
using namespace std;

void main()
{
	char taskNum{};


	while (true || taskNum != '0')
	{
		system("cls");
		cout << "Choise your task: \n";
		cout << "1 - 33 to 127 \n";
		cout << "2 - Choose the number \n";
		cout << "3 - All without 3,6\n";
		cout << "4 - Calculator\n";
		cout << "4 - Calculator\n";
		cout << "6 - MaxNum x%3 == 0\n"; //Êîððåêòíî íàçâàòü
		cout << "0 - Exit\n";

		cin >> taskNum;
		if (taskNum == '0') break;

		switch (taskNum)
		{
		case '1':
		{
			int start = 33;
			const int END = 127;
			const int MAX_WIDTH = 7;

			while (start < END) // ÎÏÒÈÌÈÇÈÐÎÂÀÒÜ
			{
				for (int i = 0; i < 7; i++)
				{
					cout << setw(4) << start << ' ';
					if (start == END) break;
					start++;

				}
				cout << endl;
			}
		}break;
		case '2':
		{

		}break;
		case '3':
		{
			int userNum{};
			int temp{};

			//bool skipFirst = (userNum % 10 == 3);
			//bool skipSecond = (userNum % 10 == 6);

			cout << "Enter your number: ";
			cin >> userNum;

			while (userNum > 0)
			{
				if (userNum % 10 != 3 &&
					userNum % 10 != 6)
				{
					temp *= 10;
					temp += userNum % 10;
				}
				userNum /= 10;
			}
			cout << "Result: ";

			while (temp > 0)
			{
				cout << temp % 10;
				temp /= 10;
			}
		}break;
		case '4':
		{
			const int SIZE = 10;
			int array[SIZE] = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512};

			for (int i = 0; i < SIZE; i++)
			{
				cout << i + 1 << " - ";
				cin >> array[i];
			}
			for (int j = SIZE - 1; j >= 0; --j)
			{
				cout << "Revers: " << j << " = " << array[j] << endl;
			}
		}
		}break;
		case '5':
		{
			const int ARR_LENGTH = 10;

			int arr[ARR_LENGTH] = { 121, 12, 14, 1261, 45, 121, 1, 121, 151, 34 };

			for (int i = 0; i < ARR_LENGTH; i++)
			{

			}
		}break;
		case '6':
		{
			const int ARRAY_SIZE = 10;
			int arr[ARRAY_SIZE] = { 156, 54, 10, 84879, 45498, 454, 564, 454, 112, 12 };
			int temp{};

			for (int i = 0; i < ARRAY_SIZE; i++)
			{
				if (!(arr[i] % 3) && arr[i] > temp) temp = arr[i];
			}

			cout << temp << endl;
		}break;
		default:
		{
			cout << "Choose correct task number\n";
		}break;
		}
		system("pause");
	}
	cout << "Bye bye";
}
