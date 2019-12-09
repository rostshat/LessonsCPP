#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <math.h>

using namespace std;

float volumeOfCylinder(float radius, float height);
long maxOfThreeNums(long firstNum, long secondNum, long thirdNum);
double dohod(double deposit, double percent, int days);
double glasn(char symbol);

int main()
{
	srand(time(NULL));
	char taskNum{};

	while (true || taskNum != '0')
	{
		system("cls");
		cout << "Choise your task: \n";
		cout << "1 - V of cylinder \n";
		cout << "2 - Max of 3 numbers \n";
		cout << "3 - Deposit calculator\n";
		cout << "4 - Glasn\n";
		cout << "4 - Calculator\n";
		cout << "6 - MaxNum x%3 == 0\n"; //Корректно назвать
		cout << "0 - Exit\n";

		cin >> taskNum;
		if (taskNum == '0') break;

		switch (taskNum)
		{
			case '1':
			{
				float radius{}, height{};

				cout << "Enter your radius: ";
				cin >> radius;
				cout << "Enter your height: ";
				cin >> height;

				if (radius <= 0 || height <= 0)
				{
					cout << "Cylinder doesn`t exist" << endl;
				}
				else
				{
					cout << volumeOfCylinder(radius, height) << endl;
				}
			}break;
			case '2':
			{
				long first{}, second{}, third{};

				cout << "Enter your numbers \n";
				cout << "First number: ";
				cin >> first;
				cout << "Second number: ";
				cin >> second;
				cout << "Third number: ";
				cin >> third;
				
				cout << maxOfThreeNums(first, second, third) << endl;
			}break;
			case '3':
			{
				double deposit{}, percent{};
				int days{};

				cout << "Enter your deposit: ";
				cin >> deposit;
				cout << "Enter your percent: ";
				cin >> percent;
				cout << "Enter your days: ";
				cin >> days;

				cout << "After end u will have: " << dohod(deposit, percent, days) << endl;
			}break;
			case '4':
			{
				char userSymbol{};

				cout << "Enter your letter: ";
				cin >> userSymbol;

				cout << "Result: " << glasn(userSymbol) << endl;
			}break;
			default:
			{

			}break;
		}
		system("pause");
	}

	return 0;
}

float volumeOfCylinder(float radius, float height)
{
	const float PI = 3.1415f;
	return PI * radius * height;
}
long maxOfThreeNums(long firstNum, long secondNum, long thirdNum)
{
	return  firstNum > secondNum ? firstNum > thirdNum ? firstNum : thirdNum : secondNum > thirdNum ? secondNum : thirdNum;

}
double dohod(double deposit, double percent, int days)
{
	const int daysInYear = 365;

	int years = days / daysInYear;

	for (int i = 0; i < years; i++)
	{
		deposit += deposit * percent / 100;
	}

	return deposit;
}

double glasn(char symbol)
{
	if (symbol == 'a' || symbol == 'e' || symbol == 'i' || symbol == 'o' || symbol == 'u') return 1;
	return 0;
}