#include <iostream>
#include <array>

class Matrix2D 
{
public:
	Matrix2D() = default;

private:
	std::array<std::array<float, 2>, 2> m_buffer{};

	friend std::ostream& operator<<(std::ostream& os, const Matrix2D& matrix);
	friend std::istream& operator>>(std::istream& is, Matrix2D& matrix);
};

// No es la forma mas eficiente pero se ve chido asi que asi lo dejo
// Una mejor forma seria no usar loops y poner directamente los valores en la matrix
// Eso haria el codigo mas legible y ligeramente mas rapido en debug
std::ostream& operator<<(std::ostream& os, const Matrix2D& matrix)
{
	for (const auto& arr : matrix.m_buffer)
	{
		for (const auto& n : arr)
		{
			os << n << ' ';
		}
		os << '\n';
	}
	return os;
}

// Lo mismo con esta
std::istream& operator>>(std::istream& is, Matrix2D& matrix)
{
	for (auto& arr : matrix.m_buffer)
	{
		for (auto& n : arr)
		{
			is >> n;
		}
	}
	return is;
}

int main()
{
	Matrix2D matrix;

	std::cin >> matrix;
	std::cout << matrix;

	return 0;
}