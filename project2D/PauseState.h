#pragma once
#include "GameState.h"

class PauseState : public GameState
{
public:
	PauseState(aie::Font * font, GameStateManager * manager)
	{
		m_fontType = font;
		m_timer = 0;
		m_manager = manager;
		m_pauseScreen = ResourceManager::getInstance().get("./textures/pause.png", ResourceManager::TEXTURE)->as<aie::Texture>();
	}
protected:
	virtual void onUpdate(float deltaTime)
	{
		aie::Input* input = aie::Input::getInstance();
		if (input->wasKeyPressed(aie::INPUT_KEY_0))
		{
			//quit
			m_toMenu = true;
			m_manager->popState();
		}
		if (input->wasKeyPressed(aie::INPUT_KEY_SPACE) || input->wasKeyPressed(aie::INPUT_KEY_ESCAPE) || input->wasMouseButtonPressed(aie::INPUT_MOUSE_BUTTON_LEFT))
		{
			//return to game
			m_toMenu = false;
			m_manager->popState();
		}
	}
	virtual void onDraw(aie::Renderer2D * renderer)
	{
		renderer->drawSprite(m_pauseScreen, SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2);
		renderer->drawText(m_fontType, "Paused: 0 to quit to menu, Escape, Space or Mouse to unpause ", 0, 10);
	}

	void onExit()
	{
		if (m_toMenu)
		{
			m_manager->pushState((int)eGameState::MENU);
			m_manager->popState();
		}
	}

private:
	bool m_toMenu = false;
	float m_timer;
	aie::Font * m_fontType;
	aie::Texture * m_pauseScreen;
};