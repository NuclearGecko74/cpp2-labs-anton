#include <iostream>

class AdHocSquare
{
private:
	double    side;
public:
	AdHocSquare(double side)
	{
		this->side = side;
	}

	void set_side(const double side)
	{
		if (side >= 0)
		{
			this->side = side;
		}
	}

	inline double get_area() const { return side * side; }
};


class LazySquare
{
private:
	double    side;
	double    area;
	bool      side_changed;
public:
	LazySquare(double side)
	{
		this->side = side;
		area = side * side;
		side_changed = false;
	}

	void set_side(const double side)
	{
		if (side >= 0)
		{
			this->side = side;
			side_changed = true;
		}
	}
	double get_area()
	{
		if (side_changed)
		{
			area = side * side;
			side_changed = false;
			std::cout << "Area in LazySquare updated within 'get_area' function.\n";
		}
		return area;
	}

};

int main()
{
	AdHocSquare* sq1 = new AdHocSquare(4);
	std::cout << "Area 1 = " << (*sq1).get_area() << '\n';

	LazySquare* sq2 = new LazySquare(6);
	std::cout << "Area 2 = " << (*sq2).get_area() << '\n';

	sq1->set_side(5);
	sq2->set_side(7);

	std::cout << "Area 1 = " << (*sq1).get_area() << '\n';
	std::cout << "Area 2 = " << (*sq2).get_area() << '\n';

	delete sq1;
	delete sq2;
}