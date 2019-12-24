#include <iostream>
#include <iomanip>
#include <time.h>
#include <stdlib.h>

using namespace std;

#define PI 3.141592

double volume(double height, double square);
double volume(double height, double square, bool cylinder);
double volume(double radius);

int main()
{
	char taskNum{};

	while (true || taskNum != '0')
	{
		system("cls");
		cout << "Choise your task: \n";
		cout << "1 - 33 to 127 \n";
		cout << "2 - Drawing \n";
		cout << "3 - All without 3,6\n";
		cout << "4 - MassRevers\n";
		cout << "4 - Calculator\n";
		cout << "5 - Difference in array\n";
		cout << "6 - MaxNum x%3 == 0\n"; //��������� �������
		cout << "0 - Exit\n";

		cin >> taskNum;
		if (taskNum == '0') break;

		switch (taskNum)
		{
			case '1':
			{
				char choose{};

				cout << "Select your figure foor get it`s volume: \n";
				cout << "Parallelepiped: \n";
				cout << "Cylinder: \n";
				cout << "Sphere: \n";
				cin >> choose;
				cout << endl;

				switch (choose)
				{
					case '1':
					{
						double height{};
						double square{};

						cout << "Enter your height: ";
						cin >> height;
						cout << "Enter your square: ";
						cin >> square;

						cout << "V: " << volume(height, square) << endl;

						break;
					}
					case '2':
					{
						double height{};
						double square{};

						cout << "Enter your height: ";
						cin >> height;
						cout << "Enter your square: ";
						cin >> square;

						cout << "V: " << volume(height, square, true) << endl;

						break;
					}
					case '3':
					{
						double radius{};

						cout << "Enter your radius: ";
						cin >> radius;

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