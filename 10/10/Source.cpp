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
bool addUnitByIndex(char*& line, const int index, const int symbol);
bool swapPoint(char*& line);
int getRepeats(char*& line, char symbol);
void getNumberOfDigits(char*& line, int* numbers, int* letters, int* symbols);
void changeSpaces(char*& line);

int main()
{
	srand(time(NULL));
	char taskNum{};

	while (true && taskNum != '0')
	{
		system("cls");

		cout << "1 - Delete Unit By Index" << endl;
		cout << "2 - Delete units By Name" << endl;
		cout << "3 - Add Unit By Index" << endl;
		cout << "4 - Swap . to !" << endl;
		cout << "5 - How many repeats" << endl;
		cout << "6 - Number of digits" << endl;
		cout << "7 - ' ' to \\t" << endl;
		cout << "8 - Number of digits" << endl;
		cout << "0 - Exit" << endl;
		cin >> taskNum;

		switch (taskNum)
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
				char* line = new char[DEFAULT_LINE_SIZE];
				char symbol;
				int index;

				cin.ignore(1, '\n');
				cout << "Enter your line: ";
				gets_s(line, DEFAULT_LINE_SIZE);
				cout << line << endl;
				
				cout << "Enter the index of unit for adding: ";
				cin >> index;
				cout << "Enter the symbol of unit for adding: ";
				cin >> symbol;

				addUnitByIndex(line, index, symbol);
				cout << line << endl;


				delete[] line;

				break;
			}
			case '4':
			{
				char* line = new char[DEFAULT_LINE_SIZE];

				cin.ignore(1, '\n');
				cout << "Enter your line: ";
				gets_s(line, DEFAULT_LINE_SIZE);

				swapPoint(line);
				cout << line << endl;


				delete[] line;

				break;
			}
			case '5':
			{
				char* line = new char[DEFAULT_LINE_SIZE];
				char symbol;

				cin.ignore(1, '\n');
				cout << "Enter your line: ";
				gets_s(line, DEFAULT_LINE_SIZE);
				cout << "Enter the symbol for counting ";
				cin >> symbol;

				
				cout << "The line has " << getRepeats(line, symbol) << " repeats of: " << symbol << endl;


				delete[] line;

				break;

				break;
			}
			case '6':
			{
				char* line = new char[DEFAULT_LINE_SIZE];
				int numbers{}, letters{}, symbols{};


				cin.ignore(1, '\n');
				cout << "Enter your line: ";
				gets_s(line, DEFAULT_LINE_SIZE);

				getNumberOfDigits(line, &numbers, &letters, &symbols);
				cout << "Numbers: " << numbers << endl << "Letters: " << letters << endl << "Symbols: " << symbols << endl;
				delete[] line;

				break;
			}
			case '7':
			{
				char* line = new char[DEFAULT_LINE_SIZE];

				cin.ignore(1, '\n');
				cout << "Enter your line: ";
				gets_s(line, DEFAULT_LINE_SIZE);

				changeSpaces(line);
				cout << line << endl;

				delete[] line;

				break;
			}
			case '8':
			{
				char* line = new char[DEFAULT_LINE_SIZE];
				int numbers{}, letters{}, symbols{};


				cin.ignore(1, '\n');
				cout << "Enter your line: ";
				gets_s(line, DEFAULT_LINE_SIZE);

				getNumberOfDigits(line, &numbers, &letters, &symbols);
				cout << "Numbers: " << numbers << endl << "Letters: " << letters << endl << "Symbols: " << symbols << endl;
				delete[] line;

				break;
			}
			default:
			{
				if(taskNum != '0') cout << "Incorrect number" << endl;

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

	if (!counter) return false;

	for (int i = 0, j = 0; i < strlen(line); i++, j++)
	{
			if (line[i] != symbol)
			{
				*(line + j) = *(line + i);
			}
			else
			{
				j--;
			}
	}

	line[strlen(line) - counter] = '\0';

	return true;
}

bool addUnitByIndex(char*& line, const int index, const int symbol)
{
	if (strlen(line) < index || index < 0)
		return false;

	char* newLine = new char[strlen(line) + 1];

	if (newLine)
	{
		for (int i = 0; i < strlen(line) + 1; i++)
		{
			if (i != index)
			{
				*(newLine + i) = *(line + i);
			}
			else if(i == index)
			{
				*(newLine + i) = symbol;
			}
			else
			{
				*(newLine + i + 1) = *(line + i);
			}
		}

		newLine[strlen(newLine)] = '\0';

		delete[] line;
		line = newLine;

		return true;
	}
}

bool swapPoint(char*& line)
{
	int counter{};
	for (int i = 0; i < strlen(line); i++)
	{
		if (line[i] == '.') counter++;
	}

	if (!counter) return false;

	for (int i = 0; i < strlen(line) + 1; i++)
	{
		if (*(line + i) != '.')
		{
			*(line + i) = *(line + i);
		}
		else 
		{
			*(line + i) = '!';
		}
	}

	return true;
}

int getRepeats(char*& line, char symbol)
{
	int counter{};
	for (int i = 0; i < strlen(line); i++)
	{
		if (line[i] == symbol) counter++;
	}

	return counter;
}

void getNumberOfDigits(char*& line, int *numbers, int *letters, int *symbols)
{
	int i = 0;
	
	while (line[i] != '\0')
	{
		if(line[i] >= '0' && line[i] <= '9')
		{
			(*numbers)++;
		}
		else if ((line[i] >= 'a' && line[i] <= 'z') || (line[i] >= 'A' && line[i] <= 'Z'))
		{
			(*letters)++;
		}
		else
		{
			(*symbols)++;
		}

		i++;
	}
}

void changeSpaces(char*& line)
{
	int i{};

	while (line[i] != '\0')
	{
		if (line[i] == ' ')
		{
			line[i] = '\t';
		}		
		i++;
	}
}