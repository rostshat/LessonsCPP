#include <iostream>
#include <iomanip>
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
bool createArr2D(T**& ptr2DArr, const int rows, const int cols);
template <typename T>
void fillArr2D(T** const ptr2DArr, const int rows, const int cols, const int min, const int max, const int order = 1);
template <typename T>
void showArr2D(T** const ptr2DArr, const int rows, const int cols, const int width = 2);
template <typename T>
void deleteArr2D(T**& ptr2DArr, const int rows);
template <typename T>

bool addRowByIndex(T**& ptr2DArr, int *rows, const int cols, const int index, const T min, const T max, const int order = 1);

template <typename T>
bool addColumnByIndex(T**& ptr2DArr, const int rows, int *cols, const int index, const T min, const T max, const int order = 1);

template <typename T>
bool deleteRowByIndex(T**& ptr2DArr, int* rows, const int cols, const int index, const T min, const T max, const int order =  1);

struct Contact
{
	char* name;
	char* number;
};

int main()
{
	srand(time(NULL));
	char* taskNum = new char;

	while (true && *taskNum != '0')
	{
		system("cls");

		cout << "1 - Add Row by Index" << endl;
		cout << "2 - Add Column by Index" << endl;
		cout << "3 - Delete Row By Index" << endl;
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
			int* sizeRows = new int{0};
			int* sizeCols = new int{0};
			int width;
			int index{};

			cout << "Rows: ";
			cin >> *sizeRows;
			cout << "Cols: ";
			cin >> *sizeCols;
			cout << "Width for printing: ";
			cin >> width;

			int** ptr2DArr = nullptr;
			bool exist = createArr2D(ptr2DArr, *sizeRows, *sizeCols);

			if (exist)
			{
				fillArr2D(ptr2DArr, *sizeRows, *sizeCols, MIN, MAX, 1);
				showArr2D(ptr2DArr, *sizeRows, *sizeCols, width);				

				cout << "Index for adding: ";
				cin >> index;

				if (index < *sizeRows && index >= 0)
				{
					addRowByIndex(ptr2DArr, sizeRows, *sizeCols, index, MIN, MAX);
					LINE;
					showArr2D(ptr2DArr, *sizeRows, *sizeCols, width);
				}
				else
				{
					cout << "Error" << endl;
				}

				deleteArr2D(ptr2DArr, *sizeRows);
			}

			delete sizeRows;
			delete sizeCols;

			break;
		}
		case '2':
		{
			int* sizeRows = new int{ 0 };
			int* sizeCols = new int{ 0 };
			int width;
			int index{};

			cout << "Rows: ";
			cin >> *sizeRows;
			cout << "Cols: ";
			cin >> *sizeCols;
			cout << "Width for printing: ";
			cin >> width;
			cout << "Enter your index: ";
			cin >> index;

			int** ptr2DArr = nullptr;
			bool exist = createArr2D(ptr2DArr, *sizeRows, *sizeCols);

			if (exist)
			{
				fillArr2D(ptr2DArr, *sizeRows, *sizeCols, MIN, MAX, 1);
				showArr2D(ptr2DArr, *sizeRows, *sizeCols, width);

				if (index < *sizeCols && index >= 0)
				{
					addColumnByIndex(ptr2DArr, *sizeRows, sizeCols, index, MIN, MAX);
					LINE;
					showArr2D(ptr2DArr, *sizeRows, *sizeCols, width);
				}
				else
				{
					cout << "Error\n";
				}

				deleteArr2D(ptr2DArr, *sizeRows);
			}

			delete sizeRows;
			delete sizeCols;

			break;
		}
		case '3':
		{
			int* sizeRows = new int{ 0 };
			int* sizeCols = new int{ 0 };
			int width;
			int index{};

			cout << "Rows: ";
			cin >> *sizeRows;
			cout << "Cols: ";
			cin >> *sizeCols;
			cout << "Width for printing: ";
			cin >> width;
			cout << "Enter your index: ";
			cin >> index;

			int** ptr2DArr = nullptr;
			bool exist = createArr2D(ptr2DArr, *sizeRows, *sizeCols);

			if (exist)
			{
				fillArr2D(ptr2DArr, *sizeRows, *sizeCols, MIN, MAX, 1);
				showArr2D(ptr2DArr, *sizeRows, *sizeCols, width);

				if (index >= 0 && index < *sizeRows)
				{
					deleteRowByIndex(ptr2DArr, sizeRows, *sizeCols, index, MIN, MAX);
					LINE;
					showArr2D(ptr2DArr, *sizeRows, *sizeCols, width);
				}
				else
				{
					cout << "Error\n";
				}
				deleteArr2D(ptr2DArr, *sizeRows);
			}

			delete sizeRows;
			delete sizeCols;			

			break;
		}
		case '4':
		{
			const int NUMBER_OF_ROWS = 2;
			const int NUMBER_OF_COLS = 1;

			int numberOfContacts{};
			char operation{};

			int* contactsBook = nullptr;						
			

			while (true && operation != '0')
			{
				cout << "Enter your task number: \n";
				cout << "1 - Add number \n";
				cout << "2 - Delete number \n";
				cout << "3 - Search by number \n";
				cout << "4 - Search by contact name \n";
				cout << "5 - Show numbers \n";
				cout << "0 - Exit \n";
				cin >> operation;

				switch (operation)
				{
					case '1':
					{


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
					default:
					{
						break;
					}
				}
			}

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
bool createArr2D(T**& ptr2DArr, const int rows, const int cols)
{
	if (!ptr2DArr)
	{
		ptr2DArr = new T * [rows];
		if (ptr2DArr)
		{
			for (int i = 0; i < rows; i++)
			{
				*(ptr2DArr + i) = new T[cols]{};
				if (!(*(ptr2DArr + i))) return false; //Checking of the array creating 2nd stage
			}
			return true;
		}
		return false;
	}
	return false;
}

template <typename T>
void fillArr2D(T** const ptr2DArr, const int rows, const int cols, const int min, const int max, const int order)
{
	if (ptr2DArr)
	{
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				*(*(ptr2DArr + i) + j) = getRandom(min, max, order);
				//array[i][j] = getRandom(min, max, order);
			}
		}
	}
}

template <typename T>
void showArr2D(T** const ptr2DArr, const int rows, const int cols, const int width)
{
	if (ptr2DArr)
	{
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				cout << fixed << setw(width) << *(*(ptr2DArr + i) + j) << ' ';
				//array[i][j] = getRandom(min, max, order);
			}
			WRAP;
		}
	}
}

template <typename T>
void deleteArr2D(T**& ptr2DArr, const int rows)
{
	if (ptr2DArr)
	{
		for (int i = 0; i < rows; i++)
		{
			delete[] * (ptr2DArr + i);
		}
		delete[]ptr2DArr;
		ptr2DArr = nullptr;
	}
}

template <typename T>
bool addRowByIndex(T** &ptr2DArr, int *rows, const int cols, const int index, const T min, const T max, const int order)
{
	if (ptr2DArr && index >= 0 && index < *rows)
	{
		T** newPtr2DArr = new T * [*rows + 1];

		if(newPtr2DArr)
		{	
			*(newPtr2DArr + index) = new T[cols]{};

			if (!(*(newPtr2DArr + index)))
			{
				delete[] newPtr2DArr;
				return false;
			}

			for (int i = 0; i < *rows; i++)
			{
				if (i < index)
				{
					*(newPtr2DArr + i) = *(ptr2DArr + i);
				}
				else
				{
					*(newPtr2DArr + i + 1) = *(ptr2DArr + i);
				}
			}

			for (int i = 0; i < cols; i++)
			{
				*(*(newPtr2DArr + index) + i) = getRandom(min, max);
			}

			delete[] ptr2DArr;
			ptr2DArr = newPtr2DArr;
			(*rows)++;
			return true;
		}
		else
		{
			delete[] newPtr2DArr;
			return false;
		}
	}
	return false;
}

template <typename T>
bool addColumnByIndex(T**& ptr2DArr, const int rows,  int *cols, const int index, const T min, const T max, const int order)
{
	if (ptr2DArr && index >= 0 && index < rows)
	{
		T** newPtr2DArr = new T * [rows];

		if (newPtr2DArr)
		{
			for (int i = 0; i < rows; i++)
			{
				*(newPtr2DArr + i) = new T[(*cols) + 1];

				for (int j = 0; j < (*cols) + 1; j++)
				{
					if (j < index)
					{
						*(*(newPtr2DArr + i) + j) = *(*(ptr2DArr + i) + j);
					}
					else if (j > index)
					{
						*(*(newPtr2DArr + i) + j) = *(*(ptr2DArr + i) + j - 1);
					}
					else
					{
						*(*(newPtr2DArr + i) + index) = getRandom(min, max);
					}
				}
			}

			delete[] ptr2DArr;
			ptr2DArr = newPtr2DArr;
			(*cols)++;
			return true;
		}
		else
		{
			delete[] newPtr2DArr;
			return false;
		}
	}
	return false;
}

template <typename T>
bool deleteRowByIndex(T**& ptr2DArr, int* rows, const int cols, const int index, const T min, const T max, const int order)
{
	if (ptr2DArr && index >= 0 && index < *rows)
	{
		T** newPtr2DArr = new T * [*rows - 1];

		if (newPtr2DArr)
		{
			*(newPtr2DArr + index) = new T[cols]{};

			if (!(*(newPtr2DArr + index)))
			{
				delete[] newPtr2DArr;
				return false;
			}

			for (int i = 0; i < (*rows) - 1; i++)
			{
				if (i < index)
				{
					*(newPtr2DArr + i) = *(ptr2DArr + i);
				}
				else if(i >= index)
				{
					*(newPtr2DArr + i) = *(ptr2DArr + i + 1);
				}				
			}			

			delete[] ptr2DArr;
			ptr2DArr = newPtr2DArr;
			(*rows)--;
			return true;
		}
		else
		{
			delete[] newPtr2DArr;
			return false;
		}
	}
	return false;
}

/*CONTACTS*/
template <typename T>
bool addNumber(T**& ptrContacts, int *counter)
{
	const int MAX_NAME_LENGTH = 20;
	const int MAX_NUMBER_LENGTH = 13;	

	cout << "Enter your name: \n";
	gets_s(name, MAX_NAME_LENGTH);
	cout << "Enter your number: \n";
	gets_s(number, MAX_NUMBER_LENGTH);


}