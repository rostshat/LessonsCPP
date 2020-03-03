#include <iostream>
#include <time.h>
#include <conio.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define DEFAULT_SIZE 10
#define DEFAULT_LINE_SIZE 50
#define MIN 0
#define MAX 100
#define LINE cout << "**********************\n"
#define ARRAY_START 0
#define WRAP cout << endl

using namespace std;

template <typename T>
T getRandom(T min, T max, int order = 1);

void deleteUnitByIndex(char*& line, const int pos);
bool deleteUnitByName(char*& line, const char symbol);

int main()
{
	srand(time(NULL));
	char* taskNum = new char;

	while (true && *taskNum != '0')
	{
		system("cls");

		cout << "1 - Task" << endl;
		cout << "2 - Task" << endl;
		cout << "3 - Task" << endl;
		cout << "4 - Task" << endl;
		cout << "5 - Task" << endl;
		cout << "6 - Task" << endl;
		cout << "7 - Task" << endl;
		cout << "8 - Task" << endl;
		cout << "0 - Exit" << endl;
		cin >> *taskNum;

		switch (*taskNum)
		{
			case'1':
			{
				char* line = new char[DEFAULT_LINE_SIZE];
				int index;

				if (line)
				{
					cin.ignore(1, '\n');
					cout << "Enter your line: ";
					gets_s(line, DEFAULT_LINE_SIZE);
					cout << line << endl;

					cout << "Enter the index of unit for deleting: ";
					cin >> index;

					deleteUnitByIndex(line, index);
					cout << line << endl;

					delete[] line;
				}

				break;
			}
			case '2':
			{
				char* line = new char[DEFAULT_LINE_SIZE];
				char symbol;

				if (line)
				{
					cin.ignore(1, '\n');
					cout << "Enter your line: ";
					gets_s(line, DEFAULT_LINE_SIZE);
					cout << line << endl;

					cout << "Enter the symbol of unit for deleting: ";
					cin >> symbol;

					deleteUnitByName(line, symbol);
					cout << line << endl;

					delete[] line;
				}


				break;
			}
			case '3':
			{
				

				break;
			}
			case '4':
			{

				break;
			}
			case '5':
			{

				break;
			}
			case '6':
			{

				break;
			}
			case '7':
			{

				break;
			}
			case '8':
			{

				break;
			}
			default:
			{
				break;
			}
		}
		system("pause");
	}

	return 0;
}

template <typename T>
T getRandom(T min, T max, int order)
{
	return (T)(rand() % (((int)max - (int)min) * order) + min * order) / order;
}

void deleteUnitByIndex(char*& line, const int index)
{
	if (strlen(line) < index)
		return;

	char* newLine = new char[strlen(line)];

	if (newLine)
	{
		for (int i = 0, j = 0; i < strlen(line); ++i, j++)
		{
			if (i != index)
			{
				*(newLine + j) = *(line + i);
			}
			else
			{
				--j;
			}
		}

		newLine[strlen(line) - 1] = '\0';

		delete[] line;
		line = newLine;
	}
}

bool deleteUnitByName(char*& line, const char symbol)
{
	int counter{};
	for (int i = 0; i < strlen(line); i++)
	{
		if (line[i] == symbol) counter++;
	}

	char* newLine = new char[strlen(line) - counter];

	if (newLine)
	{
		for (int i = 0, j = 0; i < strlen(line); ++i, j++)
		{
			if (i != symbol)
			{
				*(newLine + j) = *(line + i);
			}
			else
			{
				--j;
			}
		}

		newLine[strlen(line) - 1] = '\0';

		delete[] line;
		line = newLine;

		return true;
	}
	return false;
}