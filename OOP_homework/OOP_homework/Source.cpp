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
	Fraction(const Fraction &old) {
		this->numerator = old.numerator;
		this->denominator = old.denominator;
	}
	~Fraction() //Деструктор
	{
		//printf_s("Destructor\n");
	}

	void Initial(int first, int second){
		numerator = first;
		denominator = second;
	}
	void Print(){
		printf_s("Fraction: %d/%d\n", numerator, denominator);
	}
	void Short(){
		if ((this->numerator % this->denominator) == 0)
		{
			this->numerator = this->numerator / this->denominator;
			this->denominator = 1;
		}
	}
	Fraction operator =(Fraction a) {
		Fraction temp;
		
		temp.numerator = a.numerator;
		temp.denominator = a.denominator;

		return temp;
	}

	friend  Fraction operator +(Fraction b, Fraction a);
	friend  Fraction operator -(Fraction b, Fraction a);
	friend  Fraction operator *(Fraction b, Fraction a);
	friend  Fraction operator /(Fraction b, Fraction a);
};

Fraction operator +(Fraction b, Fraction a) {
	Fraction temp(b.numerator * a.denominator + a.numerator * b.denominator,b.denominator * a.denominator); 
	
	return temp;
}

Fraction operator -(Fraction b, Fraction a) {
	Fraction temp(b.numerator * a.denominator - a.numerator * b.denominator, b.denominator * a.denominator);

	return temp;
}

Fraction operator *(Fraction b, Fraction a) {
	Fraction temp(b.numerator * a.numerator, b.denominator * a.denominator);

	return temp;
}

Fraction operator /(Fraction b, Fraction a) {
	Fraction temp(b.numerator * a.denominator, b.denominator * a.numerator);

	return temp;
}

int main()
{
	/*Не знаю нужло ли было реализовывать массив из обьектов и их создание, но в задании этого небыло*/

	Fraction aFraction(5, 3);
	Fraction bFraction(2, 5);
	Fraction cFraction(10, 6);
	Fraction dFraction(7, 2);
	Fraction eFraction;

	aFraction.Print();
	bFraction.Print();
	Fraction plusFraction = aFraction + bFraction;
	printf_s("Fraction 1 + Fraction 2: ");
	plusFraction.Print();
	WRAP;

	bFraction.Print();
	cFraction.Print();
	Fraction minusFraction = bFraction - cFraction;
	printf_s("Fraction 2 - Fraction 3: ");
	minusFraction.Print();
	WRAP;

	cFraction.Print();
	dFraction.Print();
	Fraction multiFraction = cFraction * dFraction;
	printf_s("Fraction 3 * Fraction 4: ");
	multiFraction.Print();
	WRAP;

	dFraction.Print();
	eFraction.Print();
	Fraction fractionFraction = dFraction / eFraction;
	printf_s("Fraction 4 / Fraction 5: ");
	fractionFraction.Print();
	dFraction.Print();
	aFraction.Print();
	Fraction fraction1Fraction = dFraction / aFraction;
	printf_s("Fraction 4 / Fraction 1: ");
	fraction1Fraction.Print();
	WRAP;

	return 0;
}