#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;

void hanoi(int height, int firstColumn, int resultColumn);

int main()
{
	hanoi(4, 1, 2);

	return 0;
}

void hanoi(int height, int firstColumn, int resultColumn)
{
	if (height == 1)
		cout << "Move disk " << height << " from " << firstColumn << " column to " << resultColumn << " column" << endl;
	else
	{
		int temp = 6 - firstColumn - resultColumn;
		hanoi(height - 1, firstColumn, temp);
		cout << "Move disk " << height << " from " << firstColumn << " column to " << resultColumn << " column" << endl;
		hanoi(height - 1, temp, resultColumn);
	}
}
