#include <iostream>
#include <time.h>
using namespace std;


int main()
{
	srand(time(NULL));
	char taskNum{};

	while (true || taskNum != '0')
	{
		system("cls");
		cout << "Choise your task: \n";
		cout << "1 - V of cylinder \n";
		cout << "2 - Max of 3 numbers \n";
		cout << "3 - Deposit calculator\n";
		cout << "4 - Glasn\n";
		cout << "5 - Symbol Line\n";
		cout << "6 - Transist line\n";
		cout << "0 - Exit\n";

		cin >> taskNum;
		if (taskNum == '0') break;

		switch (taskNum)
		{
			case '1':
			{
				const int MAXSIZE = 20;
				const int MAX_MARK = 5;
				const int MIN_MARK = 1;

				int marks[MAXSIZE] = {};

				for (int i = 0; i < MAXSIZE; i++)
				{
					marks[i] = 
				}
				
				for (int i = 1; i <= MAX_MARK; i++)
				{
					int temp{};
					for (int j = 0; j < MAXSIZE; j++)
					{
						if (marks[j] == i) temp++;
					}
					cout << i << " : " << temp << endl;
				}
			}break;
			case '2':
			{
				const int TYPES = 15;
				int goods[TYPES] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};


			}break;
			case '3':
			{

			}break;
			case '4':
			{

			}break;
			default:
			{

			}break;
		}
		system("pause");
	}

	return 0;
}

int getRandomInt(int min, int max)
{
	return rand() % (max - min) + min;
}

int getRandomInt(int min, int max)
{
	return rand() % (max - min) + min;
}