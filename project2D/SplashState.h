#pragma once
#include "GameState.h"

class SplashState : public GameState
{
public:
	SplashState(aie::Font * font, GameStateManager * manager)
	{
		m_fontType = font;
		m_timer = 0;
		m_manager = manager;
		m_splashText = ResourceManager::getInstance().get("./textures/splash.png", ResourceManager::TEXTURE)->as<aie::Texture>();
	}
protected:
	virtual void onUpdate(float deltaTime)
	{
		//Timer or space pressed
		aie::Input* input = aie::Input::getInstance();
		m_timer += deltaTime;
		if (m_timer >= SPLASH_TIME || input->wasKeyPressed(aie::INPUT_KEY_SPACE) || input->wasMouseButtonPressed(aie::INPUT_MOUSE_BUTTON_LEFT))
		{
			m_manager->pushState((int)eGameState::MENU);
			m_manager->popState();
		}

	}
	virtual void onDraw(aie::Renderer2D * renderer)
	{
		renderer->drawSprite(m_splashText, SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2);
		renderer->drawText(m_fontType, "Game Project", SCREEN_WIDTH / 2 - 120, SCREEN_HEIGHT - 50, 0);
		renderer->drawText(m_fontType, "Made by Scott Hart", 5, 10);
	}

private:
	aie::Texture * m_splashText;
	aie::Font * m_fontType;
	float m_timer;
};