#include "Header.h"

class Fraction {
	int numerator;
	int denominator;
public:
	Fraction() {
		numerator = 1;
		denominator = 1;
	}
	Fraction(int first, int second) {
		numerator = first;
		denominator = second;
	}
	void Initial(int first, int second){
		numerator = first;
		denominator = second;
	}
	void Show(){
		printf_s("Fraction: %d/%d\n", numerator, denominator);
	}
	~Fraction() //Деструктор
	{
		printf_s("Destructor\n");
	}
};

int main()
{
	Fraction firstFraction(5, 4);
	firstFraction.Show();
	firstFraction.Initial(2, 3);
	firstFraction.Show();

	return 0;
}