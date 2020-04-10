#include "Header.h"

class Fraction {
	int numerator;
	int denominator;
public:
	friend Fraction operator+ (const Fraction& first, const Fraction second);

	Fraction() {
		numerator = 1;
		denominator = 1;
	}
	Fraction(int first, int second) {
		numerator = first;
		denominator = second;
	}
	Fraction(const Fraction &old) {
		this->numerator = old.numerator;
		this->denominator = old.denominator;
	}
	~Fraction() //Деструктор
	{
		printf_s("Destructor\n");
	}

	void Initial(int first, int second){
		numerator = first;
		denominator = second;
	}
	void Show(){
		printf_s("Fraction: %d/%d\n", numerator, denominator);
	}

	Fraction& operator + (const Fraction& old, int a) {
		this->numerator = old.numerator + a;
	}
};

//Fraction& operator+ (const Fraction& first, const Fraction& second) {
//	
//
//	return *temp;
//}

int main()
{
	Fraction firstFraction(5, 4);
	Fraction copyFraction(firstFraction);

	Fraction plusFraction = firstFraction + copyFraction;

	firstFraction.Show();
	copyFraction.Show();
	plusFraction.Show();


	firstFraction.Initial(2, 3);
	firstFraction.Show();

	return 0;
}