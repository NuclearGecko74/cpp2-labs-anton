#include <iostream>

#include "Fraction.h"

int main()
{
	int num{};
	int den{};
	char op{};

	std::cin >> num >> op >> den;
	while (op != '/')
	{
		std::cout << "Invalid Operation!\n";
		std::cin >> num >> op >> den;
	}

	Fraction frac(num, den);
	std::cout << frac << " is " << frac.toDecimal() << " in decimal\n";
	return EXIT_SUCCESS;
}