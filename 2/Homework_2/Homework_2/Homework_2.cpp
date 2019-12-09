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
		cout << "3 - Even and odd\n";
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
			const int NUMBER = 25;
			const int ATTEMPTS = 10;
			int userNumber{};
			char choose{};

			cout << "Computer Made up a number from 0 to 100\n";
			cout << "Try to guess it\n";
			cout << "You have 10 attempts\n";

			while (choose != 'N') {
				for (int i = 1; i <= ATTEMPTS; i++)
				{
					cout << "Enter your number: ";
					cin >> userNumber;

					if (userNumber != NUMBER)
					{
						if (userNumber > NUMBER)
						{
							cout << "Your number is bigger than need\n";
							cout << "Left " << ATTEMPTS - i << " attempts\n";
						}
						else
						{
							cout << "Your number is smaller than need\n";
							cout << "Left " << ATTEMPTS - i << " attempts\n";
						}
					}
					else
					{
						cout << "You Won!" << endl;
						choose = 'N';
						break;
					}

					if (i == 10)
					{
						cout << "You Lost\n";
						cout << "Try again?: Y/N " << endl;
						cin >> choose;
						cout << endl;
					}
				}
			}
			cout << "The number was: " << NUMBER << endl;
		}break;
		case '3':
		{
			long long userNum{};
			int odd{}, even{};
			const int ORDER = 10;

			cout << "Enter your number: ";
			cin >> userNum;

			if (userNum < 0) userNum *= -1;

			do {
				if (userNum % 2)
				{
					odd++;
				}
				else
				{
					even++;
				}
			} while (userNum /= ORDER);

			cout << "Even: " << even << endl << "Odd: " << odd << endl;

		}break;
		case '4':
		{
			float firstNumber{}, tempNumber{}, result{};
			char sign{};

			cout << "Enter first number: ";
			cin >> firstNumber;

			while (sign != '=')
			{
				cout << "Enter next operation sign: ";
				cin >> sign;
				if (sign == '=') break;
				cout << "Enter next number: ";
				cin >> tempNumber;

				if (sign == '+')
				{
					firstNumber += tempNumber;
				}
				else if (sign == '-')
				{
					firstNumber -= tempNumber;
				}
				else if (sign == '*')
				{
					firstNumber *= tempNumber;
				}
				else if (sign == '/')
				{
					firstNumber /= tempNumber;
				}
				else
				{
					cout << "Sign isn`t correct\n";
				}

				result = firstNumber;
			}
			cout << "Result: " << firstNumber << endl;
		}break;
		case '5':
		{
			
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
