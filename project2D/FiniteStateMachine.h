#pragma once
//#include "GameObject.h"
#include <vector>
class GameObject;
class Condition
{
public:
	virtual ~Condition(){}
	virtual bool test(GameObject * go) const = 0;
};
class State;
class Transition final
{
public:
	Transition(Condition * condition, State * target)
	{
		m_condition = condition;
		m_state = target;
	}
	~Transition()
	{
		delete m_condition;
	}

	bool isConditionMet(GameObject * gameObject) const
	{
		return m_condition->test(gameObject);
	}

	State* getTargetState() const { return m_state; }
private:
	State * m_state;
	Condition * m_condition;
};

class State
{
public:
	virtual ~State()
	{
		for (auto t : m_transitions)
			delete t;
	}
	virtual void onEnter(GameObject * object) {}
	virtual void onExit(GameObject * object) {}

	virtual void onUpdate(GameObject* object, float deltaTime) = 0;

	void addTransition(Transition* transition)
	{
		m_transitions.push_back(transition);
	}
	State* getNextState(GameObject * gameObject)
	{
		for(auto transition : m_transitions)
		{
			if (transition->isConditionMet(gameObject))
				return transition->getTargetState();
		}
		return nullptr;
	}

private:
	std::vector<Transition*> m_transitions;
};



class FiniteStateMachine
{
public:

	FiniteStateMachine(int stateCount)
	{
		m_states.resize(stateCount);
	}

	virtual ~FiniteStateMachine()
	{
		for (auto state : m_states)
			delete state;
	}
	void addState(int id, State * newState)
	{
		m_states[id] = newState;
	}
	void forceState(int id, GameObject * gameObject)
	{
		m_currentState->onExit(gameObject);
		m_currentState = m_states[id];
		m_currentState->onEnter(gameObject);
	}
	void forceState(int id)
	{
		m_currentState = m_states[id];
	}
	void update(GameObject * gameObject, float deltaTime)
	{
		if (m_currentState != nullptr)
		{
			m_currentState->onUpdate(gameObject, deltaTime);
			State* next = m_currentState->getNextState(gameObject);
			if(next != m_currentState && next != nullptr)
			{
				m_currentState->onExit(gameObject);
				m_currentState = next;
				m_currentState->onEnter(gameObject);
			}
		}
	}
private:
	State* m_currentState = nullptr;
	std::vector<State *> m_states;
};