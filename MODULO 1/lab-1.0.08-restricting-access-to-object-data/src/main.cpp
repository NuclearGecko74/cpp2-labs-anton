#include <iostream>
#include <string>

using namespace std;

class Square
{
private:
	double    side;
	double    area;

public:
	Square(double side);

	// getters
	inline double getSide() const { return side; }
	inline double getArea() const { return area; }

	//setters
	bool setSide(const double side)
	{
		if (side < 0) { return false; }

		this->side = side;
		area = side * side;
		return true;
	}
};

Square::Square(double side)
{
	this->side = side;
	this->area = side * side;
}

void print(Square* square)
{
	cout << "Square: side=" << square->getSide() << " area=" << square->getArea() << endl;
}

int main()
{
	Square s(4);

	print(&s);

	s.setSide(2.0);
	print(&s);

	s.setSide(-33.0);
	print(&s);

	return 0;
}