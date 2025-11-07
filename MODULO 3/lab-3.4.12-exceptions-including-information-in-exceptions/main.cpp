#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <exception>
#include <stdexcept>

class IpException : public std::exception {
private:
	std::string m_message;

public:
	IpException(const std::string& message) : m_message(message) {}
	const char* what() const noexcept override {
		return m_message.c_str();
	}
};

class IpHeader {
private:
	std::string m_sourceIp;
	std::string m_destinationIp;

	void validateIp(const std::string& ipString, const std::string& ipType)
	{
		std::stringstream ss(ipString);
		std::string segment;
		int octetCount = 0;

		while (std::getline(ss, segment, '.')) 
		{
			octetCount++;
			if (segment.empty()) 
			{
				throw IpException("Invalid IP Header - " + ipType + " is invalid.");
			}

			try
			{
				size_t charsProcessed = 0;
				int octet = std::stoi(segment, &charsProcessed);

				if (charsProcessed != segment.length())
				{
					throw std::invalid_argument("Invalid char");
				}
				if (octet < 0 || octet > 255)
				{
					throw std::out_of_range("Out of range");
				}
			}
			catch (const std::exception& e)
			{
				throw IpException("Invalid IP Header - " + ipType + " is invalid.");
			}
		}

		if (octetCount != 4)
		{
			throw IpException("Invalid IP Header - " + ipType + " is invalid.");
		}
	}

public:
	IpHeader(const std::string& sourceIp, const std::string& destinationIp) 
	{
		validateIp(sourceIp, "Source IP Address");
		m_sourceIp = sourceIp;

		validateIp(destinationIp, "Destination IP Address");
		m_destinationIp = destinationIp;
	}
};

int main() 
{
	std::string sourceIpString;
	std::string destinationIpString;

	while (std::cin >> sourceIpString >> destinationIpString) 
	{
		try
		{
			IpHeader header(sourceIpString, destinationIpString);
			std::cout << "Valid IP Header." << std::endl;
		}
		catch (const IpException& e) {
			std::cout << e.what() << std::endl;
		}
	}
	return EXIT_SUCCESS;
}