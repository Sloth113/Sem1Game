#pragma once
#include "GameState.h"

class MenuState : public GameState
{
public:
	MenuState(aie::Font * font, GameStateManager * manager)
	{
		m_fontType = font;
		m_pulseTimer = 0;
		m_manager = manager;
		m_sel = 1;
	}
protected:
	virtual void onUpdate(float deltaTime) 
	{
		aie::Input* input = aie::Input::getInstance();
		m_pulseTimer += deltaTime;
		//Toggle selected
		if(input->wasKeyPressed(aie::INPUT_KEY_DOWN) || input->wasKeyPressed(aie::INPUT_KEY_UP))
		{
			m_sel = -m_sel;
		}

		if((input->wasKeyPressed(aie::INPUT_KEY_SPACE) || input->wasMouseButtonPressed(aie::INPUT_MOUSE_BUTTON_LEFT)) && m_sel == 1)
		{
			//GO TO PLAY STATE
			//p_manager->popState();
			m_manager->pushState((int)eGameState::INGAME);
			m_manager->popState();
			
		}
		else if ((input->wasKeyPressed(aie::INPUT_KEY_SPACE) || input->wasMouseButtonPressed(aie::INPUT_MOUSE_BUTTON_LEFT)) && m_sel == -1){
			//GO TO LEVEL STATE
			m_manager->pushState((int)eGameState::SCORES);
			m_manager->popState();
		}
		else if (input->wasKeyPressed(aie::INPUT_KEY_ESCAPE)) {
			m_manager->popState();//QUIT 
		}
		//Alllow for mouse selection of play and scores
		if (input->getMouseX() > 0 && input->getMouseX() < 150 && input->getMouseY() < SCREEN_HEIGHT - 200 && input->getMouseY() > SCREEN_HEIGHT - 230)
		{
			//Play
			m_sel = 1;
		}
		if (input->getMouseX() > 0 && input->getMouseX() < 150 && input->getMouseY() < SCREEN_HEIGHT - 260 && input->getMouseY() > SCREEN_HEIGHT - 290)
		{
			//scores
			m_sel = -1;
		}		
	}
	virtual void onDraw(aie::Renderer2D * renderer) 
	{
		renderer->drawText(m_fontType, "Click things game", 0, SCREEN_HEIGHT - 40, 0);
		renderer->drawText(m_fontType, "Use your mouse to click (drag over) the shapes to earn points", 0, 20, 0);
		renderer->drawText(m_fontType, "PLAY", 0, SCREEN_HEIGHT - 200, 0);
		renderer->drawText(m_fontType, "SCORES", 0, SCREEN_HEIGHT - 270, 0);
		if(m_sel == 1)
		renderer->drawCircle(150, SCREEN_HEIGHT - 190, 10, 0);
		else
		renderer->drawCircle(150, SCREEN_HEIGHT - 260, 10, 0);
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