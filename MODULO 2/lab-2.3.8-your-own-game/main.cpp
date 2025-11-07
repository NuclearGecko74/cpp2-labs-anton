#include <iostream>
#include <string>
#include <vector>
#include <random>
#include <algorithm>
#include <limits>
#include <chrono>

enum class Suit {
	HEARTS,
	DIAMONDS,
	CLUBS,
	SPADES
};

enum class Rank {
	ACE = 1,
	TWO,
	THREE,
	FOUR,
	FIVE,
	SIX,
	SEVEN,
	EIGHT,
	NINE,
	TEN,
	JACK,
	QUEEN,
	KING
};

class Card {
private:
	Suit m_suit;
	Rank m_rank;

public:
	Card(Suit suit, Rank rank) : m_suit(suit), m_rank(rank) {}

	int getValue() const 
	{
		if (m_rank >= Rank::TEN) 
		{
			return 10;
		}
		if (m_rank == Rank::ACE)
		{
			return 11;
		}
		return static_cast<int>(m_rank);
	}

	void printCard() const
	{
		std::string rankStr;
		switch (m_rank) {
		case Rank::ACE:   rankStr = "A"; break;
		case Rank::JACK:  rankStr = "J"; break;
		case Rank::QUEEN: rankStr = "Q"; break;
		case Rank::KING:  rankStr = "K"; break;
		default:          rankStr = std::to_string(static_cast<int>(m_rank)); break;
		}

		std::string suitStr;
		switch (m_suit) 
		{
		case Suit::HEARTS:   suitStr = "\u2665"; break;
		case Suit::DIAMONDS: suitStr = "\u2666"; break;
		case Suit::CLUBS:    suitStr = "\u2663"; break;
		case Suit::SPADES:   suitStr = "\u2660"; break;
		}
		std::cout << "[" << rankStr << suitStr << "]";
	}
};

class Hand {
protected:
	std::vector<Card> m_cards;

public:
	virtual ~Hand() {}

	void addCard(const Card& card) 
	{
		m_cards.push_back(card);
	}

	void clear() 
	{
		m_cards.clear();
	}

	int calculateTotal() const 
	{
		int total = 0;
		int aceCount = 0;
		for (const auto& card : m_cards) 
		{
			int value = card.getValue();
			if (value == 11) 
			{
				aceCount++;
			}
			total += value;
		}

		while (total > 21 && aceCount > 0) 
		{
			total -= 10;
			aceCount--;
		}
		return total;
	}

	virtual void print() const = 0;
};

class PlayerHand : public Hand {
public:
	void print() const override 
	{
		for (const auto& card : m_cards)
		{
			card.printCard();
			std::cout << " ";
		}
		std::cout << " Total: " << calculateTotal() << std::endl;
	}
};

class DealerHand : public Hand {
public:
	void print(bool showFirstCard) const
	{
		if (showFirstCard) 
		{
			for (const auto& card : m_cards) 
			{
				card.printCard();
				std::cout << " ";
			}
			std::cout << " Total: " << calculateTotal() << std::endl;
		}
		else 
		{
			if (!m_cards.empty()) 
			{
				std::cout << "[?]";
				for (size_t i = 1; i < m_cards.size(); ++i) 
				{
					std::cout << " ";
					m_cards[i].printCard();
				}
				std::cout << "  Total: ?" << std::endl;
			}
		}
	}

	void print() const override 
	{
		print(true);
	}
};

class Deck {
private:
	std::vector<Card> m_cards;
	size_t m_currentCardIndex;

public:
	Deck() : m_currentCardIndex(0) 
	{
		for (int s = 0; s < 4; ++s) 
		{
			for (int r = 1; r <= 13; ++r)
			{
				m_cards.emplace_back(
					static_cast<Suit>(s), static_cast<Rank>(r)
				);
			}
		}
	}

	void shuffle() 
	{
		unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
		std::shuffle(m_cards.begin(), m_cards.end(), std::default_random_engine(seed));
		m_currentCardIndex = 0;
	}

	Card dealCard() 
	{
		if (m_currentCardIndex >= m_cards.size())
		{
			shuffle();
		}
		return m_cards[m_currentCardIndex++];
	}
};

class BlackjackGame {
private:
	Deck m_deck;
	PlayerHand m_player;
	DealerHand m_dealer;

	void printHands(bool showDealerCard)
	{
		std::cout << "\n-------------------------\n";
		std::cout << "DEALER'S HAND:\n";
		m_dealer.print(showDealerCard);
		std::cout << "\nPLAYER'S HAND:\n";
		m_player.print();
		std::cout << "-------------------------\n";
	}

	bool playerTurn() 
	{
		while (true) 
		{
			int playerTotal = m_player.calculateTotal();
			if (playerTotal > 21) 
			{
				std::cout << "Bust! You lose." << std::endl;
				return false;
			}
			if (playerTotal == 21) 
			{
				std::cout << "Blackjack!" << std::endl;
				return true;
			}

			char choice = ' ';
			while (choice != 'h' && choice != 's')
			{
				std::cout << "Hit (h) or Stand (s)? ";
				std::cin >> choice;
				if (std::cin.fail() || (choice != 'h' && choice != 's'))
				{
					std::cin.clear();
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					std::cout << "Invalid input. Please enter 'h' or 's'." << std::endl;
				}
			}
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

			if (choice == 's') 
			{
				return true;
			}

			m_player.addCard(m_deck.dealCard());
			printHands(false);
		}
	}

	void dealerTurn()
	{
		std::cout << "\nDEALER'S TURN:\n";
		printHands(true);

		while (m_dealer.calculateTotal() < 17) 
		{
			std::cout << "Dealer hits." << std::endl;
			m_dealer.addCard(m_deck.dealCard());
			printHands(true);
		}

		if (m_dealer.calculateTotal() > 21) 
		{
			std::cout << "Dealer busts!" << std::endl;
		}
		else 
		{
			std::cout << "Dealer stands." << std::endl;
		}
	}

	void checkWinner() 
	{
		int playerTotal = m_player.calculateTotal();
		int dealerTotal = m_dealer.calculateTotal();

		std::cout << "\n--- FINAL RESULTS ---\n";
		std::cout << "Dealer: " << dealerTotal << "\n";
		std::cout << "Player: " << playerTotal << "\n";

		if (playerTotal > 21)
		{
			std::cout << "You busted. Dealer wins." << std::endl;
		}
		else if (dealerTotal > 21) 
		{
			std::cout << "Dealer busted. You win!" << std::endl;
		}
		else if (playerTotal > dealerTotal) 
		{
			std::cout << "You win!" << std::endl;
		}
		else if (dealerTotal > playerTotal)
		{
			std::cout << "Dealer wins." << std::endl;
		}
		else 
		{
			std::cout << "It's a push (tie)." << std::endl;
		}
	}

	bool askPlayAgain()
	{
		char choice = ' ';
		while (choice != 'y' && choice != 'n') 
		{
			std::cout << "\nPlay again (y/n)? ";
			std::cin >> choice;
			if (std::cin.fail() || (choice != 'y' && choice != 'n')) 
			{
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				std::cout << "Invalid input. Please enter 'y' or 'n'." << std::endl;
			}
		}
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		return choice == 'y';
	}

public:
	void play() {
		do {
			m_deck.shuffle();
			m_player.clear();
			m_dealer.clear();

			std::cout << "\n--- NEW GAME: BLACKJACK ---" << std::endl;

			m_player.addCard(m_deck.dealCard());
			m_dealer.addCard(m_deck.dealCard());
			m_player.addCard(m_deck.dealCard());
			m_dealer.addCard(m_deck.dealCard());

			printHands(false);

			bool playerStands = playerTurn();

			if (playerStands) {
				dealerTurn();
				checkWinner();
			}

		} while (askPlayAgain());

		std::cout << "Thanks for playing!" << std::endl;
	}
};

int main() {
	BlackjackGame game;
	game.play();
	return 0;
}