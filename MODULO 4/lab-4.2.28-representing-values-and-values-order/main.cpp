#include <iostream>
#include <vector>


enum class State
{
	Start = 1,
	ForwardLow,
	ForwardHigh,
	DeepLow,
	DeepHigh,
	Stop
};

class FiniteStateMachine
{
public:
	FiniteStateMachine()
	{
		m_currentState = State::Start;
		m_history.push_back(State::Start);
	}

	State getCurrentState() const { return m_currentState; }

private:
	State m_currentState;
	std::vector<State> m_history;

	void printSummary() const
	{
		std::cout << "States visited:\n";
		for (size_t i = 0; i < m_history.size(); ++i)
		{
			int val = static_cast<int>(m_history[i]);
			std::cout << val;

			if (m_history[i] == State::Start) std::cout << "(Start)";
			else if (m_history[i] == State::Stop) std::cout << "(Stop)";

			if (i < m_history.size() - 1) std::cout << ", ";
		}
		std::cout << '\n';
	}

	friend FiniteStateMachine& operator<<(FiniteStateMachine& fsm, int value);
};

FiniteStateMachine& operator<<(FiniteStateMachine& fsm, int value)
{
	if (fsm.m_currentState == State::Stop) return fsm;

	State nextState = State::Stop;

	switch (fsm.m_currentState)
	{
	case State::Start:
		if (value < 5) nextState = State::ForwardHigh;
		else nextState = State::ForwardLow;
		break;

	case State::ForwardHigh:
		if (value >= 5) nextState = State::DeepLow;
		else nextState = State::DeepHigh;
		break;

	case State::ForwardLow:
		if (value < 5) nextState = State::DeepLow;
		else nextState = State::DeepHigh;
		break;

	case State::DeepLow:
	case State::DeepHigh:
		nextState = State::Stop;
		break;

	default:
		break;
	}

	fsm.m_currentState = nextState;
	fsm.m_history.push_back(nextState);

	if (nextState == State::Stop)
	{
		std::cout << "Stop state reached\n";
		fsm.printSummary();
	}

	return fsm;
}

int main()
{
	FiniteStateMachine fsm;

	fsm << 3;
	fsm << 6;
	fsm << 4;

	return 0;
}