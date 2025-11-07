#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>
#include <exception>

class InvalidTowerException : public std::exception {
public:
	const char* what() const noexcept override
	{
		return "Invalid tower number.";
	}
};

class InvalidMoveException : public std::exception {
public:
	const char* what() const noexcept override
	{
		return "Invalid move: larger disk on smaller disk.";
	}
};

class EmptyTowerException : public std::exception {
public:
	const char* what() const noexcept override
	{
		return "Source tower is empty.";
	}
};

class TowerOfHanoi {
private:
	std::vector<std::vector<int>> m_towers;

public:
	TowerOfHanoi()
	{
		m_towers.resize(3);
		m_towers[0] = { 3, 2, 1 };
	}

	void moveDisk(int source, int dest)
	{
		int sourceIndex = source - 1;
		int destIndex = dest - 1;

		if (source < 1 || source > 3 || dest < 1 || dest > 3)
		{
			throw InvalidTowerException();
		}

		if (m_towers[sourceIndex].empty())
		{
			throw EmptyTowerException();
		}

		if (!m_towers[destIndex].empty())
		{
			if (m_towers[sourceIndex].back() > m_towers[destIndex].back())
			{
				throw InvalidMoveException();
			}
		}

		int diskToMove = m_towers[sourceIndex].back();
		m_towers[sourceIndex].pop_back();
		m_towers[destIndex].push_back(diskToMove);
	}

	void printTowers() const 
	{
		for (size_t i = 0; i < m_towers.size(); ++i)
		{
			std::cout << "tower_" << (i + 1) << ":";
			if (m_towers[i].empty()) 
			{
				std::cout << " empty";
			}
			else
			{
				for (int disk : m_towers[i]) 
				{
					std::cout << " " << disk;
				}
			}
			std::cout << std::endl;
		}
	}
};

int main() 
{
	TowerOfHanoi game;
	int moveCode;

	while (std::cin >> moveCode && moveCode != 0)
	{
		int source = moveCode / 10;
		int dest = moveCode % 10;

		try 
		{
			game.moveDisk(source, dest);
		}
		catch (const InvalidTowerException& e)
		{
			std::cout << e.what() << std::endl;
		}
		catch (const InvalidMoveException& e) 
		{
			std::cout << e.what() << std::endl;
		}
		catch (const EmptyTowerException& e)
		{
			std::cout << e.what() << std::endl;
		}
		catch (const std::exception& e)
		{
			std::cout << "An unexpected error occurred: " << e.what() << std::endl;
		}
	}

	game.printTowers();

	return 0;
}