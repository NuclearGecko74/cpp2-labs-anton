#include <iostream>
#include <stdexcept>
#include <string>

class DivideByZeroException : public std::exception {
public:
	const char* what() const noexcept override
	{
		return "Are you kidding me?\nYour input is not valid. You can't divide by zero.";
	}
};

float div(float arg1, float arg2)
{
	if (arg2 == 0.0) 
	{
		throw DivideByZeroException();
	}
	return arg1 / arg2;
}

int main() 
{
	float r, a, b;
	while (std::cin >> a) 
	{
		std::cin >> b;
		try 
		{
			r = div(a, b);
			std::cout << r << std::endl;
		}
		catch (const DivideByZeroException& e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	return EXIT_SUCCESS;
}