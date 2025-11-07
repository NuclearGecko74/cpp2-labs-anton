#include <iostream>
#include <string>

int main()
{
	int a = 8, b = 0, c = 0;
	std::cin >> b;
	try 
	{
		if (b == 0)
		{
			throw "Your input is not valid, you can't divide by zero.";
		}
		c = a / b;
	}
	catch (const char* errorMsg)
	{
		std::cout << errorMsg << std::endl;
	}
	std::cout << c << std::endl;
	return 0;
}