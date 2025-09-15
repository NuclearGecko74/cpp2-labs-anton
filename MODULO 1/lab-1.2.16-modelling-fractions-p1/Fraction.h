#pragma once

#include <iostream>

class Fraction
{
private:
	int numerator;
	int denominator;

public:
	Fraction(int numerator, int denominator);

	double toDecimal() const;
	std::string toString() const;

	friend std::ostream& operator<< (std::ostream& out, const Fraction& fraction);
};

