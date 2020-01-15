#include <iostream>
#include <iomanip>
#include <time.h>
#include <stdlib.h>

using namespace std;

#define PI 3.141592

double volume(double height, double square);
double volume(double height, double square, bool cylinder);
double volume(double radius);

template <typename T>
T getRandom(const T min, const T max, int order = 1)
{
	return (T)(rand() % (((int)max - (int)min) * order) + min * order) / order;
}

template <typename T>
void showMatrix(T matrix[], int rows, int cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			cout << setw(5) << matrix[i][j] << ' ';
		}
		cout << endl;
	}
}

template <typename T>
void squareMatrixDiagonalSum(T matrix[], int size, bool diagonalType, bool isDouble = false);

template <typename T>
void maxNumberInPerimetr(const T const matrix[], const int rows, const int cols, bool isDouble = false);
template <typename T>
void getAverageNumberFromMatrix(const T const matrix[], const int rows, const int COLS, bool isDouble);

int main()
{
	srand(time(NULL));
	char taskNum{};

	while (true || taskNum != '0')
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

		cin >> taskNum;
		if (taskNum == '0') break;

		switch (taskNum)
		{
			case '1':
			{
				char object{};

				cout << "Select your figure foor get it`s volume: \n";
				cout << "1 - Parallelepiped\n";
				cout << "2 - Cylinder\n";
				cout << "3 - Sphere\n";
				cin >> object;
				cout << endl;

				switch (object)
				{
					case '1':
					{
						double height{};
						double square{};

						do {
							cout << "Enter your height: ";
							cin >> height;
							cout << "Enter your square: ";
							cin >> square;
							cout << endl;
						} while (height <= 0 || square <= 0);

						cout << "V: " << volume(height, square) << endl;
						break;
					}
					case '2':
					{
						double height{};
						double square{};

						do {
							cout << "Enter your height: ";
							cin >> height;
							cout << "Enter your square: ";
							cin >> square;
							cout << endl;
						} while (height <= 0 || square <= 0);

						cout << "V: " << volume(height, square, true) << endl;
						break;
					}
					case '3':
					{
						double radius{};

						do
						{
							cout << "Enter your radius: ";
							cin >> radius;
							cout << endl;
						} while (radius <= 0);

						cout << "V: " << volume(radius) << endl;
						break;
					}
					default:
					{
						cout << "Enter a correct number. \n";
						break;
					}						
				}
				break;
			}
			case '2':
			{
				const int ROWS = 15;
				const int COLS = 12;

				char typeOfMatrix{};

				cout << "Select your type of matrix: \n";
				cout << "1 - Integer\n";
				cout << "2 - Char\n";
				cout << "3 - Double\n";
				cin >> typeOfMatrix;
				cout << endl;

				switch (typeOfMatrix)
				{
					case '1':
					{
						int matrix[ROWS][COLS] = { 0 };
						int min{}, max{};

						for (int i = 0; i < ROWS; i++)
						{
							for (int j = 0; j < COLS; j++)
							{
								matrix[i][j] = getRandom(min, max);
							}
						}
						showMatrix(matrix, ROWS, COLS);

						break;
					}
					case '2':
					{
						char matrix[ROWS][COLS] = { 0 };
						char min, max;

						cout << "Enter min symbol: ";
						cin >> min;
						cout << "Enter max symbol: ";
						cin >> max;
						cout << endl;

						for (int i = 0; i < ROWS; i++)
						{
							for (int j = 0; j < COLS; j++)
							{
								matrix[i][j] = getRandom(min, max);
							}
						}
						showMatrix(matrix, ROWS, COLS);

						break;
					}
					case '3':
					{
						double matrix[ROWS][COLS] = { 0 };
						double min{}, max{};
						int order{};

						do {
							cout << "Enter min number: ";
							cin >> min;
							cout << "Enter max number: ";
							cin >> max;
							cout << "Enter a number of numbers after comma: ";
							cin >> order;
							cout << endl;
						} while (min > max);

						for (int i = 0; i < ROWS; i++)
						{
							for (int j = 0; j < COLS; j++)
							{
								matrix[i][j] = getRandom(min, max, order);
							}
						}
						showMatrix(matrix, ROWS, COLS);

						break;
					}
					default:
					{
						cout << "Enter a correct number. \n";
						break;
					}						
				}

				break;
			}
			case '3':
			{
				const int ROWS = 10;
				const int COLS = 10;
				const int MIN = 1;
				const int MAX = 100;

				int matrix[ROWS][COLS] = { 0 };

				for (int i = 0; i < ROWS; i++)
				{
					for (int j = 0; j < COLS; j++)
					{
						matrix[i][j] = getRandom(MIN, MAX);
					}
				}
				showMatrix(matrix, ROWS, COLS);

				break;
			}
			case '4':
			{
				const int SIZE = 10;
				bool choose{}, chooseType{};

				cout << "Choose type of matrix 0 - Int32/ 1 - Double \nEnter your choose: ";
				cin >> choose;

				if (choose)
				{
					double matrix[SIZE][SIZE] = { 0 };
					double min, max;
					int order;

					cout << "Enter minimal number: ";
					cin >> min;
					cout << "Enter maximal number: ";
					cin >> max;
					cout << "Enter order: ";
					cin >> order;
					cout << "Default diagolan = 0/ Reversed diagolan = 1 \nEnter your choose: ";
					cin >> chooseType;

					for (int i = 0; i < SIZE; i++)
					{
						for (int j = 0; j < SIZE; j++)
						{
							matrix[i][j] = getRandom(min, max, order);
						}
					}
					showMatrix(matrix, SIZE, SIZE);
					squareMatrixDiagonalSum(matrix, SIZE, chooseType, true);
				}
				else
				{
						int matrix[SIZE][SIZE] = { 0 };
						int min, max;

						cout << "Enter minimal number: ";
						cin >> min;
						cout << "Enter maximal number: ";
						cin >> max;
						cout << "Default diagolan = 0/ Reversed diagolan = 1 \nEnter your choose: ";
						cin >> chooseType;

						for (int i = 0; i < SIZE; i++)
						{
							for (int j = 0; j < SIZE; j++)
							{
								matrix[i][j] = getRandom(min, max);
							}
						}
						showMatrix(matrix, SIZE, SIZE);
						squareMatrixDiagonalSum(matrix, SIZE, chooseType);
				}

				break;
			}
			case '5':
			{
				const int SIZE = 10;
				char matrixType;

				cout << "0 - Integer \n";
				cout << "1 - Double \n";
				cout << "Enter your matrix type: \n";
				cin >> matrixType;

				switch (matrixType)
				{
					case'0':
					{
						int matrix[SIZE][SIZE] = { 0 };
						int min, max;

						do {
							cout << "Enter min number: ";
							cin >> min;
							cout << "Enter max number: ";
							cin >> max;
							cout << endl;

						} while (min >= max);

						for (int i = 0; i < SIZE; i++)
						{
							for (int j = 0; j < SIZE; j++)
							{
								matrix[i][j] = getRandom(min, max);
							}
						}
						showMatrix(matrix, SIZE, SIZE);
						maxNumberInPerimetr(matrix, SIZE, SIZE);

						break;
					}
					case'1':
					{
						double matrix[SIZE][SIZE] = { 0 };
						double  min, max;
						int order;

						do {
							cout << "Enter min number: ";
							cin >> min;
							cout << "Enter max number: ";
							cin >> max;
							cout << "Enter your order: ";
							cin >> order;
							cout << endl;

						} while (min >= max || order < 1);

						for (int i = 0; i < SIZE; i++)
						{
							for (int j = 0; j < SIZE; j++)
							{
								matrix[i][j] = getRandom(min, max, order);
							}
						}
						showMatrix(matrix, SIZE, SIZE);
						maxNumberInPerimetr(matrix, SIZE, SIZE, true);

						break;
					}
					default:
						break;
				}

				break;
			}
			case'6':
			{
				const int ROWS = 15;
				const int COLS = 12;
				
				bool isDouble;

				cout << "Enter type of the matrix: \n 0 - Int32\n 1 - Double \n";
				cin >> isDouble;

				if (isDouble)
				{
					double matrix[ROWS][COLS] = { 0 };
					double min, max;
					int order;


					do {
						cout << "Enter min number: ";
						cin >> min;
						cout << "Enter max number: ";
						cin >> max;
						cout << "Enter number of numbers after comma: ";
						cin >> order;
						cout << endl;

					} while (min >= max);

					for (int i = 0; i < ROWS; i++)
					{
						for (int j = 0; j < COLS; j++)
						{
							matrix[i][j] = getRandom(min, max, order);
						}
					}

					showMatrix(matrix, ROWS, COLS);
					getAverageNumberFromMatrix(matrix, ROWS, COLS, isDouble);
				}
				else
				{
					int matrix[ROWS][COLS] = { 0 };
					int min, max;

					do {
						cout << "Enter min number: ";
						cin >> min;
						cout << "Enter max number: ";
						cin >> max;
						cout << endl;

					} while (min >= max);


					for (int i = 0; i < ROWS; i++)
					{
						for (int j = 0; j < COLS; j++)
						{
							matrix[i][j] = getRandom(min, max);
						}
					}

					showMatrix(matrix, ROWS, COLS);
					getAverageNumberFromMatrix(matrix, ROWS, COLS, isDouble);
				}

				break;
			}
			default:
			{
				cout << "Enter a correct task number \n";
				break;
			}
		}
		system("pause");
	}

	return 0;
}

template <typename T>
void getAverageNumberFromMatrix(const T const matrix[], const int rows, const int COLS, bool isDouble)
{
	if (isDouble)
	{
		double sum{};
		const int amountOfNumbers = rows * COLS;
		
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < COLS; j++)
			{
				sum += matrix[i][j];
			}
		}

		cout << endl << "Average numnber is: " << sum / amountOfNumbers << endl;
	}
	else
	{
		int sum{};
		const int amountOfNumbers = rows * COLS;

		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < COLS; j++)
			{
				sum += matrix[i][j];
			}
		}

		cout << endl << "Average numnber is: " << sum / amountOfNumbers << endl;
	}
}
template <typename T>
void squareMatrixDiagonalSum(T matrix[], int size, bool diagonalType, bool isDouble)
{
	if (isDouble)
	{
		double sum = 0;

		for (int i = 0; i < size; i++)
		{
			if (!diagonalType) sum += matrix[i][i];
			if (diagonalType) sum += matrix[i][size - i - 1];
		}

		cout << sum << endl;
	}
	else
	{
		int sum = 0;

		for (int i = 0; i < size; i++)
		{
			if (!diagonalType) sum += matrix[i][i];
			if (diagonalType) sum += matrix[i][size - i - 1];
		}

		cout << sum << endl;
	}
}

template <typename T>
void maxNumberInPerimetr(const T const matrix[], const int rows, const int cols, bool isDouble)
{
	if (isDouble)
	{
		double max{};
		max = matrix[0][0];

		for (int i = 0; i < rows; i += rows - 1)
		{
			for (int j = 0; j < cols; j++)
			{
				if (matrix[i][j] > max) max = matrix[i][j];
			}
		}

		for (int i = 0; i < rows; i += rows - 1)
		{
			for (int j = 0; j < cols; j++)
			{
				if (matrix[j][i] > max) max = matrix[j][i];
			}
		}

		cout << max << endl;
	}
	else
	{
		int max{};
		max = matrix[0][0];

		for (int i = 0; i < rows; i += rows - 1)
		{
			for (int j = 0; j < cols; j++)
			{
				if (matrix[i][j] > max) max = matrix[i][j];
			}
		}

		for (int i = 0; i < rows; i += rows - 1)
		{
			for (int j = 0; j < cols; j++)
			{
				if (matrix[j][i] > max) max = matrix[j][i];
			}
		}

		cout << max << endl;
	}
}

double volume(double height, double square)
{
	return height * square;
}

double volume(double height, double square, bool cylinder)
{
	return height * square;
}

double volume(double radius)
{
	return (double)4/3 * radius * PI;
}