#pragma once

#include <memory>
#include <stack>

#include "States/State.h"

using StateRef = std::unique_ptr<State>;

class StateManager
{
public:
	StateManager();
	~StateManager();

	void AddState(StateRef newState, bool isReplacing = true);
	void PopState();
	void ProcessStateChanges();

	StateRef& GetActiveState();

private:
	std::stack<StateRef> m_states;
	StateRef m_newState;

	bool m_isRemoving;
	bool m_isAdding;
	bool m_isReplacing;
};

