#include <iostream>
using namespace std;

void main()
{
	cout << "Choose your task: \n";
	cout << "1 - Average of 2 numbers\n";
	cout << "2 - Currency Converter\n";
	cout << "3 - Text with special symbols\n";
	cout << "4 - Pow\n";
	cout << "5 - Summ and multiply of 3 numbers\n";
	short taskNum;
	cin >> taskNum;

	if (taskNum >= 1 && taskNum <= 5 && taskNum)
	{
		if (taskNum == 1)
		{
			float firstNum{};
			float secondNum{};
			float average{};

			cout << "\x1B[2J\x1B[H";
			cout << "Enter first number: ";
			cin >> firstNum;
			cout << endl;
			cout << "Enter second number: ";
			cin >> secondNum;
			cout << endl;
			average = (firstNum + secondNum) / 2;

			cout << "The average between " << firstNum << " and " << secondNum << " is: " << average;
		}
		else if (taskNum == 2)
		{
			const float UAH_TO_USD = 0.040f;
			const float UAH_TO_EUR = 0.036f;
			const float UAH_TO_RUB = 2.54f;
			float uah{};
			int choosedType{};

			cout << "\x1B[2J\x1B[H";
			cout << "Enter your summ in UAH: ";
			cin >> uah;

			cout << "Choose your currency \n 1 - USD \n 2 - EUR \n 3 - RUB \n 4 - all \n";
			cin >> choosedType;
			switch (choosedType)
			{
			case 1:
				cout << uah << " UAH in USD is : " << uah * UAH_TO_USD << endl;
				break;
			case 2:
				cout << uah << " UAH in EUR is : " << uah * UAH_TO_EUR << endl;
				break;
			case 3:
				cout << uah << " UAH in RUB is : " << uah * UAH_TO_RUB << endl;
				break;
			case 4:
				cout << uah << " UAH in USD is : " << uah * UAH_TO_USD << endl;
				cout << uah << " UAH in EUR is : " << uah * UAH_TO_EUR << endl;
				cout << uah << " UAH in RUB is : " << uah * UAH_TO_RUB << endl;
				break;
			default:
				cout << "Choose from 1 - 4";
				break;
			}
		}
		else if (taskNum == 3)
		{
			cout << "\x1B[2J\x1B[H";
			cout << "\"To be or not to be\"" << endl;			cout << "\\ Sheakspeare \\";
		}
		else if (taskNum == 4)
		{
			cout << "\x1B[2J\x1B[H";

			float userNum{};
			cout << "Enter the number to be squared: ";
			cin >> userNum;
			cout << userNum << " * " << userNum << " = " << userNum * userNum << endl;
		}
		else if (taskNum == 5)
		{
			cout << "\x1B[2J\x1B[H";
			float firstNum{};
			float secondNum{};
			float thirdNum{};

			cout << "Enter your numbers: \n";
			cout << "First number: ";
			cin >> firstNum;
			cout << "Second number: ";
			cin >> secondNum;
			cout << "Third number: ";
			cin >> thirdNum;

			cout << firstNum << " + " << secondNum << " + " << thirdNum << " = " << firstNum + secondNum + thirdNum << endl;
			cout << firstNum << " * " << secondNum << " * " << thirdNum << " = " << firstNum * secondNum * thirdNum;
		}
	}
	else
	{
		cout << "Choose the correct number of task";
	}
}