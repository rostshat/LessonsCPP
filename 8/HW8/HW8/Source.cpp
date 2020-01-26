#include <iostream>
#include <time.h>

#define DEFAULT_SIZE 10
#define ARRAY_START 0
#define MIN 0
#define MAX 100
#define LINE cout << "**********************\n"

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
void arrayReverse(T* array, const int size, const int firstIndex, const int lastIndex);

template <typename T>
void reversCopingOfArray(T* array1, T* array2, const int SIZE);

template <typename T>
T biggerNumber(T* number1, T* number2);

template <typename T>
void isPositive(T* number);

template <typename T>
void getSumm(T* number, T* result);

template <typename T>
void getDifference(T* number, T* result);

template <typename T>
void getMultiply(T* number, T* result);

template <typename T>
void getFraction(T* number, T* result);

template <typename T>
void getResidue(T* number, T* result);

template <typename T>
void getSummOfArrayItems(T* array, int size);

int main()
{
	srand(time(NULL));
	char taskNumber{};

	while (true || taskNumber != '0')
	{
		system("cls");
		cout << "Choose your task: \n";
		cout << "1 -	Array reverse\n";
		cout << "2 -	Reverse Coping\n";
		cout << "3 -	Which number is bigger\n";
		cout << "4 -	-20 to 20 Bubble Sort\n";
		cout << "5 -	Pointer`s calculator\n";
		cout << "6 -	Array`s elements summ\n";
		cout << "0 -	Exit\n";
		cin >> taskNumber;

		if (taskNumber == '0') break;

		switch (taskNumber)
		{
			case '1':
			{

				int array[DEFAULT_SIZE] = { 0 };
				
				fillArray(array, DEFAULT_SIZE, MIN, MAX);
				showArray(array, DEFAULT_SIZE);

				arrayReverse(array, DEFAULT_SIZE, ARRAY_START, DEFAULT_SIZE);
				showArray(array, DEFAULT_SIZE);

				break;
			}
			case '2':
			{
				int array[DEFAULT_SIZE] = { 0 };
				int copiedArray[DEFAULT_SIZE] = { 0 };

				fillArray(array, DEFAULT_SIZE, MIN, MAX);
				showArray(array, DEFAULT_SIZE);
				LINE;

				reversCopingOfArray(array, copiedArray, DEFAULT_SIZE);
				showArray(copiedArray, DEFAULT_SIZE);

				break;
			}
			case '3':
			{
				int firstNum{}, secondNum{};

				cout << "Enter first number: ";
				cin >> firstNum;
				cout << "Enter second number: ";
				cin >> secondNum;

				cout << biggerNumber(&firstNum, &secondNum) << endl;

				break;
			}
			case '4':
			{
				int enteredNumber;

				cout << "Enter your number: ";
				cin >> enteredNumber;
				
				isPositive(&enteredNumber);

				break;
			}
			case '5':
			{
				char userSign;
				int userNumber1, userNumber2;

				cout << "Enter your first number: ";
				cin >> userNumber1;

				while (true)
				{
					cout << "Sign: ";
					cin >> userSign;

					if (userSign == '=')
					{
						cout << "Result: " << userNumber1 << endl;
						break;
					}

					switch (userSign)
					{
						case '+':
						{
							cin >> userNumber2;
							getSumm(&userNumber2, &userNumber1);
							break;
						}
						case '-':
						{
							cin >> userNumber2;
							getDifference(&userNumber2, &userNumber1);
							break;
						}
						case '*':
						{
							cin >> userNumber2;
							getMultiply(&userNumber2, &userNumber1);
							break;
						}
						case '/':
						{
							cin >> userNumber2;
							getFraction(&userNumber2, &userNumber1);
							break;
						}
						case '%':
						{
							cin >> userNumber2;
							getResidue(&userNumber2, &userNumber1);
							break;
						}
						default:
						{
							cout << "The sigh is uncorrect!" << endl;
							break;
						}
					}
				}
			}
			case '6':
			{
				int array[DEFAULT_SIZE] = { 0 };
				fillArray(array, DEFAULT_SIZE, MIN, MAX);
				showArray(array, DEFAULT_SIZE);

				getSummOfArrayItems(array, DEFAULT_SIZE);

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
void arrayReverse(T* array, const int size, const int firstIndex, const int lastIndex)
{
	for (int i = firstIndex, j = lastIndex - 1; i < j; i++, j--)
	{
		swap(array[i], array[j]);
	}
}

template <typename T>
void reversCopingOfArray(T* array1, T* array2, const int SIZE)
{
	for (T i = 0; i < SIZE; i++)
	{
		*(array2 + i) = *(array1 + i);
	}

	arrayReverse(array2, SIZE, ARRAY_START, SIZE);
}

template <typename T>
T biggerNumber(T* number1, T* number2)
{
	return *number1 > * number2 ? *number1 : *number2;
}

template <typename T>
void isPositive(T* number)
{
	*number < 0 ? cout << "Number is smaller than 0" << endl : cout << "Number >= 0" << endl;
}

template <typename T>
void getSumm(T* number, T* result)
{
	*result += *number;
}

template <typename T>
void getDifference(T* number, T* result)
{
	*result -= *number;
}

template <typename T>
void getMultiply(T* number, T* result)
{
	*result *= *number;
}

template <typename T>
void getFraction(T* number, T* result)
{
	*result += *number;
}

template <typename T>
void getResidue(T* number, T* result)
{
	*result %= *number;
}

template <typename T>
void getSummOfArrayItems(T* array, int size)
{
	T temp{};

	for (int i = 0; i < size; i++)
	{
		temp += *(array + i);
	}

	cout << "The summ of items = " << temp << endl;
}