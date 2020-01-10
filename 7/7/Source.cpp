#include <iostream>
#include <time.h>

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
void bubbleSort(T* array, const int size, const int firstIndex, const int lastIndex);

int main()
{
	srand(time(NULL));
	char taskNumber;

	while (true || taskNumber != '0')
	{
		system("cls");
		cout << "Choise your task: \n";
		cout << "1 - Volume of figures\n";
		cout << "2 - Matrix Generator \n";
		cout << "3 - Show Matrix\n";
		cout << "4 - Diagonal Summ\n";
		cout << "5 - Max number in P\n";
		cout << "6 - Average number\n";
		cout << "0 - Exit\n";

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

				fillArray(array, ARR_SIZE, MIN, MAX);
				showArray(array, ARR_SIZE);
				bubbleSort(array, ARR_SIZE, 0,ARR_SIZE);
				showArray(array, ARR_SIZE);

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
void bubbleSort(T* array, const int size, const int firstIndex, const int lastIndex)
{
	for (int i = firstIndex; i < lastIndex; i++) 
	{
		for (int j = lastIndex - 1; j > i; j--) 
		{
			if (array[j - 1] > array[j]) swap(&array[j], &array[j + 1]);
		}
	}
}