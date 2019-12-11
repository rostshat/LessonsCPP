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
		cout << "6 - Transist line\n"; //ÃŠÃ®Ã°Ã°Ã¥ÃªÃ²Ã­Ã® Ã­Ã Ã§Ã¢Ã Ã²Ã¼
		cout << "0 - Exit\n";

		cin >> taskNum;
		if (taskNum == '0') break;

		switch (taskNum)
		{
			case '1':
			{

			}break;
			default:
			{

			}break;
		}
	}

	return 0;
}