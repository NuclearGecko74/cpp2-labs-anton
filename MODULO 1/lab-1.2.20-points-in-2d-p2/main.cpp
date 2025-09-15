#include <iostream>

#include "Point2D.h"
#include "Line2D.h"

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

	Line2D line(p1, p2);
	std::cout << "\n----------------------------------------\n";
	std::cout << "A line has been generated from the points:\n";
	std::cout << line << '\n';
	std::cout << "----------------------------------------\n";

	float x3{}, y3{};
	std::cout << "Enter point 3 (x3 y3): ";
	std::cin >> x3 >> y3;
	Point2D p3(x3, y3);

	std::cout << "\nChecking if point " << p3 << " is collinear to the line...\n\n";
	if (line.contains(p3))
	{
		std::cout << "The point is collinear\n";
	}
	else
	{
		std::cout << "The point is not collinear\n";
	}

	return EXIT_SUCCESS;
}