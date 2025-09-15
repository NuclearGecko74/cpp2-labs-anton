#include <iostream>
#include <string>
#include <array>
#include "GymMembership.h"

void displayHelp()
{
	std::cout << "\n--- Command List ---\n";
	std::cout << "  create [id] [name]   - Create a new member with ID and name.\n";
	std::cout << "  extend [id] [months] - Extend a member's subscription by a number of months.\n";
	std::cout << "  cancel [id]          - Cancel a member's subscription (sets months to 0).\n";
	std::cout << "  delete [id]          - Delete a member from the system.\n";
	std::cout << "  quit                 - Exit the program.\n";
	std::cout << "  help                 - Show this help message.\n";
	std::cout << "----------------------\n";
}

int main()
{
	std::array<GymMembership, 10> members;
	int numMembers = 0;

	std::cout << "Welcome to the Gym Membership Management System!\n";
	displayHelp();

	while (true)
	{
		if (numMembers == 0)
		{
			std::cout << "\nNo members in the system.\n";
		}
		else
		{
			std::cout << "\nCurrent members:\n";
			for (int i = 0; i < numMembers; ++i)
			{
				members[i].printStatus();
			}
		}

		std::cout << "\nEnter a command: ";
		std::string command;
		std::cin >> command;

		int id;
		bool found = false;
		int index = -1;

		auto findMemberIndex = [&](int memberId) -> int {
			for (int i = 0; i < numMembers; ++i) {
				if (members[i].getId() == memberId) {
					return i;
				}
			}
			return -1;
			};

		if (command == "create")
		{
			std::string name;
			std::cin >> id;
			std::getline(std::cin, name);
			if (!name.empty() && name[0] == ' ')
			{
				name.erase(0, 1);
			}

			if (id <= 0)
			{
				std::cout << "Error: Invalid ID. The ID must be a positive number.\n";
			}
			else if (findMemberIndex(id) != -1)
			{
				std::cout << "Error: A member with ID " << id << " already exists.\n";
			}
			else if (numMembers >= 10)
			{
				std::cout << "Error: The system is full. Max 10 members allowed.\n";
			}
			else
			{
				members[numMembers] = GymMembership(id, name);
				std::cout << "Success! Member created: ";
				members[numMembers].printStatus();
				numMembers++;
			}
		}
		else if (command == "extend")
		{
			int months;
			std::cin >> id >> months;
			index = findMemberIndex(id);

			if (index == -1)
			{
				std::cout << "Error: Member with ID " << id << " not found.\n";
			}
			else
			{
				members[index].extendSubscription(months);
				std::cout << "Subscription updated for member " << id << ": ";
				members[index].printStatus();
			}
		}
		else if (command == "cancel")
		{
			std::cin >> id;
			index = findMemberIndex(id);

			if (index == -1)
			{
				std::cout << "Error: Member with ID " << id << " not found.\n";
			}
			else
			{
				members[index].cancelSubscription();
				std::cout << "Subscription canceled for member " << id << ": ";
				members[index].printStatus();
			}
		}
		else if (command == "delete")
		{
			std::cin >> id;
			index = findMemberIndex(id);

			if (index == -1)
			{
				std::cout << "Error: Member with ID " << id << " not found.\n";
			}
			else
			{
				for (int i = index; i < numMembers - 1; ++i)
				{
					members[i] = members[i + 1];
				}
				numMembers--;
				std::cout << "Member " << id << " has been deleted.\n";
			}
		}
		else if (command == "quit")
		{
			std::cout << "Exiting the program. Goodbye!\n";
			break;
		}
		else if (command == "help")
		{
			displayHelp();
		}
		else
		{
			std::cout << "Invalid command. Type 'help' to see the list of commands.\n";
		}
	}
	return EXIT_SUCCESS;
}