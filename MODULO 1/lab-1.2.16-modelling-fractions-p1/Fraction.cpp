#include "Fraction.h"

#include <string>

std::ostream& operator<< (std::ostream& out, const Fraction& fraction)
{
	out << fraction.numerator << "/" << fraction.denominator;
	return out;
}

Fraction::Fraction(int numerator, int denominator) :
	numerator { numerator }, denominator { denominator }
{

}

double Fraction::toDecimal() const
{
	return static_cast<double>(numerator) / denominator;
}

std::string Fraction::toString() const
{
	return std::to_string(numerator) + "/" + std::to_string(denominator);
}
