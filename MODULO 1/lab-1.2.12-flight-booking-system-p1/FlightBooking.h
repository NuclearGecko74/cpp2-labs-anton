#pragma once

class FlightBooking
{
private:
	int id;
	int capacity;
	int reserved;

public:
	FlightBooking(int id, int capacity, int reserved);

	void printStatus();
};

