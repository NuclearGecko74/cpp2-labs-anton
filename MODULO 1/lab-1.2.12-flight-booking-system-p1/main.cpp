#include <iostream>

#include "FlightBooking.h"

int main()
{
	int reserved = 0;
	int	capacity = 0;

	std::cout << "Provide flight capacity: ";
	std::cin >> capacity;

	std::cout << "Provide number of reserved seats: ";
	std::cin >> reserved;

	FlightBooking booking(1, capacity, reserved);

	booking.printStatus();
}