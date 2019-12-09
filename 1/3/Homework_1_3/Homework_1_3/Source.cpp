#include <iostream>
#include <stdlib.h>
using namespace std;

void main() 
{
		short taskNum;

		cout << "Choose your task: \n";
		cout << "1 - Square of sphere\n";
		cout << "2 - Map\n";
		cout << "3 - Descending sort\n";
		cout << "4 - User Number Operations\n";
		cin >> taskNum;
		if (taskNum == 1)
		{
			const float PI = 3.14f;
			float radius;

			cout << "\x1B[2J\x1B[H";
			cout << "Enter your radius: ";
			cin >> radius;

			float vSphere = (4.0 / 3.0) * PI * (radius * radius * radius);

			cout << "The V of your shere (4/3 * PI * radius^3) = " << vSphere;



		}
		else if (taskNum == 2)
		{
			float kilometrsInSm;
			float distanceSantimetres;

			cout << "\x1B[2J\x1B[H";
			cout << "Enter km in sm: ";
			cin >> kilometrsInSm;
			cout << endl;

			cout << "Enter your distance: ";
			cin >> distanceSantimetres;
			cout << endl;

			cout << "Distance in km: " << kilometrsInSm * distanceSantimetres << endl;
		}
		else if (taskNum == 3)
		{
			float firstNum;
			float secondNum;
			float thirdNum;

			cout << "\x1B[2J\x1B[H";
			cout << "Enter firstNum: ";
			cin >> firstNum;
			cout << endl;

			cout << "Enter secondNum: ";
			cin >> secondNum;
			cout << endl;

			cout << "Enter thirdNum: ";
			cin >> thirdNum;
			cout << endl;

			float numbers[3] = { firstNum, secondNum, thirdNum };
			int length = 3;

			/*Bubble sort*/
			for (int i = 0; i < length; ++i)
			{
				for (int j = 0; j < length - i; j++)
				{
					if (numbers[j] < numbers[j + 1])
					{
						int temp = numbers[j]; //временный 
						numbers[j] = numbers[j + 1];
						numbers[j + 1] = temp;
					}
				}
			}
			for (int i = 0; i < length; ++i)
			{
				cout << numbers[i] << " ";
			}
			cout << endl;

		}
		else if (taskNum == 4)
		{
			float userNum;

			cout << "\x1B[2J\x1B[H";
			cout << "Enter yout number: ";
			cin >> userNum;
			cout << endl;

			if (userNum >= 50)
			{
				cout << userNum << " * " << userNum << " = " << userNum * userNum;
			}
			else if (userNum > 10 && userNum < 30)
			{
				cout << 0;
			}
			else
			{
				cout << "Error";
			}
		}
		else
		{
			cout << "Enter the correct task number";
		}
}