#pragma once
#include <vector>
#include "GameState.h"
//Manages game states
class GameStateManager
{
public:
	GameStateManager() :GameStateManager(0) {}
	GameStateManager(unsigned int stateCount)
	{
		m_registeredStates.resize(stateCount);
	}
	~GameStateManager()
	{
		for (auto state : m_registeredStates)
			delete state;
	}
	//Add state that can be used
	void registerState(int id, GameState * state)
	{
		m_registeredStates[id] = state;
	}
	//Push onto pushedstats stack (allows for going into menus or sub menus of menus)
	void pushState(int id)
	{
		m_pushedStates.push_back(m_registeredStates[id]);
	}
	void popState()
	{
		m_popState = true;
	}
	//Logic
	void update(float deltaTime)
	{
		//Pop state, check to see if needing to pop current state. 
		while (m_popState)
		{
			m_popState = false;

			m_stateStack.back()->exit();
			auto tmp = m_stateStack.back();
			m_stateStack.pop_back();
			tmp->onPopped();

			if (m_stateStack.empty() == false)
				m_stateStack.back()->enter();
		}
		//Push new states
		for (auto pushedState : m_pushedStates)
		{
			if (m_stateStack.empty() == false)
				m_stateStack.back()->exit();

			pushedState->onPushed();
			m_stateStack.push_back(pushedState);
			m_stateStack.back()->enter();
		}
		m_pushedStates.clear();
		//Update state
		for (auto state : m_stateStack)
		{
			if (state->isActive())
				state->onUpdate(deltaTime);
		}
	}

	void draw(aie::Renderer2D * renderer)
	{
		//Draw state
		for (auto state : m_stateStack)
		{
			state->onDraw(renderer);
		}
	}

	int activeStateCount() const
	{
		return m_stateStack.size();
	}
	GameState* getTopState() const
	{
		return m_stateStack.back();
	}
	GameState* getState(int id) const
	{
		return m_registeredStates[id];
	}

private:
	std::vector<GameState*> m_pushedStates;
	bool m_popState = false;

	std::vector<GameState*> m_stateStack;
	std::vector<GameState*> m_registeredStates;
};