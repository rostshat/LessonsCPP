#include <iostream>
#include <time.h>
using namespace std;

int getRandomInt(int min = 0, int max = 100);
int getRandomIntRB(int min = 0, int max = 100);

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
					
			}break;
			case '2':
			{
				const int NUMBER_OF_GOODS = 15;
				const int MIN_PRICE = 20;
				const int MAX_PRICE = 120;
				const int ATTRIBUTES = 1;

				int goods[15][1] = { 0 };
				int temp{}, average{};

				for (int i = 0; i < NUMBER_OF_GOODS; i++)
				{
					for (int j = 0; j < ATTRIBUTES; j++)
					{
						goods[i][j] = getRandomIntRB(MIN_PRICE, MAX_PRICE);;
					}
				}

				for (int i = 0; i < NUMBER_OF_GOODS; i++)
				{
					for (int j = 0; j < ATTRIBUTES; j++)
					{
						temp += goods[i][j];
					}
				}

				average = temp / NUMBER_OF_GOODS;

				cout << "Avegare: " << average << endl;

				for (int i = 0; i < NUMBER_OF_GOODS; i++)
				{
					for (int j = 0; j < ATTRIBUTES; j++)
					{
						if (goods[i][j] < average)
						{
							cout << i << " : " << goods[i][j] << endl;
						}
					}
				}
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

int getRandomIntRB(int min, int max)
{
	return rand() % (max - min + 1) + min;
}