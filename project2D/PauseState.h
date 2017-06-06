#pragma once
#include "GameState.h"

class PauseState : public GameState
{
public:
	PauseState(aie::Font * font, GameStateManager * manager)
	{
		m_fontType = font;
		m_timer = 0;
		p_manager = manager;
	}
protected:
	virtual void onUpdate(float deltaTime)
	{
		aie::Input* input = aie::Input::getInstance();
		if (input->wasKeyPressed(aie::INPUT_KEY_ESCAPE))
		{
			//quit
			m_toMenu = true;
			p_manager->popState();
		}
		if (input->wasKeyPressed(aie::INPUT_KEY_SPACE))
		{
			//quit
			m_toMenu = false;
			p_manager->popState();
		}
	}
	virtual void onDraw(aie::Renderer2D * renderer)
	{
		renderer->drawText(m_fontType, "Paused.... esc to menu, space to game ", SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, 0);
	}

	void onExit()
	{
		if(m_toMenu)
		{
			p_manager->popState();
		}
	}


private:
	bool m_toMenu = false;
	aie::Font * m_fontType;
	float m_timer;
};