#include <iostream>
#include <string>
#include <vector>

class IpAddress {
private:
	std::string m_ipValue;

public:
	IpAddress(std::string ipValue = "") : m_ipValue(ipValue) {}

	void print() const 
	{
		std::cout << m_ipValue;
	}
};

class Network {
private:
	std::vector<IpAddress> m_addresses;

public:
	void addIpAddress(const IpAddress& ipAddress)
	{
		m_addresses.push_back(ipAddress);
	}

	void print() const
	{
		for (const IpAddress& ip : m_addresses) 
		{
			ip.print();
			std::cout << std::endl;
		}
	}
};

int main() {
	std::string ip1Str, ip2Str, ip3Str, ip4Str, ip5Str;
	std::cin >> ip1Str >> ip2Str >> ip3Str >> ip4Str >> ip5Str;

	IpAddress ip1(ip1Str);
	IpAddress ip2(ip2Str);
	IpAddress ip3(ip3Str);
	IpAddress ip4(ip4Str);
	IpAddress ip5(ip5Str);

	Network networkOne;
	networkOne.addIpAddress(ip1);
	networkOne.addIpAddress(ip2);
	networkOne.addIpAddress(ip3);

	Network networkTwo;
	networkTwo.addIpAddress(ip3);
	networkTwo.addIpAddress(ip4);
	networkTwo.addIpAddress(ip5);

	std::cout << "Network 1:" << std::endl;
	networkOne.print();
	std::cout << "Network 2:" << std::endl;
	networkTwo.print();

	return 0;
}