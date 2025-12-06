#include <iostream>
#include <vector>
#include <stdexcept>
#include <iomanip>

class Matrix
{
public:
	Matrix(int rows, int cols, int initialValue = 0)
		: m_rows(rows), m_cols(cols)
	{
		m_buffer.resize(rows, std::vector<int>(cols, initialValue));
	}

	Matrix operator+(int value) const
	{
		Matrix result(m_rows, m_cols);
		for (int i = 0; i < m_rows; ++i)
		{
			for (int j = 0; j < m_cols; ++j)
			{
				result.m_buffer[i][j] = m_buffer[i][j] + value;
			}
		}
		return result;
	}

	Matrix operator+(const Matrix& other) const
	{
		if (m_rows != other.m_rows || m_cols != other.m_cols)
		{
			throw std::invalid_argument("Matrix dimensions must match for addition.");
		}

		Matrix result(m_rows, m_cols);
		for (int i = 0; i < m_rows; ++i)
		{
			for (int j = 0; j < m_cols; ++j)
			{
				result.m_buffer[i][j] = m_buffer[i][j] + other.m_buffer[i][j];
			}
		}
		return result;
	}

	Matrix operator-(int value) const
	{
		Matrix result(m_rows, m_cols);
		for (int i = 0; i < m_rows; ++i)
		{
			for (int j = 0; j < m_cols; ++j)
			{
				result.m_buffer[i][j] = m_buffer[i][j] - value;
			}
		}
		return result;
	}

	Matrix operator-(const Matrix& other) const
	{
		if (m_rows != other.m_rows || m_cols != other.m_cols)
		{
			throw std::invalid_argument("Matrix dimensions must match for subtraction.");
		}

		Matrix result(m_rows, m_cols);
		for (int i = 0; i < m_rows; ++i)
		{
			for (int j = 0; j < m_cols; ++j)
			{
				result.m_buffer[i][j] = m_buffer[i][j] - other.m_buffer[i][j];
			}
		}
		return result;
	}

	Matrix operator*(int value) const
	{
		Matrix result(m_rows, m_cols);
		for (int i = 0; i < m_rows; ++i)
		{
			for (int j = 0; j < m_cols; ++j)
			{
				result.m_buffer[i][j] = m_buffer[i][j] * value;
			}
		}
		return result;
	}

	Matrix operator*(const Matrix& other) const
	{
		if (m_cols != other.m_rows)
		{
			throw std::invalid_argument("Matrix A columns must match Matrix B rows for multiplication.");
		}

		Matrix result(m_rows, other.m_cols);
		for (int i = 0; i < m_rows; ++i)
		{
			for (int j = 0; j < other.m_cols; ++j)
			{
				for (int k = 0; k < m_cols; ++k)
				{
					result.m_buffer[i][j] += m_buffer[i][k] * other.m_buffer[k][j];
				}
			}
		}
		return result;
	}

private:
	int m_rows;
	int m_cols;
	std::vector<std::vector<int>> m_buffer;

	friend std::ostream& operator<<(std::ostream& os, const Matrix& matrix);
};

std::ostream& operator<<(std::ostream& os, const Matrix& matrix)
{
	for (const auto& row : matrix.m_buffer)
	{
		for (const auto& val : row)
		{
			os << std::setw(4) << val;
		}
		os << '\n';
	}
	return os;
}

int main()
{
	Matrix A(2, 2, 1);
	Matrix B(2, 2, 3);

	std::cout << "Matrix A:\n" << A;
	std::cout << "Matrix B:\n" << B;

	std::cout << "A + B:\n" << (A + B);
	std::cout << "A - B:\n" << (A - B);
	std::cout << "A * B:\n" << (A * B);

	std::cout << "A + 10:\n" << (A + 10);
	std::cout << "B * 2:\n" << (B * 2);

	Matrix C(3, 3, 5);
	std::cout << "Matrix C (Different Size):\n" << C;

	std::cout << "--- Exception Tests ---\n";

	try
	{
		std::cout << "Trying A + C...\n";
		Matrix res = A + C;
	}
	catch (const std::exception& e)
	{
		std::cout << "Exception caught: " << e.what() << '\n';
	}

	try
	{
		std::cout << "Trying A - C...\n";
		Matrix res = A - C;
	}
	catch (const std::exception& e)
	{
		std::cout << "Exception caught: " << e.what() << '\n';
	}

	try
	{
		std::cout << "Trying A * C...\n";
		Matrix res = A * C;
	}
	catch (const std::exception& e)
	{
		std::cout << "Exception caught: " << e.what() << '\n';
	}

	return 0;
}