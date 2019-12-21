#include <iostream>
#include <time.h>
#include <math.h>
#include <iomanip>
using namespace std;

int getRandomInt(int min = 0, int max = 100);
int getRandomIntRB(int min = 0, int max = 100);
float getPercentage(int all_percent, int number);
int primeNumber(int userNum);
int getMax(int array[], int arraySize);
int getMin(int array[], int arraySize);
void getAverageDifferent(double average, int thisHalf);

const int numberOfStudent = 16;

int main()
{
	srand(time(NULL));
	char taskNum{};

	while (true || taskNum != '0')
	{
		system("cls");
		cout << "Choise your task: \n";
		cout << "1 - Student`s marks\n";
		cout << "2 - 15 types of goods \n";
		cout << "3 - 10 types of goods\n";
		cout << "4 - Drawing\n";
		cout << "5 - Transposed matrix\n";
		cout << "6 - Prime numbers\n";
		cout << "7 - Weather in Kiev\n";
		cout << "8 - Two matrixs\n";
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
					cout << setw(4) << fixed << setprecision(2) << i << " : " << temp << " : " << getPercentage(numberOfMarks, temp) << '%' << endl;
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
							cout << "Good #" << setw(2) << i + 1 << " costs " << goods[i][j] << endl;
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
				const int ROWS = 10;
				const int COLS = 10;

				int taskNumber = (numberOfStudent + 4) % 10 + 1;
				int matrix[10][10] = { 0 };
				int tempCols{0}, tempMax = matrix[0][0];

				for (int i = 0; i < ROWS; i++)
				{
					for (int j = 0; j < COLS; j++)
					{
						matrix[i][j] = getRandomInt();
					}
				}


				for (int i = 0; i < ROWS; i++)
				{
					for (int j = 0; j < COLS; j++)
					{
						cout << setw(3) << matrix[i][j] << ' ';
					}
					cout << endl;
				}
				cout << endl;
				for (int i = 0; i < ROWS; i++)
				{
					for (int k = 0; k < tempCols; k++)
					{
						cout << "    ";
					}
					for (int j = tempCols; j < COLS; j++)
					{
						
						cout << setw(3) << matrix[i][j] << ' ';
						if(matrix[i][j] > tempMax) tempMax = matrix[i][j];
					}
					cout << endl;
					tempCols++;
				}

				cout << endl;
				cout << "MaxNumber:" << tempMax << endl;

			}break;
			case '5':
			{
				const int ROWS = 10;
				const int COLS = 10;

				int array[ROWS][COLS] = { 0 };
				int arrayT[ROWS][COLS] = { 0 };

				for (int i = 0; i < ROWS; i++)
				{
					for (int j = 0; j < COLS; j++)
					{
						array[i][j] = getRandomIntRB(-10, 10);
					}
				}

				for (int i = 0; i < ROWS; i++)
				{
					for (int j = 0; j < COLS; j++)
					{
						cout << setw(3) << array[i][j] << ' ';
					}
					cout << endl;
				}

				cout << endl;

				for (int i = 0; i < ROWS; i++)
				{
					for (int j = 0; j < COLS; j++)
					{
						arrayT[j][i] = array[i][j];
					}
				}

				for (int i = 0; i < ROWS; i++)
				{
					for (int j = 0; j < COLS; j++)
					{
						cout << setw(3) << arrayT[i][j] << ' ';
					}
					cout << endl;
				}
			}break;
			case '6':
			{
				const int ROWS = 5;
				const int COLS = 8;
				const int START = 100 * numberOfStudent;

				int array[ROWS][COLS] = { 0 };
				int temp = START;

				for (int i = 0; i < ROWS; i++)
				{
					for (int j = 0; j < COLS; j++)
					{				
						while(true)
						{
							if (primeNumber(temp))
							{
								cout << setw(6) << temp << ' '; //Вывод простого числа
								temp++; //Счётчик
								break;
							}
							{
								temp++; //Счётчик
							}
						}
					}
					cout << endl;
				}
			}break;
			case '7':
			{
				const int YEARS = 10;
				const int HALFS = 2;
				const int ARR_SIZE = 10 * 2;

				int numberOfPrecipitationPerHalf [ARR_SIZE] {};
				int numberOfPrecipitationPerYear [YEARS][HALFS]{};
				double average{};

				for (int i = 0; i < ARR_SIZE; i++)
				{
					numberOfPrecipitationPerHalf[i] = getRandomInt(15, 100);
				}

				int temp = 0;
				for (int i = 0; i < YEARS; i++)
				{
					for (int j = 0; j < HALFS; j++)
					{
						numberOfPrecipitationPerYear[i][j] = numberOfPrecipitationPerHalf[temp];
						temp++;
					}
				}

				/*GET AVERAGE*/
				for (int i = 0; i < YEARS; i++)
				{
					for (int j = 0; j < HALFS; j++)
					{
						temp += numberOfPrecipitationPerYear[i][j];
					}
				}
				
				average = (double)temp / ARR_SIZE;

				/*Вывод*/
				cout << "Average number of precipitation: " << average << endl;
				cout << " " << setw(25) << "January - June" << setw(25) << "July - December" << setw(15) << "Average" << endl;

				for (int i = 0; i < YEARS; i++)
				{
					temp = 0;
					cout << i + 1;
					for (int j = 0; j < HALFS; j++)
					{
						cout << setw(25) << numberOfPrecipitationPerYear[i][j];

						getAverageDifferent(average, numberOfPrecipitationPerYear[i][j]);
						temp += numberOfPrecipitationPerYear[i][j];
					}
					cout << setw(15) << (double)temp / HALFS << endl;
				}
			}break;
			case '8':
			{
				const int MIN = -20;
				const int MAX = 20;
				const int ROWS = 10;
				const int COLS = 15;
				const int ARR_MAX = ROWS * COLS;
				int posTemp = 0;
				int negTemp = 0;

				int matrix[ROWS][COLS] = { 0 };
				int posNumbers[ARR_MAX]{};
				int negNumbers[ARR_MAX]{};

				for (int i = 0; i < ROWS; i++) //Сделать функцию с заполнением
				{
					for (int j = 0; j < COLS; j++)
					{
						matrix[i][j] = getRandomIntRB(MIN, MAX);
					}
				}

				/*
					for (int i = 0; i < ROWS; i++)
					{
						for (int j = 0; j < COLS; j++)
						{
							cout << setw(3) << matrix[i][j] << ' ';
						}
						cout << endl;
					}
				*/

				for (int i = 0; i < ROWS; i++)
				{
					for (int j = 0; j < COLS; j++)
					{
						if (matrix[i][j] >= 0)
						{
							posNumbers[posTemp] = matrix[i][j];
							posTemp++;
						}
						else
						{
							negNumbers[negTemp] = matrix[i][j];
							negTemp++;
						}
					}
				}

				for (int i = 0; i < posTemp; i++)
				{
					cout << posNumbers[i] << ' ';
				}
				cout << endl << endl;
				for (int i = 0; i < negTemp; i++)
				{
					cout << negNumbers[i] << ' ';
				}

				cout << endl;
				cout << endl << getMax(posNumbers, posTemp) << endl;
				cout << endl << getMin(negNumbers, negTemp) << endl;

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

int primeNumber(int userNum)
{
	for (int i = 2; i <= sqrt(userNum); i++) //Ещё раз разобраться в этом
		if (userNum % i == 0) return false;
	return true;
}

int getMax(int array[], int arraySize)
{
	int max = array[0];
	
	for (int i = 1; i < arraySize; i++)
	{
		if (array[i] > max) max = array[i];
	}

	return max;
}

int getMin(int array[], int arraySize)
{
	int min = array[0];

	for (int i = 1; i < arraySize; i++)
	{
		if (array[i] < min) min = array[i];
	}

	return min;
}

void getAverageDifferent(double average, int thisHalf)
{
	if (thisHalf < average)
	{
		cout << "(-" << average - thisHalf << ")";
	}
	else if (thisHalf > average)
	{
		cout << "(+" << thisHalf - average << ")";
	}
	else
	{
		cout << "(0)";
	}
}