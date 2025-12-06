#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>

enum WeekDay { Thursday = 0, Friday, Saturday, Sunday, Monday, Tuesday, Wednesday };

class Calendar {
public:
	Calendar(int d, int m, int y) : day(d), month(m), year(y)
	{
		if (y < 1970) 
		{
			throw std::invalid_argument("Date cannot be earlier than 1970.");
		}
	}

	bool isLeap(int y) const
	{
		return (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0);
	}

	int getDaysInMonth(int m, int y) const
	{
		if (m == 2) return isLeap(y) ? 29 : 28;
		if (m == 4 || m == 6 || m == 9 || m == 11) return 30;
		return 31;
	}

	void print()
	{
		long totalDays = 0;
		for (int y = 1970; y < year; ++y) 
		{
			totalDays += isLeap(y) ? 366 : 365;
		}

		for (int m = 1; m < month; ++m) 
		{
			totalDays += getDaysInMonth(m, year);
		}

		totalDays += (day - 1);

		int dayOfWeekIndex = totalDays % 7;

		const std::vector<std::string> weekDays = {
			"Thursday", "Friday", "Saturday", "Sunday", "Monday", "Tuesday", "Wednesday"
		};
		const std::vector<std::string> months = {
			"", "January", "February", "March", "April", "May", "June",
			"July", "August", "September", "October", "November", "December"
		};

		std::cout << day << " " << months[month] << " " << year << " - "
			<< weekDays[dayOfWeekIndex] << " - "
			<< totalDays << " days since 1st January 1970" << std::endl;
	}

private:
	int day, month, year;
};

int main()
{
	try
	{
		int d, m, y;
		std::cin >> d >> m >> y;

		Calendar date(d, m, y);
		date.print();
	}
	catch (const std::exception& e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}

	return 0;
}