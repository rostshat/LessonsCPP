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

template <typename T>
void deleteUnit(T*& line, const int index);

int main()
{
	srand(time(NULL));
	char* taskNum = new char;

	while (true || *taskNum != '0')
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
			int* index = new int;

			if (line)
			{
				cin.ignore(1, '\n');
				cout << "Enter your line: ";
				gets_s(line, DEFAULT_LINE_SIZE);
				cout << line << endl;

				cout << "Enter number of units for deleting: ";
				cin >> *index;

				deleteUnit(line, *index);
				cout << line;

				delete index;
				delete[] line;
			}

			break;
		}
		case '2':
		{
			
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

template <typename T>
void deleteUnit(T *&line, const int index)
{
	char* newLine = new char[strlen(line)];
	
	if (newLine)
	{
		int i = 0;
		while (*(line + i) != '\0')
		{
			*(newLine + i) = *(line + i);
		}
		*(newLine + i) = '\0';

		line = newLine;

		delete[] newLine;
	}
}