#include <iostream>
#include <string>
#include <cctype>

class StringValidator
{
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
		return input.length() > m_minLength;
	}
};

class MaxLengthValidator : public StringValidator {
private:
	int m_maxLength;
public:
	MaxLengthValidator(int maxLength) : m_maxLength(maxLength) {}

	bool isValid(std::string input) override 
	{
		return input.length() < m_maxLength;
	}
};

class PatternValidator : public StringValidator {
private:
	std::string m_pattern;

	bool segmentMatches(std::string segment) const
	{
		if (segment.length() != m_pattern.length()) 
		{
			return false;
		}

		for (size_t i = 0; i < m_pattern.length(); ++i) 
		{
			char p = m_pattern[i];
			char s = segment[i];

			if (p == 'D') 
			{
				if (!std::isdigit(s)) return false;
			}
			else if (p == 'A')
			{
				if (!std::isalpha(s)) return false;
			}
			else if (p == '?') 
			{
				continue;
			}
			else if (std::islower(p))
			{
				if (std::tolower(s) != p) 
					return false;
			}
			else if (std::ispunct(p)) 
			{
				if (s != p)
					return false;
			}
			else {
				if (s != p) 
					return false;
			}
		}
		return true;
	}

public:
	PatternValidator(std::string pattern) : m_pattern(pattern) {}

	bool isValid(std::string input) override 
	{
		if (input.length() < m_pattern.length()) 
		{
			return false;
		}

		for (size_t i = 0; i <= input.length() - m_pattern.length(); ++i) 
		{
			if (segmentMatches(input.substr(i, m_pattern.length())))
			{
				return true;
			}
		}
		return false;
	}
};

void printValid(StringValidator& validator, std::string input)
{
	std::cout << "The string '" << input << "' is "
		<< (validator.isValid(input) ? "valid" : "invalid")
		<< std::endl;
}

int main()
{
	std::cout << "MinLengthValidator" << std::endl;
	MinLengthValidator min(5);
	printValid(min, "hello");
	printValid(min, "welcome");
	std::cout << std::endl;

	std::cout << "MaxLengthValidator" << std::endl;
	MaxLengthValidator max(6);
	printValid(max, "hello");
	printValid(max, "welcome");
	std::cout << std::endl;

	std::cout << "PatternValidator" << std::endl;
	PatternValidator pattern("D");
	printValid(pattern, "there are 2 types of sentences in the world");
	printValid(pattern, "valid and invalid ones");

	return EXIT_SUCCESS;
}