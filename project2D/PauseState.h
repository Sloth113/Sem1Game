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


	}
	virtual void onDraw(aie::Renderer2D * renderer)
	{
		renderer->drawText(m_fontType, "Paused.... forever ", SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, 0);
	}



private:
	aie::Font * m_fontType;
	float m_timer;
};