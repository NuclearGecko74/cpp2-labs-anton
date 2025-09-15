#include <iostream>
#include <string>

#include <array>

#include "FlightBooking.h"

int main()
{
	std::array<FlightBooking, 10> bookings;
	int numFlights = 0;

	while (true)
	{
		if (numFlights == 0)
		{
			std::cout << "No flights in the system\n";
		}

		std::cout << "What would you like to do?: ";
		std::string command;
		std::cin >> command;

		int id;
		int value;
		bool found = false;
		int index = -1;

		if (command == "create")
		{
			std::cin >> id >> value;
			if (numFlights >= 10)
			{
				std::cout << "Cannot perform this operation! Max flights reached.\n";
				continue;
			}
			if (id <= 0)
			{
				std::cout << "Cannot perform this operation! Invalid ID.\n";
				continue;
			}
			for (int i = 0; i < numFlights; ++i)
			{
				if (bookings[i].getId() == id)
				{
					found = true;
					break;
				}
			}
			if (found)
			{
				std::cout << "Cannot perform this operation! Flight with this ID already exists.\n";
			}
			else
			{
				bookings[numFlights] = FlightBooking(id, value, 0);
				bookings[numFlights].printStatus();
				numFlights++;
			}
		}
		else if (command == "add")
		{
			std::cin >> id >> value;
			if (id <= 0)
			{
				std::cout << "Cannot perform this operation! Invalid ID.\n";
				continue;
			}
			for (int i = 0; i < numFlights; ++i)
			{
				if (bookings[i].getId() == id)
				{
					index = i;
					found = true;
					break;
				}
			}
			if (found)
			{
				bookings[index].reserveSeats(value);
				bookings[index].printStatus();
			}
			else
			{
				std::cout << "Cannot perform this operation! Flight not found.\n";
			}
		}
		else if (command == "cancel")
		{
			std::cin >> id >> value;
			if (id <= 0)
			{
				std::cout << "Cannot perform this operation! Invalid ID.\n";
				continue;
			}
			for (int i = 0; i < numFlights; ++i)
			{
				if (bookings[i].getId() == id)
				{
					index = i;
					found = true;
					break;
				}
			}
			if (found)
			{
				bookings[index].cancelReservations(value);
				bookings[index].printStatus();
			}
			else
			{
				std::cout << "Cannot perform this operation! Flight not found.\n";
			}
		}
		else if (command == "delete")
		{
			std::cin >> id;
			if (id <= 0)
			{
				std::cout << "Cannot perform this operation! Invalid ID.\n";
				continue;
			}
			for (int i = 0; i < numFlights; ++i)
			{
				if (bookings[i].getId() == id)
				{
					index = i;
					found = true;
					break;
				}
			}
			if (found)
			{
				for (int i = index; i < numFlights - 1; ++i)
				{
					bookings[i] = bookings[i + 1];
				}
				numFlights--;
				std::cout << "Flight " << id << " deleted successfully.\n";
			}
			else
			{
				std::cout << "Cannot perform this operation! Flight not found.\n";
			}
		}
		else if (command == "quit")
		{
			break;
		}
		else
		{
			std::cout << "Invalid command.\n";
		}
	}
	return EXIT_SUCCESS;
}