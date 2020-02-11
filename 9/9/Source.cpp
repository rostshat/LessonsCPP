#include <iostream>
#include <time.h>
#include <conio.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define DEFAULT_SIZE 10
#define MIN 0
#define MAX 100
#define LINE cout << "**********************\n"
#define ARRAY_START 0
#define WRAP cout << endl

using namespace std;

template <typename T>
T getRandom(T min, T max, int order = 1);

template <typename T>
void swap(T* xp, T* yp);

template <typename T>
void fillArray(T* array, const int size, T min, T max, int order = 1);
template <typename T>
void fillArray(T* array, const int rows, const int cols, T min, T max, int order = 1);

template <typename T>
void showArray(T* array, const int size);
template <typename T>
void showArray(T* array, const int rows, const int cols);

template <typename T>
void pushArrEnd(T*& array, int& size, const T element);

template <typename T>
void pushArrStart(T*& array, int& size, const T element);

template <typename T>
void pushArrByIndex(T*& array, int& size, const T element, const int index);

template <typename T>
void maluallyFillArray(T*& array, int& size);

int main()
{
	srand(time(NULL));
	char choise;

	while (true)
	{
		system("cls");

		cout << "1 - Push" << endl;
		cout << "2 - Remove" << endl;
		cout << "0 - Exit" << endl;
		cin >> choise;

		if (choise == '0') break;

		switch (choise)
		{
		case'1':
		{
			char taskChoise{};

			while (taskChoise != '0')
			{
				cout << "1 - Push to the end" << endl;
				cout << "2 - Push to the start" << endl;
				cout << "3 - Push by index" << endl;
				cout << "0 - Back" << endl;
				cin >> taskChoise;

				switch (taskChoise)
				{
					case'1':
					{
						int size = 10;
						bool arrType;
						
						cout << "Which array do you need?" << endl;
						cout << "0 - Default generated array" << endl;
						cout << "1 - Custom generated array" << endl;
						cin >> arrType;

						if (arrType)
						{
							int* change = new int;
							int* array = new int[size];

							maluallyFillArray(array, size);
							LINE;
							showArray(array, size);

							WRAP;

							cout << "Enter your number ";
							cin >> *change;

							pushArrEnd(array, size, *change);
							showArray(array, size);

							delete[] array;
							delete change;
						}
						else
						{
							int* change = new int;
							int* array = new int[size];

							fillArray(array, size, MIN, MAX);
							cout << "Generated array: ";
							showArray(array, size);
							WRAP;

							cout << "Enter your number ";
							cin >> *change;

							pushArrEnd(array, size, *change);
							showArray(array, size);

							delete[] array;
							delete change;
						}
						LINE;
						break;
					}
					case'2':
					{
						int size = 10;
						bool arrType;

						cout << "Which array do you need?" << endl;
						cout << "0 - Default generated array" << endl;
						cout << "1 - Custom generated array" << endl;
						cin >> arrType;

						if (arrType)
						{
							int* change = new int;
							int* array = new int[size];

							maluallyFillArray(array, size);
							LINE;
							showArray(array, size);

							WRAP;

							cout << "Enter your number ";
							cin >> *change;

							pushArrStart(array, size, *change);
							showArray(array, size);

							delete[] array;
							delete change;
						}
						else
						{
							int* change = new int;
							int* array = new int[size];

							fillArray(array, size, MIN, MAX);
							cout << "Generated array: ";
							showArray(array, size);
							WRAP;

							cout << "Enter your number ";
							cin >> *change;

							pushArrStart(array, size, *change);
							showArray(array, size);

							delete[] array;
							delete change;
						}
						LINE;
						break;
					}
					case'3':
					{
						int size = 10;
						bool arrType;

						cout << "Which array do you need?" << endl;
						cout << "0 - Default generated array" << endl;
						cout << "1 - Custom generated array" << endl;
						cin >> arrType;

						if (arrType)
						{
							int* change = new int;
							int* index = new int;
							int* array = new int[size];

							maluallyFillArray(array, size);
							LINE;
							showArray(array, size);

							WRAP;

							cout << "Enter your number ";
							cin >> *change;
							cout << "Enter your index ";
							cin >> *index;

							pushArrByIndex(array, size, *change, *index);
							showArray(array, size);

							delete[] array;
							delete change;
							delete index;
						}
						else
						{
							int* change = new int;
							int* index = new int;
							int* array = new int[size];

							fillArray(array, size, MIN, MAX);
							cout << "Generated array: ";
							showArray(array, size);
							WRAP;

							cout << "Enter your number ";
							cin >> *change;
							cout << "Enter your index ";
							cin >> *index;

							pushArrByIndex(array, size, *change, *index);
							showArray(array, size);

							delete[] array;
							delete change;
							delete index;
						}
						LINE;
						break;
					}
					case'0':
					{
						taskChoise = '0';

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
void fillArray(T* array, const int size, T min, T max, int order)
{
	for (int i = 0; i < size; i++)
	{
		array[i] = getRandom(min, max, order);
	}
}

template <typename T>
void fillArray(T* array, const int rows, const int cols, T min, T max, int order)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			*array[i][j] = getRandom(min, max);
		}
	}
}


template <typename T>
void showArray(T* array, const int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << array[i] << ' ';
	}
	cout << endl;
}

template <typename T>
void showArray(T* array, const int rows, const int cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			cout << array[i][j] << ' ';
		}
		cout << endl;
	}
}

template <typename T>
void swap(T* xp, T* yp)
{
	T temp = *xp;
	*xp = *yp;
	*yp = temp;
}

template <typename T>
void pushArrEnd(T*& array, int& size, const T element)
{
	T* newArray = new T[size + 1]{};

	if (newArray)
	{
		for (int i = 0; i < size; i++)
		{
			*(newArray + i) = *(array + i);
		}
		*(newArray + size) = element;
		size++;

		delete[]array;

		array = newArray;
	}
}

template <typename T>
void pushArrStart(T*& array, int& size, const T element)
{
	T* newArray = new T[size + 1]{};

	if (newArray)
	{
		size++;
		*(newArray) = element;

		for (int i = 0; i < size; i++)
		{
			*(newArray + i + 1) = *(array + i);
		}

		delete[]array;

		array = newArray;
	}
}

template <typename T>
void pushArrByIndex(T*& array, int& size, const T element, int index)
{
	T* newArray = new T[size + 1]{};

	if (newArray)
	{
		if (index >= size)
		{
			pushArrEnd(array, size, element);
		}
		else if (index <= 0)
		{
			pushArrStart(array, size, element);
		}
		else
		{
			size++;

			for (int i = 0; i < size; i++)
			{
				if (i >= index)
				{
					if (i == index)
					{
						*(newArray + i) = element;
					}
					else
					{
						*(newArray + i) = *(array + i - 1);
					}
				}
				else
				{
					*(newArray + i) = *(array + i);
				}				
			}

			delete[]array;

			array = newArray;
		}
	}
}


template <typename T>
void maluallyFillArray(T*& array, int& size)
{
	T temp;
	cout << "Fill your array: \n";
	for (int i = 0; i < size; i++)
	{
		cout << i << ": ";
		cin >> temp;

		*(array + i) = temp;
	}
}