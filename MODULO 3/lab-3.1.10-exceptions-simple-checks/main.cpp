#include <iostream>
#include <string>
#include <vector>
#include <exception>

class MatrixException : public std::exception {
private:
	std::string m_message;
public:
	MatrixException(const std::string& message) : m_message(message) {}
	const char* what() const noexcept override
	{
		return m_message.c_str();
	}
};

class Matrix {
private:
	int m_rows;
	int m_cols;
	std::vector<std::vector<int>> m_data;

public:
	Matrix(int rows, int cols) : m_rows(rows), m_cols(cols) 
	{
		if (rows <= 0 || cols <= 0) 
		{
			throw MatrixException("Matrices don't fit.");
		}
		m_data.resize(m_rows, std::vector<int>(m_cols, 0));
	}

	void addValue(int row, int col, int value) 
	{
		if (row < 0 || row >= m_rows || col < 0 || col >= m_cols)
		{
			throw MatrixException("Invalid index.");
		}
		m_data[row][col] = value;
	}

	Matrix add(const Matrix& other) const
	{
		if (m_rows != other.m_rows || m_cols != other.m_cols)
		{
			throw MatrixException("Matrices don't fit.");
		}

		Matrix result(m_rows, m_cols);
		for (int i = 0; i < m_rows; ++i) 
		{
			for (int j = 0; j < m_cols; ++j)
			{
				result.m_data[i][j] = m_data[i][j] + other.m_data[i][j];
			}
		}
		return result;
	}

	void print() const 
	{
		for (int i = 0; i < m_rows; ++i) 
		{
			for (int j = 0; j < m_cols; ++j)
			{
				std::cout << m_data[i][j] << (j == m_cols - 1 ? "" : " ");
			}
			std::cout << std::endl;
		}
	}
};

int main() {
	int r1, c1, r2, c2, r3, c3;
	std::cin >> r1 >> c1 >> r2 >> c2 >> r3 >> c3;

	try
	{
		Matrix a(r1, c1);
		Matrix b(r2, c2);
		Matrix c(r3, c3);

		try 
		{
			Matrix resultAb = a.add(b);
			resultAb.print();
		}
		catch (const MatrixException& e)
		{
			std::cout << e.what() << std::endl;
		}

		try 
		{
			Matrix resultAc = a.add(c);
			resultAc.print();
		}
		catch (const MatrixException& e)
		{
			std::cout << e.what() << std::endl;
		}

		try 
		{
			Matrix resultBc = b.add(c);
			resultBc.print();
		}
		catch (const MatrixException& e) 
		{
			std::cout << e.what() << std::endl;
		}

	}
	catch (const MatrixException& e)
	{
		std::cout << e.what() << std::endl;
	}

	return 0;
}