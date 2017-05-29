#pragma once
#include "GameState.h"

class LevelSelState : public GameState
{
public:
	LevelSelState(aie::Font * font, GameStateManager * manager)
	{
		m_fontType = font;
		p_manager = manager;
		m_sel = (int)levelSel::LEVELONE;
	}
protected:
	virtual void onUpdate(float deltaTime)
	{
		aie::Input* input = aie::Input::getInstance();
		if (input->wasKeyPressed(aie::INPUT_KEY_DOWN))
		{
			m_sel++;
			if (m_sel >= (int)levelSel::SIZE)
				m_sel = (int)levelSel::LEVELONE;
		}
		if (input->wasKeyPressed(aie::INPUT_KEY_UP))
		{
			m_sel--;
			if (m_sel < 0)
				m_sel = (int)levelSel::BACK;
		}
		if (input->wasKeyPressed(aie::INPUT_KEY_SPACE))
		{
			switch (m_sel)
			{
			case (int)levelSel::LEVELONE:
				p_manager->popState();
				p_manager->pushState((int)eGameState::INGAME);
				break;
			case (int)levelSel::LEVELTWO:
				p_manager->popState();
				p_manager->pushState((int)eGameState::INGAME);
				break;
			case (int)levelSel::LEVELTHREE:
				p_manager->popState();
				p_manager->pushState((int)eGameState::INGAME);
				break;
			case (int)levelSel::BACK:
				p_manager->popState();
				break;
			}
		}
		if (input->wasKeyPressed(aie::INPUT_KEY_ESCAPE))
		{
			p_manager->popState();
		}


	}
	virtual void onDraw(aie::Renderer2D * renderer)
	{
		renderer->drawText(m_fontType, "Level Select", 0, SCREEN_HEIGHT-30 , 0);
		renderer->drawText(m_fontType, "Level 1", 0, SCREEN_HEIGHT - 80, 0);
		renderer->drawText(m_fontType, "Level 2", 0, SCREEN_HEIGHT - 120, 0);
		renderer->drawText(m_fontType, "Level 3", 0, SCREEN_HEIGHT - 160, 0);
		renderer->drawText(m_fontType, "Back", 0, 40, 0);
		switch(m_sel)
		{
			case (int)levelSel::LEVELONE:
				renderer->drawLine(0, SCREEN_HEIGHT - 80, 100, SCREEN_HEIGHT - 80, 3, 0);
				break;
			case (int)levelSel::LEVELTWO:
				renderer->drawLine(0, SCREEN_HEIGHT - 120, 100, SCREEN_HEIGHT - 120, 3, 0);
				break;
			case (int)levelSel::LEVELTHREE:
				renderer->drawLine(0, SCREEN_HEIGHT - 160, 100, SCREEN_HEIGHT - 160, 3, 0);
				break;
			case (int)levelSel::BACK:
				renderer->drawLine(0, 40, 100, 40, 3, 0);
				break;	
		}
	}




private:
	aie::Font * m_fontType;
	enum class levelSel
	{
		LEVELONE,		LEVELTWO,
		LEVELTHREE,
		BACK,
		SIZE
	};
	int m_sel;
};