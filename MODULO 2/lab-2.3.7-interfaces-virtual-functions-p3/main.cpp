#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <cctype>

class StringValidator {
public:
	virtual ~StringValidator() {};
	virtual bool isValid(std::string input) = 0;
};

class MinLengthValidator : public StringValidator {
private:
	int m_minLength;
public:
	MinLengthValidator(int minLength) : m_minLength(minLength) {}

	bool isValid(std::string input) override
	{
		return input.length() >= m_minLength;
	}
};

class HasUpperValidator : public StringValidator {
public:
	bool isValid(std::string input) override
	{
		for (char c : input) 
		{
			if (std::isupper(c)) 
			{
				return true;
			}
		}
		return false;
	}
};

class HasLowerValidator : public StringValidator {
public:
	bool isValid(std::string input) override
	{
		for (char c : input) 
		{
			if (std::islower(c))
			{
				return true;
			}
		}
		return false;
	}
};

class HasDigitValidator : public StringValidator {
public:
	bool isValid(std::string input) override
	{
		for (char c : input) 
		{
			if (std::isdigit(c)) 
			{
				return true;
			}
		}
		return false;
	}
};

class HasSpecialValidator : public StringValidator {
public:
	bool isValid(std::string input) override
	{
		for (char c : input) 
		{
			if (std::ispunct(c))
			{
				return true;
			}
		}
		return false;
	}
};

class PasswordValidator : public StringValidator {
private:
	std::vector<std::unique_ptr<StringValidator>> m_rules;

public:
	PasswordValidator() {
		m_rules.push_back(std::make_unique<MinLengthValidator>(8));
		m_rules.push_back(std::make_unique<HasUpperValidator>());
		m_rules.push_back(std::make_unique<HasLowerValidator>());
		m_rules.push_back(std::make_unique<HasDigitValidator>());
		m_rules.push_back(std::make_unique<HasSpecialValidator>());
	}

	bool isValid(std::string input) override 
	{
		for (const auto& rule : m_rules)
		{
			if (!rule->isValid(input))
			{
				return false;
			}
		}
		return true;
	}
};

void printValid(StringValidator& validator, std::string input)
{
	std::cout << "The string '" << input << "' is "
		<< (validator.isValid(input) ? "valid" : "invalid")
		<< std::endl;
}

int main() {
	PasswordValidator passwordValidator;

	printValid(passwordValidator, "short");
	printValid(passwordValidator, "nouppercase1!");
	printValid(passwordValidator, "NOLOWERCASE1!");
	printValid(passwordValidator, "NoDigitUpper!");
	printValid(passwordValidator, "NoSpecial1Upper");
	printValid(passwordValidator, "ValidPass1!");

	return 0;
}