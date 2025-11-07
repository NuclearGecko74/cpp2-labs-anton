#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <exception>
#include <stdexcept>
#include <algorithm>
#include <iterator>

class IpException : public std::exception {
private:
	std::string m_message;

public:
	IpException(const std::string& message) : m_message(message) {}

	const char* what() const noexcept override
	{
		return m_message.c_str();
	}
};

class IpAddress {
private:
	std::vector<int> m_octets;

	void validateIpString(const std::string& ipString) 
	{
		std::stringstream ss(ipString);
		std::string segment;
		while (std::getline(ss, segment, '.'))
		{
			try 
			{
				size_t charsProcessed = 0;
				int octet = std::stoi(segment, &charsProcessed);

				if (charsProcessed != segment.length())
				{
					throw IpException("Exception - Invalid IP number.");
				}
				if (octet < 0 || octet > 255)
				{
					throw IpException("Exception - Invalid IP number.");
				}
				m_octets.push_back(octet);
			}
			catch (const std::exception& e) 
			{
				throw IpException("Exception - Invalid IP number.");
			}
		}
		if (m_octets.size() != 4) 
		{
			throw IpException("Exception - Invalid IP number.");
		}
	}

public:
	IpAddress(const std::string& ipString)
	{
		validateIpString(ipString);
	}

	void printSubnet(int range) const
	{
		const int validRanges[] = { 1, 2, 4, 8, 16, 32, 64, 128, 256 };
		const int* begin = validRanges;
		const int* end = validRanges + 9;
		const int* found = std::find(begin, end, range);

		if (found == end) 
		{
			throw IpException("Exception - invalid range.");
		}

		for (int i = 0; i < range; ++i) 
		{
			int lastOctet = m_octets[3] + i;
			if (lastOctet > 255) 
			{
				break;
			}
			std::cout << m_octets[0] << "." << m_octets[1] << "."
				<< m_octets[2] << "." << lastOctet << std::endl;
		}
	}

	void print() const
	{
		std::cout << m_octets[0] << "." << m_octets[1] << "."
			<< m_octets[2] << "." << m_octets[3] << std::endl;
	}
};

int main() {
	std::string line;
	while (std::getline(std::cin, line))
	{
		if (line.empty()) 
		{
			continue;
		}

		std::stringstream ss(line);
		std::string ipString;
		int range;

		ss >> ipString;

		try
		{
			IpAddress ip(ipString);
			if (ss >> range) {
				ip.printSubnet(range);
			}
			else 
			{
				ip.print();
			}
		}
		catch (const IpException& e) 
		{
			std::cout << e.what() << std::endl;
		}
	}
	return EXIT_SUCCESS;
}