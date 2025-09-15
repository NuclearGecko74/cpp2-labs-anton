#include "Point2D.h"
#include <cmath>

Point2D::Point2D(float x, float y) :
	x{ x }, y{ y }
{

}

Point2D::Point2D() :
	Point2D(0.f, 0.f)
{

}

Point2D::Point2D(const Point2D& other) :
	x{ other.x }, y{ other.y }
{
}

float Point2D::distanceTo(const Point2D& other) const
{
	return sqrt((x - other.x) * (x - other.x) + (y - other.y) * (y - other.y));
}

bool Point2D::operator!=(const Point2D& other) const
{
	return (x != other.x) || (y != other.y);
}

bool Point2D::operator==(const Point2D& other) const
{
	return (x == other.x) && (y == other.y);
}

std::ostream& operator<<(std::ostream& out, const Point2D& point)
{
	out << '(' << point.x << ", " << point.y << ')';
	return out;
}