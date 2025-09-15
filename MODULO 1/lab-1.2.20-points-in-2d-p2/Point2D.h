#pragma once

#include <iostream>

class Line2D;

class Point2D
{
private:
	float x;
	float y;
public:
	Point2D(float x, float y);
	Point2D();

	Point2D(const Point2D& other);

	float distanceTo(const Point2D& other) const;

	inline float getX() const { return x; }
	inline float getY() const { return y; }

public:
	// Overloaded Operators
	bool operator==(const Point2D& other) const;
	bool operator!=(const Point2D& other) const;

	friend std::ostream& operator<<(std::ostream& out, const Point2D& point);

	friend class Line2D;
};