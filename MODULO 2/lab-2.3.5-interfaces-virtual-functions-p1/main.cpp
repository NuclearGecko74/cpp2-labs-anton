#include <iostream>
#include <string>

class StringValidator {
public:
	virtual ~StringValidator() {};
	virtual bool isValid(std::string input) = 0;
};

class ExactValidator : public StringValidator {
private:
	std::string secret_string;

public:
	ExactValidator(std::string secret) : secret_string(secret) {}

	bool isValid(std::string input) override
	{
		return input == secret_string;
	}
};


class DummyValidator : public StringValidator {
public:
	bool isValid(std::string input) override;
};

bool DummyValidator::isValid(std::string input)
{
	return true;
}


void printValid(StringValidator& validator, std::string input)
{
	std::cout << "The string '" << input << "' is " << (validator.isValid(input) ? "valid" : "invalid");
}


int main()
{
	DummyValidator dummy;
	printValid(dummy, "hello");
	std::cout << std::endl;

	ExactValidator exact("secret");
	printValid(exact, "hello");
	std::cout << std::endl;
	printValid(exact, "secret");
	std::cout << std::endl;

	return EXIT_SUCCESS;
}