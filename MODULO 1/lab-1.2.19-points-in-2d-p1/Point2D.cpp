#include "Point2D.h"
#include <cmath>

Point2D::Point2D(float x, float y) :
	x {x}, y {y}
{

}

Point2D::Point2D() :
	Point2D(0.f, 0.f)
{

}

float Point2D::distanceTo(const Point2D& other) const
{
	return sqrt((x - other.x) * (x - other.x) + (y - other.y) * (y - other.y));
}