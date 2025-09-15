#pragma once

#include <iostream>
#include <string>

class GymMembership
{
private:
	std::string name;
	int id;
	int subscriptionMonths;

public:
	GymMembership() : id(0), name(""), subscriptionMonths(0) {}
	GymMembership(int id, const std::string& name);

	void printStatus() const;

	void extendSubscription(int months);
	void cancelSubscription();

	inline int getId() const { return id; }
};

