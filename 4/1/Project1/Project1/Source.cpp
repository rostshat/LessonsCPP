#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

float volumeOfCylinder(float radius, float height);
long maxOfThreeNums(long firstNum, long secondNum, long thirdNum);
double dohod(double deposit, double percent, int days);
double glasn(char symbol);
void symbolLine(int length, char symbol);
double resistanceOfLine(double firstResistor, double secondResistor, char type);


int main() //Åñëè ÷òî-òî íå òàê, ïðîñòî áðîñüòå íà äîðàáîòêó, ïîòîìó ÷òî 5 çàäàíèå ÿ íå ïîëíîñòüþ ïîíÿë
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
		cout << "5 - Symbol Line\n";
		cout << "6 - Resistor line\n";
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

			while (deposit <= 0 || days <= 0)
			{
				cout << "Enter your deposit: ";
				cin >> deposit;
				cout << "Enter your percent: ";
				cin >> percent;
				cout << "Enter your days: ";
				cin >> days;
				cout << endl;
			}

			cout << "After end u will have: " << dohod(deposit, percent, days) << endl;
		}break;
		case '4':
		{
			char userSymbol{};

			cout << "Enter your letter: ";
			cin >> userSymbol;

			cout << "Result: " << glasn(userSymbol) << endl;
		}break;
		case '5':
		{
			int length{};
			char userSymbol{};

			cout << "Enter your line length: ";
			cin >> length;
			cout << "Enter your symbol: ";
			cin >> userSymbol;

			symbolLine(length, userSymbol);
		}break;
		case '6':
		{
			char type{};
			double firstResistor{}, secondResistor{};

			cout << "Enter type of connection (0 - consistent; 1 - parallel): ";
			cin >> type;
			cout << "Enter resistance in 1st Resistor: ";
			cin >> firstResistor;
			cout << "Enter resistance in 2nd Resistor: ";
			cin >> secondResistor;

			cout << "R: " << resistanceOfLine(firstResistor, secondResistor, type) << endl;
		}break;

		default:
		{
			cout << "Enter a correct task nubmer\n";
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
	if (symbol == 'a' || symbol == 'e' || symbol == 'i' || symbol == 'o' || symbol == 'u' || symbol == 'A' || symbol == 'E' || symbol == 'I' || symbol == 'O' || symbol == 'U') return 1;
	return 0;
}

void symbolLine(int length, char symbol)
{
	for (int i = 0; i < length / 2; i++)
	{
		cout << symbol << '$';
	}
}

double resistanceOfLine(double firstResistor, double secondResistor, char type)
{
	return (type == '0') ? firstResistor + secondResistor : (type == '1') ? (firstResistor * secondResistor) / (firstResistor + secondResistor) : -1;
}
