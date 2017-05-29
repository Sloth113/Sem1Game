#pragma once
#include "GameState.h"

class InGameState : public GameState
{
public:
	InGameState(aie::Font * font, GameStateManager * manager)
	{
		m_fontType = font;
		m_timer = 0;
		p_manager = manager;
	}
protected:
	virtual void onUpdate(float deltaTime)
	{
		aie::Input* input = aie::Input::getInstance();
		//GAME LOGIC
		if(input->wasKeyPressed(aie::INPUT_KEY_ESCAPE))
		{
			//Pause menu
			p_manager->pushState((int)eGameState::PAUSE);
			m_active = false;
		}

	}
	virtual void onDraw(aie::Renderer2D * renderer)
	{
		renderer->drawText(m_fontType, "PLAYING THE GAME", SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, 0);
	}


private:
	aie::Font * m_fontType;
	float m_timer;
};