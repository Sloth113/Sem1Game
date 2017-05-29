#pragma once
#include "GameState.h"

class SplashState : public GameState
{
public:
	SplashState(aie::Font * font, GameStateManager * manager)
	{
		m_fontType = font;
		m_timer = 0;
		p_manager = manager;
	}
protected:
	virtual void onUpdate(float deltaTime)
	{
		aie::Input* input = aie::Input::getInstance();
		m_timer += deltaTime;
		if (m_timer == SPLASH_TIME || input->wasKeyPressed(aie::INPUT_KEY_SPACE))
		{
			p_manager->pushState((int)eGameState::MENU);
			p_manager->popState();
		}

	}
	virtual void onDraw(aie::Renderer2D * renderer)
	{
		renderer->drawText(m_fontType, "Splash", SCREEN_WIDTH/2, SCREEN_HEIGHT/2, 0);
//		char count[32];
//		sprintf_s(count, SCREEN_WIDTH-60, "TEST: %i", m_timer);
//		renderer->drawText(m_fontType, count, 0, 720 - 32);
	}


private:
	aie::Font * m_fontType;
	float m_timer;
};