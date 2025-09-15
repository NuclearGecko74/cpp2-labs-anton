#include "Fraction.h"

#include <string>
#include <cassert>

std::ostream& operator<< (std::ostream& out, const Fraction& fraction)
{
	if (fraction.denominator < 0)
		std::cout << '-';

	if (fraction.denominator != 1)
	{
		out << fraction.numerator << "/" << abs(fraction.denominator);
	}
	else
	{
		out << fraction.numerator;
	}

	return out;
}

Fraction::Fraction(int numerator, int denominator) :
	numerator{ numerator }, denominator{ denominator }
{
	assert(denominator != 0 && "Cannot divide by zero!");
	reduce();
}

Fraction::Fraction(int numerator) :
	Fraction(numerator, 1)
{

}

Fraction::Fraction() :
	Fraction(0, 1)
{

}

void Fraction::reduce()
{
	int gcd = gcd_eucl(numerator, denominator);
	numerator /= gcd;
	denominator /= gcd;
}

double Fraction::toDecimal() const
{
	return static_cast<double>(numerator) / denominator;
}

std::string Fraction::toString() const
{
	return std::to_string(numerator) + "/" + std::to_string(denominator);
}

Fraction Fraction::reciprocal() const
{
	return { denominator, numerator };
}

Fraction Fraction::operator+(const Fraction& other) const
{
	int num = (numerator * other.denominator) + (other.numerator * denominator);
	int den = denominator * other.denominator;
	return { num, den };
}

Fraction Fraction::operator+(int number) const
{
	Fraction sum = *this + Fraction(number, 1);
	return sum;
}

Fraction Fraction::operator-(const Fraction& other) const
{
	int num = (numerator * other.denominator) - (other.numerator * denominator);
	int den = denominator * other.denominator;
	return { num, den };
}

Fraction Fraction::operator-(int number) const
{
	Fraction sub = *this - Fraction(number, 1);
	return sub;
}

Fraction Fraction::operator*(const Fraction& other) const
{
	int num = numerator * other.numerator;
	int den = denominator * other.denominator;
	return { num, den };
}

Fraction Fraction::operator*(int number) const
{
	Fraction mult = *this * Fraction(number);
	return mult;
}

Fraction Fraction::operator/(const Fraction& other) const
{
	Fraction division = *this * other.reciprocal();
	return division;
}

Fraction Fraction::operator/(int number) const
{
	return { numerator, denominator * number };
}

bool Fraction::operator<(const Fraction& other) const
{
	return this->toDecimal() < other.toDecimal();
}

bool Fraction::operator>(const Fraction& other) const
{
	return this->toDecimal() > other.toDecimal();
}

int Fraction::gcd_eucl(int a, int b) const
{
	while (b != 0)
	{
		int remainder = a % b;
		a = b;
		b = remainder;
	}
	return a;
}