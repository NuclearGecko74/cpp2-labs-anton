#include "Line2D.h"

#include <cassert>

static constexpr double relEps{ 1e-8 };
static constexpr double absEps{ 1e-12 };

static bool approximatelyEqualRel(double a, double b, double relEpsilon);
static bool approximatelyEqualAbsRel(double a, double b, double absEpsilon, double relEpsilon);

Line2D::Line2D(const Point2D& p1, const Point2D& p2) :
	p1{ p1 }, p2{ p2 }
{
	assert(!approximatelyEqualAbsRel(p2.x - p1.x, 0.0, absEps, relEps) && "Undefined Slope!");

	slope = (p2.y - p1.y) / (p2.x - p1.x);
	yIntercept = p1.y - (slope * p1.x);
}

bool Line2D::contains(const Point2D& other) const
{
	return approximatelyEqualAbsRel(other.y, (slope * other.x) + yIntercept, absEps, relEps);
}

std::ostream& operator<< (std::ostream& out, const Line2D& line)
{
	out << "y = ";

	if (!approximatelyEqualAbsRel(line.slope, 1, absEps, relEps))
		out << line.slope;
	out << "x";
	if (!approximatelyEqualAbsRel(line.yIntercept, 0, absEps, relEps))
		out << " + " << line.yIntercept;
	return out;
}

static bool approximatelyEqualRel(double a, double b, double relEpsilon)
{
	return (std::abs(a - b) <= (std::max(std::abs(a), std::abs(b)) * relEpsilon));
}

static bool approximatelyEqualAbsRel(double a, double b, double absEpsilon, double relEpsilon)
{
	if (std::abs(a - b) <= absEpsilon)
		return true;

	return approximatelyEqualRel(a, b, relEpsilon);
}