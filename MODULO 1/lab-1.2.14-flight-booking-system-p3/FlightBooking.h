#pragma once

class FlightBooking
{
private:
	int id;
	int capacity;
	int reserved;

public:
	FlightBooking() { id = 0; capacity = 0; reserved = 0; }
	FlightBooking(int id, int capacity, int reserved);

	void printStatus();

	bool reserveSeats(int numberOfSeats);
	bool cancelReservations(int numberOfSeats);

	// getters
	inline int getId() const { return id; }
};


