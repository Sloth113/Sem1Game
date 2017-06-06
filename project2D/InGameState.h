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

	void setLevel(int level)
	{
		m_level = level;
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
		switch (m_level)
		{
		case 0:
			renderer->drawText(m_fontType, "PLAYING THE GAME NEW", SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, 0);
			break;
		case 1:
			renderer->drawText(m_fontType, "PLAYING THE GAME  1", SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, 0);
			break;
		case 2:
			renderer->drawText(m_fontType, "PLAYING THE GAME  2", SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, 0);
			break;
		case 3: 
			renderer->drawText(m_fontType, "PLAYING THE GAME  3", SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, 0);
			break;
		default:
			renderer->drawText(m_fontType, "PLAYING BUT SETTING SOMETHING THAT SHOULDNT BE SET", SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, 0);
			break;
		}
	}

private:
	int m_level = 0;
	aie::Font * m_fontType;
	float m_timer;
};