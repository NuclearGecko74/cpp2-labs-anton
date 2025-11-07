#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <stdexcept>
#include <ios>

class Matrix {
private:
	std::vector<std::vector<int>> m_data;

public:
	Matrix() 
	{
		m_data.resize(2, std::vector<int>(2, 0));
	}

	void loadMatrix(const std::string& filePath)
	{
		std::ifstream inFile;
		inFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
		try
		{
			inFile.open(filePath);
			inFile >> m_data[0][0] >> m_data[0][1];
			inFile >> m_data[1][0] >> m_data[1][1];
			inFile.close();
		}
		catch (const std::ios_base::failure& e) 
		{
			std::cout << "File not found at: path" << std::endl;
			throw;
		}
	}

	void saveMatrix(const std::string& filePath)
	{
		std::ofstream outFile;
		outFile.exceptions(std::ofstream::failbit | std::ofstream::badbit);
		try 
		{
			outFile.open(filePath);
			outFile << m_data[0][0] << " " << m_data[0][1] << "\n";
			outFile << m_data[1][0] << " " << m_data[1][1] << "\n";
			outFile.close();
		}
		catch (const std::ios_base::failure& e) 
		{
			std::cout << "No rights to write to file: path" << std::endl;
			throw;
		}
	}
};

int main()
{
	Matrix myMatrix;

	std::string nonExistentPath = "non_existent_file_12345.txt";
	std::string unwritablePath = "/root/no_permission_file_12345.txt";

	std::cout << "Simulate both situations handled:" << std::endl << std::endl;

	try 
	{
		myMatrix.loadMatrix(nonExistentPath);
	}
	catch (...) 
	{
	}

	try
	{
		myMatrix.saveMatrix(unwritablePath);
	}
	catch (...) 
	{
	}

	return EXIT_SUCCESS;
}