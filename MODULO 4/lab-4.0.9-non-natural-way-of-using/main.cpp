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
		m_buffer.pop_back();
	}

	std::expected<float, std::string> top()
	{
		try 
		{
			if (m_buffer.empty())
			{
				throw std::runtime_error("stack is empty.");
			}
			return m_buffer.back();
		}
		catch (const std::exception& ex)
		{
			std::cout << "Exception: " << ex.what() << std::endl;
		}
		return std::unexpected("Stack is empty error");
	}

private:
	std::vector<float> m_buffer{};

	friend std::ostream& operator<<(std::ostream& os, const Stack& stack);
	friend std::istream& operator>>(std::istream& is, Stack& stack);
};

std::ostream& operator<<(std::ostream& os, const Stack& stack)
{
	int stackSize = stack.m_buffer.size();
	for (int i = stackSize - 1; i >= 0; i--)
	{
		os << stack.m_buffer[i] << '\n';
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
	std::cin >> stack;
	std::cin >> stack;
	std::cin >> stack;

	std::cout << stack;
}