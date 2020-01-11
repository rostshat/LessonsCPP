#include <iostream>
#include <time.h>

using namespace std;

template <typename T>
T getRandom(T min, T max, int order = 1);

#define ARRAY_START 0
#define WRAP cout << endl

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
void bubbleSortDescending(T* array, const int size, const int firstIndex, const int lastIndex);

template <typename T>
void bubbleSortAscending(T* array, const int size, const int firstIndex, const int lastIndex);

int main()
{
	srand(time(NULL));
	char taskNumber;

	while (true || taskNumber != '0')
	{
		system("cls");
		cout << "Choise your task: \n";
		cout << "1 -	-20 to 20 Bubble Sort\n";
		cout << "2 -	10.00 to 99.99 Half Sort\n";
		cout << "3 -	-20 to 20 Bubble Sort\n";
		cout << "4 -	-20 to 20 Bubble Sort\n";
		cout << "0 -	Exit\n";

		cin >> taskNumber;
		if (taskNumber == '0') break;

		switch (taskNumber)
		{
			case '1':
			{
				const int ARR_SIZE = 15;
				const int MIN = -20;
				const int MAX = 20;

				int array[15] = { 0 };
				int smallestIndex = 0;
				int biggestIndex = 0;

				fillArray(array, ARR_SIZE, MIN, MAX);
				showArray(array, ARR_SIZE);


				for (int i = 0; i < ARR_SIZE; i++)
				{
					if (array[i] < 0)
					{
						smallestIndex = i;
						break;
					}
				}

				for (int i = ARR_SIZE - 1; i >= 0; i--)
				{
					if (array[i] < 0)
					{
						biggestIndex = i;
						break;
					}
				}

				cout << "The smallest < 0 index: " << smallestIndex << endl;
				cout << "The biggest < 0 index: "<< biggestIndex << endl;

				bubbleSortDescending(array, ARR_SIZE, smallestIndex + 1, biggestIndex - 1);
				showArray(array, ARR_SIZE);

				break;
			}
			case '2':
			{
				const short ARR_SIZE = 20;
				const double MIN = 10.00;
				const double MAX = 99.99;

				double array[ARR_SIZE] = { 0 };

				fillArray(array, ARR_SIZE, MIN, MAX, 100);
				showArray(array, ARR_SIZE);
				WRAP;
				bubbleSortAscending(array, ARR_SIZE, ARRAY_START, ARR_SIZE / 2);
				showArray(array, ARR_SIZE);
				WRAP;
				bubbleSortDescending(array, ARR_SIZE, ARR_SIZE / 2, ARR_SIZE);
				showArray(array, ARR_SIZE);

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
				cout << "Please, enter correct task number.\n";
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
void bubbleSortDescending(T* array, const int size, const int firstIndex, const int lastIndex)
{
	for (int i = firstIndex; i < lastIndex; i++)
	{
		for (int j = firstIndex; j < lastIndex; j++)
		{
			if (array[j] < array[j + 1])
			{
				swap(array[j], array[j + 1]);
			}
		}
	}
}

template <typename T>
void bubbleSortAscending(T* array, const int size, const int firstIndex, const int lastIndex)
{
	for (int i = firstIndex; i < lastIndex; i++)
	{
		for (int j = firstIndex; j < lastIndex; j++)
		{
			if (array[j] > array[j + 1])
			{
				swap(array[j], array[j + 1]);
			}
		}
	}
}