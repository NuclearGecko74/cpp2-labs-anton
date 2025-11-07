#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <stdexcept>

class IPAddress {
protected:
	std::string ip_value;

public:
	IPAddress() = default;

	IPAddress(const std::string& ip) : ip_value(ip) {}

	IPAddress(const IPAddress& other) : ip_value(other.ip_value) {}

	virtual ~IPAddress() {}

	virtual void print() const 
	{
		std::cout << ip_value;
	}
};

class IPAddressChecked : public IPAddress {
private:
	bool is_correct;

	bool validate_ip(const std::string& ip)
	{
		std::stringstream ss(ip);
		std::string segment;
		std::vector<std::string> segments;
		while (std::getline(ss, segment, '.'))
		{
			segments.push_back(segment);
		}

		if (segments.size() != 4) {
			return false;
		}

		for (const std::string& s : segments) 
		{
			if (s.empty()) 
			{
				return false;
			}

			try 
			{
				size_t chars_processed = 0;
				int value = std::stoi(s, &chars_processed);

				if (chars_processed != s.length()) 
				{
					return false;
				}

				if (value < 0 || value > 255) 
				{
					return false;
				}
			}
			catch (const std::exception&) 
			{
				return false;
			}
		}
		return true;
	}

public:
	IPAddressChecked(const std::string& ip)
		: IPAddress(ip) 
	{
		is_correct = validate_ip(ip);
	}

	IPAddressChecked(const IPAddressChecked& other)
		: IPAddress(other), is_correct(other.is_correct) 
	{
	}

	void print() const override
	{
		IPAddress::print();

		if (is_correct)
		{
			std::cout << " - Correct";
		}
		else
		{
			std::cout << " - Not Correct";
		}
	}
};

int main() {
	std::string ip1_str, ip2_str, ip3_str;

	std::cin >> ip1_str;
	std::cin >> ip2_str;
	std::cin >> ip3_str;

	IPAddress ip1(ip1_str);
	IPAddressChecked ip2(ip2_str);
	IPAddressChecked ip3(ip3_str);

	ip1.print();
	std::cout << std::endl;

	ip2.print();
	std::cout << std::endl;

	ip3.print();
	std::cout << std::endl;

	return 0;
}