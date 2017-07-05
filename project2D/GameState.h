#pragma once
#include "Renderer2D.h"
#include "Input.h"
#include "defines.h"
#include "ResourceManager.h"
//Game state template for manager
class GameState
{
	friend class GameStateManager;
public:
	
	GameState() {};
	GameState(GameStateManager * manager)
	{
		m_manager = manager;
	}
	virtual ~GameState() {};
	bool isActive() const { return m_active; }

protected:

	virtual void onUpdate(float deltaTime) = 0;
	virtual void onDraw(aie::Renderer2D * renderer) = 0;

	void enter() 
	{
		m_active = true; 
		onEnter();
	}
	void exit()
	{
		m_active = false;
		onExit();
	}

	virtual void onEnter() {}
	virtual void onExit() {}
	virtual void onPushed() {}
	virtual void onPopped() {}

protected:

	GameStateManager * m_manager;
	bool m_active = true;

};