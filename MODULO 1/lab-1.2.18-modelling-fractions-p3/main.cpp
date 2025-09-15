#include <iostream>
#include "Fraction.h"

void compareFractions();
void calculateAllOperations();

int main()
{
	int option;

	std::cout << "Choose an option:\n";
	std::cout << "1. Perform all arithmetic operations\n";
	std::cout << "2. Compare two fractions\n";
	std::cout << "Enter your choice: ";
	std::cin >> option;

	if (option == 1) {
		calculateAllOperations();
	}
	else if (option == 2) {
		compareFractions();
	}
	else {
		std::cout << "Invalid option. Please choose 1 or 2.\n";
	}

	return 0;
}

void getFractions(int& num1, int& den1, int& num2, int& den2) {
	char slash;

	do {
		std::cout << "Enter the first fraction (n/d): ";
		std::cin >> num1 >> slash >> den1;
		if (slash != '/') {
			std::cout << "Invalid format. Please use 'n/d'.\n";
		}
	} while (slash != '/');

	do {
		std::cout << "Enter the second fraction (n/d): ";
		std::cin >> num2 >> slash >> den2;
		if (slash != '/') {
			std::cout << "Invalid format. Please use 'n/d'.\n";
		}
	} while (slash != '/');
}

void compareFractions() {
	int num1, den1, num2, den2;
	getFractions(num1, den1, num2, den2);

	Fraction frac1(num1, den1);
	Fraction frac2(num2, den2);

	std::cout << "Comparing fractions...\n";

	if (frac1 > frac2) {
		std::cout << frac1 << " > " << frac2 << '\n';
	}
	else if (frac1 < frac2) {
		std::cout << frac1 << " < " << frac2 << '\n';
	}
	else {
		std::cout << frac1 << " = " << frac2 << '\n';
	}
}

void calculateAllOperations() {
	int num1, den1, num2, den2;
	getFractions(num1, den1, num2, den2);

	Fraction frac1(num1, den1);
	Fraction frac2(num2, den2);

	std::cout << frac1 << " + " << frac2 << " = " << frac1 + frac2 << '\n';
	std::cout << frac1 << " - " << frac2 << " = " << frac1 - frac2 << '\n';
	std::cout << frac1 << " * " << frac2 << " = " << frac1 * frac2 << '\n';
	std::cout << frac1 << " / " << frac2 << " = " << frac1 / frac2 << '\n';
}