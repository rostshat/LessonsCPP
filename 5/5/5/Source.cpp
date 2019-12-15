#include <iostream>
#include <time.h>
#include <iomanip>
using namespace std;

int getRandomInt(int min = 0, int max = 100);
int getRandomIntRB(int min = 0, int max = 100);
float getPercentage(int all_percent, int number);

int main()
{
	srand(time(NULL));
	char taskNum{};

	while (true || taskNum != '0')
	{
		system("cls");
		cout << "Choise your task: \n";
		cout << "1 - Student`s marks\n";
		cout << "2 - 15 goods \n";
		cout << "3 - Deposit calculator\n";
		cout << "4 - Glasn\n";
		cout << "5 - Symbol Line\n";
		cout << "6 - Transist line\n";
		cout << "0 - Exit\n";

		cin >> taskNum;
		if (taskNum == '0') break;

		switch (taskNum)
		{
			case '1':
			{
				const int MIN_MARK = 1;
				const int MAX_MARK = 5;
				const int MARKS_PER_STUDENT= 1;

				int marks[][1] = { 0 };
				int numberOfMarks{};

				do
				{
					cout << "Enter your number of marks (more than 20): ";
					cin >> numberOfMarks;
				} while (numberOfMarks < 20);


				/*GENERATE MARKS*/
				for (int i = 0; i < numberOfMarks; i++)
				{
					for (int j = 0; j < MARKS_PER_STUDENT; j++)
					{
						marks[i][j] = getRandomIntRB(MIN_MARK, MAX_MARK);
					}
				}

				/*OUTPUT MARKS*/

				for (int i = 1; i <= MAX_MARK; i++)
				{
					int temp{};
					int sumTemp{};
					for (int j = 0; j < numberOfMarks; j++)
					{
						if(marks[j][0] == i) temp++;
					}
					cout << setw(4) << fixed << setprecision(3) << i << " : " << temp << " : " << getPercentage(numberOfMarks, temp) << '%' << endl;
				}
			}break;
			case '2':
			{
				const int NUMBER_OF_GOODS = 15;
				const int MIN_PRICE = 20;
				const int MAX_PRICE = 120;
				const int ATTRIBUTES = 1;
				const int FORMAT = 4;

				int goods[15][1] = { 0 };
				int temp{}, average{};

				for (int i = 0; i < NUMBER_OF_GOODS; i++)
				{
					for (int j = 0; j < ATTRIBUTES; j++)
					{
						goods[i][j] = getRandomIntRB(MIN_PRICE, MAX_PRICE);;
					}
				}

				for (int i = 0; i < NUMBER_OF_GOODS; i++)
				{
					for (int j = 0; j < ATTRIBUTES; j++)
					{
						temp += goods[i][j];
					}
				}

				average = temp / NUMBER_OF_GOODS;

				cout << "Avegare: " << average << endl;

				for (int i = 0; i < NUMBER_OF_GOODS; i++)
				{
					for (int j = 0; j < ATTRIBUTES; j++)
					{
						if (goods[i][j] < average)
						{
							cout << setw(FORMAT) << i + 1 << " : " << goods[i][j] << endl;
						}
					}
				}
			}break;
			case '3':
			{
				const int NUMBER_OF_GOODS = 10;
				const int MIN_PRICE = 10;
				const int MAX_PRICE = 75;
				const int ATTRIBUTES = 1;
				const int FORMAT = 4;

				int goods[10][1] = { 0 };
				int temp{}, average{}, sumTemp{};

				/*Generate prices*/
				for (int i = 0; i < NUMBER_OF_GOODS; i++)
				{
					for (int j = 0; j < ATTRIBUTES; j++)
					{
						goods[i][j] = getRandomIntRB(MIN_PRICE, MAX_PRICE);;
					}
				}

				/*Goods < 40*/
				for (int i = 0; i < NUMBER_OF_GOODS; i++)
				{
					for (int j = 0; j < ATTRIBUTES; j++)
					{
						if (goods[i][j] < 40)
						{
							temp++;
							sumTemp += goods[i][j];

							cout << "Good #" << setw(2) << i + 1 << " costs " << goods[i][j] << endl;
						}
					}
				}
				cout << endl << "Number of goods which cost under 40: " << temp << endl;
				cout << "Average price of goods which cost under 40: " << sumTemp / temp << endl;

			}break;
			case '4':
			{

			}break;
			case '5':
			{
				/*
					const int ROWS = 10;
					const int COLS = 10;

					int array[ROWS][COLS] = { 0 };

					for (int i = 0; i < ROWS; i++)
					{
						array[i] = getRandomIntRB(-10, 10);
						for (int j = 0; j < COLS; j++)
						{
							array[i][j] = getRandomIntRB(-10, 10);
						}
					}
				*/
			}break;
			case '6':
			{

			}break;
			case '7':
			{

			}break;
			case '8':
			{

			}break;
			default:
			{

			}break;
		}
		system("pause");
	}

	return 0;
}

int getRandomInt(int min, int max)
{
	return rand() % (max - min) + min;
}

int getRandomIntRB(int min, int max)
{
	return rand() % (max - min + 1) + min;
}
float getPercentage(int all_percent, int number)
{
	return (float)number / (float)all_percent * 100;
}