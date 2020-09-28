#include "StateMachine.h"

void StateMachine::AddState(StateRef newState)
{
	_adding = true;
	_newstate = std::move(newState);
}

void StateMachine::StateChange()
{
	if (_adding)
	{
		_states.push(std::move(_newstate));
		_states.top()->Init();
		_adding = false;
	}
}

StateRef & StateMachine::ActiveState()
{
	return _states.top();
}