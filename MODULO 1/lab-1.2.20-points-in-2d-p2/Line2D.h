#pragma once

#include <iostream>
#include "Point2D.h"

class Line2D
{
private:
	Point2D p1;
	Point2D p2;

	float slope;
	float yIntercept;

public:
	Line2D(const Point2D& p1, const Point2D& p2);

	bool contains(const Point2D& other) const;

	friend std::ostream& operator<< (std::ostream& out, const Line2D& line);
};