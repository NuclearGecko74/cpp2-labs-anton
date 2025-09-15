#pragma once

#include <iostream>

class Fraction
{
private:
	int numerator;
	int denominator;

public:
	Fraction(int numerator, int denominator);
	Fraction(int numerator);
	Fraction();

	double toDecimal() const;
	std::string toString() const;

	Fraction reciprocal() const;

public:
	// Overloaded Operators
	Fraction operator+(const Fraction& other) const;
	Fraction operator+(int number) const;

	Fraction operator-(const Fraction& other) const;
	Fraction operator-(int number) const;

	Fraction operator*(const Fraction& other) const;
	Fraction operator*(int number) const;

	Fraction operator/(const Fraction& other) const;
	Fraction operator/(int number) const;

	bool operator<(const Fraction& other) const;
	bool operator>(const Fraction& other) const;

	friend std::ostream& operator<< (std::ostream& out, const Fraction& fraction);

private:
	// Helper functions
	int gcd_eucl(int a, int b) const;
	void reduce();
};