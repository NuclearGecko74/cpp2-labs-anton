#include <iostream>

#include "Point2D.h"

int main()
{
	float x1{}, x2{};
	float y1{}, y2{};

	std::cout << "Enter point 1 (x1 y1): ";
	std::cin >> x1 >> y1;
	Point2D p1(x1, y1);

	std::cout << "Enter point 2 (x2 y2): ";
	std::cin >> x2 >> y2;
	Point2D p2(x2, y2);

	std::cout << p1.distanceTo(p2) << '\n';

	return EXIT_SUCCESS;
}