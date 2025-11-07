#include <iostream>
#include <string>
#include <exception>

class ValueException : public std::exception {
private:
	std::string m_message;

public:
	ValueException(const std::string& message) : m_message(message) {}
	const char* what() const noexcept override 
	{
		return m_message.c_str();
	}
};

class ValueHolder {
private:
	int m_value;
	int m_minLimit;
	int m_maxLimit;

public:
	ValueHolder(int value, int minLimit, int maxLimit) : m_value(value), m_minLimit(minLimit), m_maxLimit(maxLimit) 
	{
		if (value < minLimit || value > maxLimit) 
		{
			throw ValueException("Initial value exceeds limits.");
		}
	}

	void add(int valueToAdd) 
	{
		int newValue = m_value + valueToAdd;
		if (newValue > m_maxLimit || newValue < m_minLimit)
		{
			throw ValueException("Value could exceed limit.");
		}
		m_value = newValue;
	}

	void subtract(int valueToSubtract)
	{
		int newValue = m_value - valueToSubtract;
		if (newValue > m_maxLimit || newValue < m_minLimit)
		{
			throw ValueException("Value could exceed limit.");
		}
		m_value = newValue;
	}

	int getValue() const 
	{
		return m_value;
	}
};

int main() 
{
	int v1, min1, max1;
	int v2, min2, max2;
	int op1, op2, op3;

	std::cin >> v1 >> min1 >> max1;
	std::cin >> v2 >> min2 >> max2;
	std::cin >> op1 >> op2 >> op3;

	try 
	{
		ValueHolder a(v1, min1, max1);
		ValueHolder b(v2, min2, max2);

		try 
		{
			a.add(op1);
		}
		catch (const ValueException& e)
		{
			std::cout << e.what() << std::endl;
		}

		try 
		{
			b.add(op2);
		}
		catch (const ValueException& e)
		{
			std::cout << e.what() << std::endl;
		}

		try 
		{
			b.add(op3);
		}
		catch (const ValueException& e) 
		{
			std::cout << e.what() << std::endl;
		}

		std::cout << a.getValue() << std::endl;
		std::cout << b.getValue() << "." << std::endl;

	}
	catch (const ValueException& e)
	{
		std::cout << e.what() << std::endl;
	}

	return EXIT_SUCCESS;
}