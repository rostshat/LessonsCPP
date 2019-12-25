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
T getRandom(T min, T max, int order = 1)
{
	return (T)(rand() % (((int)max - (int)min) * order) + min * order) / order;
}


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
		cout << "3 - All without 3,6\n";
		cout << "4 - MassRevers\n";
		cout << "4 - Calculator\n";
		cout << "5 - Difference in array\n";
		cout << "6 - MaxNum x%3 == 0\n"; //Корректно назвать
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
						int matrix[15][12] = { 0 };
						int min, max;

						cout << "Enter min number: ";
						cin >> min;
						cout << "Enter max number: ";
						cin >> max;
						cout << endl;

						for (int i = 0; i < ROWS; i++)
						{
							for (int j = 0; j < COLS; j++)
							{
								matrix[i][j] = getRandom(min, max);
							}
						}

						for (int i = 0; i < ROWS; i++)
						{
							for (int j = 0; j < COLS; j++)
							{
								cout << setw(4) << matrix[i][j] << ' ';
							}
							cout << endl;
						}

						break;
					}
					case '2':
					{
						char matrix[15][12] = { 0 };
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

						for (int i = 0; i < ROWS; i++)
						{
							for (int j = 0; j < COLS; j++)
							{
								cout << setw(4) << matrix[i][j] << ' ';
							}
							cout << endl;
						}

						break;
					}
					case '3':
					{
						double matrix[15][12] = { 0 };
						double min{}, max{};
						int order{};

						cout << "Enter min number: ";
						cin >> min;
						cout << "Enter max number: ";
						cin >> max;
						cout << "Enter a number of numbers after comma: ";
						cin >> order;
						cout << endl;

						for (int i = 0; i < ROWS; i++)
						{
							for (int j = 0; j < COLS; j++)
							{
								matrix[i][j] = getRandom(min, max, order);
							}
						}

						for (int i = 0; i < ROWS; i++)
						{
							for (int j = 0; j < COLS; j++)
							{
								cout << setw(7) << matrix[i][j] << ' ';
							}
							cout << endl;
						}

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


				break;
			}
			case '4':
			{


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