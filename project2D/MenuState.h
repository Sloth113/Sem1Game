#pragma once
#include "GameState.h"

class MenuState : public GameState
{
public:
	MenuState(aie::Font * font, GameStateManager * manager)
	{
		m_fontType = font;
		m_pulseTimer = 0;
		p_manager = manager;
		m_sel = 1;
	}
protected:
	virtual void onUpdate(float deltaTime) 
	{
		aie::Input* input = aie::Input::getInstance();
		m_pulseTimer += deltaTime;

		if(input->wasKeyPressed(aie::INPUT_KEY_DOWN) || input->wasKeyPressed(aie::INPUT_KEY_UP))
		{
			m_sel = -m_sel;
		}

		if(input->wasKeyPressed(aie::INPUT_KEY_SPACE) && m_sel == 1)
		{
			//GO TO PLAY STATE
			//p_manager->popState();
			p_manager->pushState((int)eGameState::INGAME);
			
		}
		else if (input->wasKeyPressed(aie::INPUT_KEY_SPACE) && m_sel == -1){
			//GO TO LEVEL STATE
			p_manager->pushState((int)eGameState::LEVELSEL);
			//p_manager->popState();
		}
		else if (input->wasKeyPressed(aie::INPUT_KEY_ESCAPE)) {
			p_manager->popState();//QUIT 
		}

		
	}
	virtual void onDraw(aie::Renderer2D * renderer) 
	{
		renderer->drawText(m_fontType, "MENU", 0, SCREEN_HEIGHT - 40, 0);
		renderer->drawText(m_fontType, "PLAY", 0, SCREEN_HEIGHT - 200, 0);
		renderer->drawText(m_fontType, "LEVEL SELECT", 0, SCREEN_HEIGHT - 260, 0);
		if(m_sel == 1)
		renderer->drawCircle(100, SCREEN_HEIGHT - 190, 10, 0);
		else
		renderer->drawCircle(250, SCREEN_HEIGHT - 250, 10, 0);
	}
	virtual void onEnter()
	{
		m_active = true;
	}
	virtual void onExit()
	{
		m_active = false;
	}

private:
	aie::Font * m_fontType;
	float m_pulseTimer;
	int m_sel;
};