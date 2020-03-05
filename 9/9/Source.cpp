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
void fillArray(T* array, const int size, T min, T max, int order = 1);
template <typename T>
void fillArray(T* array, const int rows, const int cols, T min, T max, int order = 1);

template <typename T>
void showArray(T* array, const int size);

template <typename T>
void pushArrEnd(T*& array, int& size, const T element);

template <typename T>
void pushArrStart(T*& array, int& size, const T element);

template <typename T>
void pushArrByIndex(T*& array, int& size, const T element, const int index);

template <typename T>
void maluallyFillArray(T*& array, int& size);

template <typename T>
void removeElement(T*& array, int& size, const int index);

template <typename T>
void pushNArrEnd(T*& array, int& size, const int numberOfElements);

template <typename T>
void pushNArrStart(T*& array, int& size, const int numberOfElements);

template <typename T>
void pushNArrByIndex(T*& array, int& size, const int numberOfElements, const int index);

template <typename T>
void removeNArrEnd(T*& array, int& size, const int numberOfElements);

template <typename T>
void removeNArrStart(T*& array, int& size, const int numberOfElements);

template <typename T>
void removeNArrByIndex(T*& array, int& size, const int numberOfElements, const int index);

int main()
{
	srand(time(NULL));
	char choise;

	while (true)
	{
		system("cls");

		cout << "1 - Push 1 element" << endl;
		cout << "2 - Remove 1 element" << endl;
		cout << "3 - Push N elements" << endl;
		cout << "4 - Remove N elements" << endl;
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
			{
				char taskChoise{};

				while (taskChoise != '0')
				{
					cout << "1 - Remove from the end" << endl;
					cout << "2 - Remove from the start" << endl;
					cout << "3 - Remove by index" << endl;
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
							int* array = new int[size];

							maluallyFillArray(array, size);
							LINE;
							showArray(array, size);

							WRAP;

							removeElement(array, size, size - 1);
							showArray(array, size);

							delete[] array;
						}
						else
						{
							int* array = new int[size];

							fillArray(array, size, MIN, MAX);
							cout << "Generated array: ";
							showArray(array, size);
							WRAP;

							removeElement(array, size, size - 1);
							showArray(array, size);

							delete[] array;
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
							int* array = new int[size];

							maluallyFillArray(array, size);
							LINE;
							showArray(array, size);

							WRAP;

							removeElement(array, size, 0);
							showArray(array, size);

							delete[] array;
						}
						else
						{
							int* array = new int[size];

							fillArray(array, size, MIN, MAX);
							cout << "Generated array: ";
							showArray(array, size);
							WRAP;

							removeElement(array, size, 0);
							showArray(array, size);

							delete[] array;
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

							cout << "Enter your index ";
							cin >> *index;

							removeElement(array, size, *index);
							showArray(array, size);

							delete[] array;
							delete change;
							delete index;
						}
						else
						{
							int* index = new int;
							int* array = new int[size];

							fillArray(array, size, MIN, MAX);
							cout << "Generated array: ";
							showArray(array, size);
							WRAP;

							cout << "Enter your index ";
							cin >> *index;

							removeElement(array, size, *index);
							showArray(array, size);

							delete[] array;
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
		}
		case '3':
		{
			char taskChoise{};

			while (taskChoise != '0')
			{
				cout << "1 - Push N to the end" << endl;
				cout << "2 - Push N to the start" << endl;
				cout << "3 - Push N with index" << endl;
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
						int* numberOfElements = new int;
						int* array = new int[size];

						maluallyFillArray(array, size);
						LINE;
						showArray(array, size);

						WRAP;

						cout << "Enter your number of elements ";
						cin >> *numberOfElements;

						pushNArrEnd(array, size, *numberOfElements);
						showArray(array, size);

						delete[] array;
						delete numberOfElements;
					}
					else
					{
						int* numberOfElements = new int;
						int* array = new int[size];

						fillArray(array, size, MIN, MAX);
						cout << "Generated array: ";
						showArray(array, size);
						WRAP;

						cout << "Enter your number of elements ";
						cin >> *numberOfElements;

						pushNArrEnd(array, size, *numberOfElements);
						showArray(array, size);

						delete[] array;
						delete numberOfElements;
					}
					LINE;

					break;
				}
				case'2':
				{
					{
						int size = 10;
						bool arrType;

						cout << "Which array do you need?" << endl;
						cout << "0 - Default generated array" << endl;
						cout << "1 - Custom generated array" << endl;
						cin >> arrType;

						if (arrType)
						{
							int* numberOfElements = new int;
							int* array = new int[size];

							maluallyFillArray(array, size);
							LINE;
							showArray(array, size);

							WRAP;

							cout << "Enter your number of elements ";
							cin >> *numberOfElements;

							pushNArrStart(array, size, *numberOfElements);
							showArray(array, size);

							delete[] array;
							delete numberOfElements;
						}
						else
						{
							int* numberOfElements = new int;
							int* array = new int[size];

							fillArray(array, size, MIN, MAX);
							cout << "Generated array: ";
							showArray(array, size);
							WRAP;

							cout << "Enter your number of elements ";
							cin >> *numberOfElements;

							pushNArrStart(array, size, *numberOfElements);
							showArray(array, size);

							delete[] array;
							delete numberOfElements;
						}
						LINE;

						break;
					}
				}
				case'3':
				{
					{
						int size = 10;
						bool arrType;

						cout << "Which array do you need?" << endl;
						cout << "0 - Default generated array" << endl;
						cout << "1 - Custom generated array" << endl;
						cin >> arrType;

						if (arrType)
						{
							int* numberOfElements	= new int;
							int* index				= new int;
							int* array				= new int[size];

							maluallyFillArray(array, size);
							LINE;
							showArray(array, size);

							WRAP;

							cout << "Enter your index ";
							cin >> *index;
							cout << "Enter your number of elements ";
							cin >> *numberOfElements;

							pushNArrByIndex(array, size, *numberOfElements, *index);
							showArray(array, size);

							delete[] array;
							delete index;
							delete numberOfElements;
						}
						else
						{
							int* numberOfElements = new int;
							int* index = new int;
							int* array = new int[size];

							fillArray(array, size, MIN, MAX);
							cout << "Generated array: ";
							showArray(array, size);
							WRAP;

							cout << "Enter your index ";
							cin >> *index;
							cout << "Enter your number of elements ";
							cin >> *numberOfElements;

							pushNArrByIndex(array, size, *numberOfElements, *index);
							showArray(array, size);

							delete[] array;
							delete numberOfElements;
							delete index;

						}
						LINE;

						break;
					}
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
		case '4':
		{
			char taskChoise{};

			while (taskChoise != '0')
			{
				cout << "1 - Remove N from the end" << endl;
				cout << "2 - Remove N from the start" << endl;
				cout << "3 - Remove N with index" << endl;
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
						int* numberOfElements = new int;
						int* array = new int[size];

						maluallyFillArray(array, size);
						LINE;
						showArray(array, size);

						WRAP;

						do
						{
							cout << "Enter your number of elements ";
							cin >> *numberOfElements;
						} while (*numberOfElements > size);

						removeNArrEnd(array, size, *numberOfElements);
						showArray(array, size);

						delete[] array;
						delete numberOfElements;
					}
					else
					{
						int* numberOfElements = new int;
						int* array = new int[size];

						fillArray(array, size, MIN, MAX);
						cout << "Generated array: ";
						showArray(array, size);
						WRAP;

						do
						{
							cout << "Enter your number of elements ";
							cin >> *numberOfElements;
						} while (*numberOfElements > size);

						removeNArrEnd(array, size, *numberOfElements);
						showArray(array, size);

						delete[] array;
						delete numberOfElements;
					}
					LINE;

					break;
				}
				case'2':
				{
					{
						int size = 10;
						bool arrType;

						cout << "Which array do you need?" << endl;
						cout << "0 - Default generated array" << endl;
						cout << "1 - Custom generated array" << endl;
						cin >> arrType;

						if (arrType)
						{
							int* numberOfElements = new int;
							int* array = new int[size];

							maluallyFillArray(array, size);
							LINE;
							showArray(array, size);

							WRAP;

							do
							{
								cout << "Enter your number of elements ";
								cin >> *numberOfElements;
							} while (*numberOfElements > size);

							removeNArrStart(array, size, *numberOfElements);
							showArray(array, size);

							delete[] array;
							delete numberOfElements;
						}
						else
						{
							int* numberOfElements = new int;
							int* array = new int[size];

							fillArray(array, size, MIN, MAX);
							cout << "Generated array: ";
							showArray(array, size);
							WRAP;

							do
							{
								cout << "Enter your number of elements ";
								cin >> *numberOfElements;
							} while (*numberOfElements > size);

							removeNArrStart(array, size, *numberOfElements);
							showArray(array, size);

							delete[] array;
							delete numberOfElements;
						}
						LINE;

						break;
					}
				}
				case'3':
				{
					{
						int size = 10;
						bool arrType;

						cout << "Which array do you need?" << endl;
						cout << "0 - Default generated array" << endl;
						cout << "1 - Custom generated array" << endl;
						cin >> arrType;

						if (arrType)
						{
							int* numberOfElements = new int;
							int* index = new int;
							int* array = new int[size];

							maluallyFillArray(array, size);
							LINE;
							showArray(array, size);

							WRAP;

							cout << "Enter your index ";
							cin >> *index;
							do
							{
								cout << "Enter your number of elements ";
								cin >> *numberOfElements;
							} while (*numberOfElements > size);

							removeNArrByIndex(array, size, *numberOfElements, *index);
							showArray(array, size);

							delete[] array;
							delete index;
							delete numberOfElements;
						}
						else
						{
							int* numberOfElements = new int;
							int* index = new int;
							int* array = new int[size];

							fillArray(array, size, MIN, MAX);
							cout << "Generated array: ";
							showArray(array, size);
							WRAP;

							cout << "Enter your index ";
							cin >> *index;

							do
							{
								cout << "Enter your number of elements ";
								cin >> *numberOfElements;
							} while (*numberOfElements > size);

							removeNArrByIndex(array, size, *numberOfElements, *index);
							showArray(array, size);

							delete[] array;
							delete numberOfElements;
							delete index;

						}
						LINE;

						break;
					}
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

template <typename T>
void removeElement(T*& array, int& size, const int index)
{
	T* newArray = new T[size - 1]{};

	if (newArray)
	{
		for (int i = 0; i < size; i++)
		{
			if (i >= index)
			{
				*(newArray + i) = *(array + i + 1);
			}
			else
			{
				*(newArray + i) = *(array + i);
			}
		}
		size--;

		delete[]array;
		array = newArray;
	}
}

template <typename T>
void pushNArrEnd(T*& array, int& size, const int numberOfElements)
{
	T* newArray = new T[size + numberOfElements]{};
	int* newSize = new int;

	if (newArray)
	{
		for (int i = 0; i < size; i++)
		{
			*(newArray + i) = *(array + i);
		}
		
		*newSize = size + numberOfElements;

		for (int i = size; i < *newSize; i++)
		{
			*(newArray + i) = getRandom(MIN, MAX);
		}
		size += numberOfElements;

		delete[]array;
		delete newSize;

		array = newArray;
	}
}

template <typename T>
void pushNArrStart(T*& array, int& size, const int numberOfElements)
{
	T* newArray = new T[size + numberOfElements]{};

	if (newArray)
	{
		for (int i = 0; i < numberOfElements; i++)
		{
			*(newArray + i) = getRandom(MIN, MAX);
		}
		size += numberOfElements;
		for (int i = numberOfElements,j = 0; i < size; i++, j++)
		{
			*(newArray + i) = *(array + j);
		}

		delete[]array;

		array = newArray;
	}
}

template <typename T>
void pushNArrByIndex(T*& array, int& size, const int numberOfElements, const int index)
{
	T* newArray = new T[size + numberOfElements]{};

	if (newArray)
	{
		if (index >= size)
		{
			pushNArrEnd(array, size, numberOfElements);
		}
		else if (index <= ARRAY_START)
		{
			pushNArrStart(array, size, numberOfElements);
		}
		else
		{
			size += numberOfElements;

			for (int i = 0; i < index; i++)
			{
				*(newArray + i) = *(array + i);
			}

			for (int i = index; i < numberOfElements; i++)
			{
				*(newArray + i) = getRandom(MIN, MAX); //FIX
			}

			for (int i = index + numberOfElements,j = index ; i < size; i++, j++)
			{
				*(newArray + i) = *(array + j);
			}

			delete[]array;

			array = newArray;
		}
	}
}

template <typename T>
void removeNArrEnd(T*& array, int& size, const int numberOfElements)
{
	T* newArray = new T[size + numberOfElements]{};

	if (newArray)
	{
		for (int i = 0; i < size - numberOfElements; i++)
		{
			*(newArray + i) = *(array + i);
		}
		size -= numberOfElements;

		delete[]array;

		array = newArray;
	}
}

template <typename T>
void removeNArrStart(T*& array, int& size, const int numberOfElements)
{
	T* newArray = new T[size + numberOfElements]{};

	if (newArray)
	{
		for (int i = 0; i < size - numberOfElements; i++)
		{
			*(newArray + i) = *(array + numberOfElements + i);
		}
		size -= numberOfElements;

		delete[]array;

		array = newArray;
	}
}

template <typename T>
void removeNArrByIndex(T*& array, int& size, const int numberOfElements, const int index)
{
	T* newArray = new T[size + numberOfElements]{};

	if (newArray)
	{
		if (index >= size)
		{
			removeNArrEnd(array, size, numberOfElements);
		}
		else if (index <= ARRAY_START)
		{
			removeNArrStart(array, size, numberOfElements);
		}
		else
		{
			for (int i = 0; i < index; i++)
			{
				*(newArray + i) = *(array + i);
			}
			for (int i = index, j = index + numberOfElements; i < j; i++)
			{
				if (i == size) break;
				*(newArray + i) = *(array + j);
			}
			size -= numberOfElements;
		}

		delete[]array;

		array = newArray;
	}
}