#include "FlightBooking.h"

#include <iostream>

FlightBooking::FlightBooking(int id, int capacity, int reserved)
{
	this->id = id;
	this->capacity = (capacity > 0) ? capacity : 0;
	
	if (reserved < 0)
	{
		this->reserved = 0;
	}
	else if (reserved > static_cast<int>(1.05 * capacity))
	{
		this->reserved = static_cast<int>(1.05 * capacity);
	}
	else
	{
		this->reserved = (reserved > 0) ? reserved : 0;
	}
	
}

void FlightBooking::printStatus()
{
	std::cout << "Flight " << id << " : ";
	std::cout << reserved << '/' << capacity;
	std::cout << " (" << static_cast<int>((reserved / static_cast<float>(capacity)) * 100);
	std::cout << "%) seats reserved\n";
}

bool FlightBooking::reserveSeats(int numberOfSeats)
{
	int reserved{ this->reserved + numberOfSeats };
	if (reserved > static_cast<int>(1.05 * capacity) || numberOfSeats <= 0)
	{
		std::cout << "Cannot perform this operation!";
		return false;
	}
	this->reserved = reserved;
	return true;
}

bool FlightBooking::cancelReservations(int numberOfSeats)
{
	int reserved{ this->reserved - numberOfSeats };
	if (reserved < 0 || numberOfSeats <= 0)
	{
		std::cout << "Cannot perform this operation!\n";
		return false;
	}
	this->reserved = reserved;
	return true;
}
