#include "FlightBooking.h"

#include <iostream>

FlightBooking::FlightBooking(int id, int capacity, int reserved)
{
	this->id = id;
	this->capacity = (capacity > 0) ? capacity : 0;
	this->reserved = (reserved > 0) ? reserved : 0;
}

void FlightBooking::printStatus()
{
	std::cout << "Flight " << id << " : "; 
	std::cout << reserved << '/' << capacity;
	std::cout << " (" << static_cast<int>((reserved / static_cast<float>(capacity)) * 100); 
	std::cout << "%) seats reserved\n";
}
