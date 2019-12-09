#include <iostream>
#include <stdlib.h>
#include <iomanip>
using namespace std;

void main()
{
	srand(time(NULL))	;
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
			const int END = 127;
			const int MAX_WIDTH = 7;
			const int FORMAT = 7;

			int start = 33;

			while (start < END) // ÎÏÒÈÌÈÇÈÐÎÂÀÒÜ
			{
				for (int i = 0; i < MAX_WIDTH; i++)
				{
					cout << setw(FORMAT) << start << ' ';
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
			const int arrLength = SIZE - 1;
			int arr[SIZE] = { };

			for (int i = 0; i < SIZE; i++)
			{
				arr[i] = rand() % 100;
				cout << arr[i] << ' ';
			}
			cout << endl;
			for(int i = arrLength; i >= 0; i--)
			{
				cout << arr[i] << ' ';
			}
		}break;
		case '5':
		{
			const int SIZE = 10;

			int arr[SIZE] = {};
			int odd{};
			int even{};

			for (int i = 0; i < SIZE; i++)
			{
				arr[i] = rand() % 100;
			}

			for (int i = 0; i < SIZE; i++)
			{
				if (arr[i] % 2 == 0) {
					even -= arr[i];
				}
				else {
					odd -= arr[i];
				}
			}
			cout << "Difference even : " << even << '\n';
			cout << "Difference odd : " << odd << "\n";
		}break;
		case '6':
		{
			const int SIZE = 10;
			int arr[SIZE] = {};
			int temp{};

			for (int i = 0; i < SIZE; i++)
			{
				arr[i] = rand() % 100;
			}

			for (int i = 0; i < SIZE; i++)
			{
				if (!(arr[i] % 3) && arr[i] > temp) temp = arr[i];
			}
			(!(temp % 3) && temp != 0) ? cout << temp << endl : cout << "The number doesn`t exist in this array" << endl;


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
