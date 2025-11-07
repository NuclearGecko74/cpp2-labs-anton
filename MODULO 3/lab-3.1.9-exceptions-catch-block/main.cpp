#include <iostream>
#include <string>
#include <exception>

class NegativeAreaException : public std::exception {
private:
	std::string m_message;

public:
	NegativeAreaException(std::string message) : m_message(message) {}
	const char* what() const noexcept override 
	{
		return m_message.c_str();
	}
};

float squareArea(float a)
{
	if (a <= 0) 
	{
		throw NegativeAreaException("Your input is not valid. The area can't be negative.");
	}
	return a * a;
}

float rectangleArea(float a, float b) 
{
	if (a <= 0 || b <= 0) 
	{
		throw NegativeAreaException("Your input is not valid. The area can't be negative.");
	}
	return a * b;
}

int main()
{
	float a, b;
	std::cin >> a;
	std::cin >> b;
	try
	{
		float rsquare = squareArea(a);
		float rrectangle = rectangleArea(a, b);
		std::cout << rsquare << std::endl << rrectangle << std::endl;
	}
	catch (const NegativeAreaException& e)
	{
		std::cout << e.what() << std::endl;
	}
	return EXIT_SUCCESS;
}