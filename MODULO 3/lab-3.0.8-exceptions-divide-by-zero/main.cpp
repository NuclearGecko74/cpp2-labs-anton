#include <iostream>
#include <exception>

class DivideByZeroException : public std::exception {
public:
	const char* what() const noexcept override 
	{
		return "Your input is not valid, you can't divide by zero.";
	}
};

int main() 
{
	int numerator, denominator;
	std::cin >> numerator;
	std::cin >> denominator;

	try
	{
		if (denominator == 0) 
		{
			throw DivideByZeroException();
		}
		int result = numerator / denominator;
		std::cout << result << std::endl;
	}
	catch (const DivideByZeroException& e) 
	{
		std::cout << e.what() << std::endl;
	}

	return EXIT_SUCCESS;
}