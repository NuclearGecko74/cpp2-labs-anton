#include <iostream>

#include "Fraction.h"

int main()
{
	int num1, den1, num2, den2;
	char slash;

	do {
		std::cout << "Enter the first fraction (n / d): ";
		std::cin >> num1 >> slash >> den1;
		if (slash != '/') {
			std::cout << "Invalid format. Please use 'n / d'.\n";
		}
	} while (slash != '/');

	do {
		std::cout << "Enter the second fraction (n / d): ";
		std::cin >> num2 >> slash >> den2;
		if (slash != '/') {
			std::cout << "Invalid format. Please use 'n / d'.\n";
		}
	} while (slash != '/');

	Fraction frac1(num1, den1);
	Fraction frac2(num2, den2);

	std::cout << frac1 << " + " << frac2 << " = " << frac1 + frac2 << '\n';
	std::cout << frac1 << " - " << frac2 << " = " << frac1 - frac2 << '\n';
	std::cout << frac1 << " * " << frac2 << " = " << frac1 * frac2 << '\n';
	std::cout << frac1 << " / " << frac2 << " = " << frac1 / frac2 << '\n';

	return EXIT_SUCCESS;
}