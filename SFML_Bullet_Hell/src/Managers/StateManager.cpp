#include "stdafx.h"
#include "StateManager.h"

StateManager::StateManager()
	: m_isRemoving(false), m_isAdding(false), m_isReplacing(false)
{
}

StateManager::~StateManager()
{
}

void StateManager::AddState(StateRef newState, bool isReplacing)
{
	m_isAdding = true;
	m_isReplacing = isReplacing;
	m_newState = std::move( newState );
}

void StateManager::PopState()
{
	m_isRemoving = true;
}

void StateManager::ProcessStateChanges()
{
	if ( m_isRemoving && !m_states.empty() )
	{
		m_states.pop();

		if ( !m_states.empty() )
			m_states.top()->Resume();

		m_isRemoving = false;
	}

	if (m_isAdding)
	{
		if (!m_states.empty())
		{
			if (m_isReplacing)
				m_states.pop();
			else
				m_states.top()->Pause();
		}

		m_states.push( std::move(m_newState) );
		m_states.top()->Init();
		m_isAdding = false;
	}
}

StateRef& StateManager::GetActiveState()
{
	return m_states.top();
}
