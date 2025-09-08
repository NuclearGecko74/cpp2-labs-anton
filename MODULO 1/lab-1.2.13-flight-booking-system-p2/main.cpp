#include <iostream>
#include <string>

#include "FlightBooking.h"

int main()
{
	int reserved{};
	int	capacity{};

	std::cout << "Provide flight capacity: ";
	std::cin >> capacity;

	std::cout << "Provide number of reserved seats: ";
	std::cin >> reserved;

	FlightBooking booking(1, capacity, reserved);

	while (true)
	{
		std::string command{};
		booking.printStatus();

		std::cout << "What would you like to do?: ";
		std::cin >> command;

		int numberOfSeats{};
		if (command == "add")
		{
			
			std::cin >> numberOfSeats;
			booking.reserveSeats(numberOfSeats);
		}
		else if (command == "cancel")
		{
			std::cin >> numberOfSeats;
			booking.cancelReservations(numberOfSeats);
		}
		else if (command == "quit")
		{
			break;
		}
	}
	return EXIT_SUCCESS;
}