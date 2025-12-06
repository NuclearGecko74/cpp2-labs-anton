#include <iostream>
#include <vector>
#include <exception>
#include <expected>

class Stack {
public:
	Stack() = default;

	void push(float n)
	{
		m_buffer.push_back(n);
	}

	void pop()
	{
		if (!m_buffer.empty())
		{
			m_buffer.pop_back();
		}
	}

	float top()
	{
		if (m_buffer.empty())
		{
			throw std::runtime_error("stack is empty.");
		}
		return m_buffer.back();
	}

private:
	std::vector<float> m_buffer{};

	friend std::ostream& operator<<(std::ostream& os, Stack& stack);
	friend std::istream& operator>>(std::istream& is, Stack& stack);
};

std::ostream& operator<<(std::ostream& os, Stack& stack)
{
	try
	{
		float value = stack.top();
		os << value << std::endl;
		stack.pop();
	}
	catch (const std::exception& e)
	{
		os << "Exception: " << e.what() << std::endl;
	}
	return os;
}
std::istream& operator>>(std::istream& is, Stack& stack)
{
	float n;
	is >> n;
	stack.m_buffer.push_back(n);
	return is;
}

int main()
{
	Stack stack;
	int count;

	std::cout << "Cuantos elementos deseas agregar: ";
	std::cin >> count;

	for (int i = 0; i < count; i++) 
	{
		std::cin >> stack;
	}

	std::cout << "Cuantos elementos deseas sacar: ";
	std::cin >> count;

	for (int i = 0; i < count; i++)
	{
		std::cout << stack;
	}

	return 0;
}