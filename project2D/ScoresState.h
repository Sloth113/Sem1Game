#pragma once
#include "GameState.h"
#include "LinkedList.h"

//Struct for scores
struct ScoreItem
{
	int session;
	int score;

};
class ScoresState : public GameState
{
public:
	ScoresState(aie::Font * font, GameStateManager * manager)
	{
		m_fontType = font;
		m_manager = manager;
		m_newScore = m_scores.end();//Set null pointer iterator used to check if new score is added
	}

	int addScore(ScoreItem i)
	{
		//Add new score
		int position = 0;
		//If empty or first as insert adds one after iterator 
		if (m_scores.empty() || i.score > m_scores.first().score)
		{
			m_scores.pushFront(i);
			m_newScore = m_scores.begin();
			return 0;
		}
		//Through the linked list or if its gone through 9 
		for (LinkedList<ScoreItem>::Iterator it = m_scores.begin(); it != m_scores.end() && position < 10; it++)
		{
			position++;
			if (i.score > (*it).score)
			{
				it--;
				m_scores.insert(it, i);
				it++;
				m_newScore = it;
				return position;
			}
		}
		return -1; //Not inserted
	}
protected:
	virtual void onUpdate(float deltaTime)
	{
		aie::Input* input = aie::Input::getInstance();
		//Check input
		if (input->wasKeyPressed(aie::INPUT_KEY_SPACE) || input->wasKeyPressed(aie::INPUT_KEY_ESCAPE) || input->wasMouseButtonPressed(aie::INPUT_MOUSE_BUTTON_LEFT))
		{
			m_manager->pushState((int)eGameState::MENU);
			m_manager->popState();
		}
	}
	virtual void onDraw(aie::Renderer2D * renderer)
	{
		renderer->drawText(m_fontType, "SCORES", 0, SCREEN_HEIGHT - 30, 0);
		renderer->drawText(m_fontType, "Press space, escape or click to go to menu", 0, 40, 0);
		//Draw scores
		int offset = 80;
		char score[32];
		char session[32];
		for (LinkedList<ScoreItem>::Iterator it = m_scores.begin(); it != m_scores.end(); it++)
		{
			//Check if new input 
			if (it == m_newScore)
			{
				renderer->setRenderColour(1, 0, 0);
			}
			else
			{
				renderer->setRenderColour(1, 1, 1);
			}
			sprintf_s(score, 32, "SCORE: %i", (*it).score);
			renderer->drawText(m_fontType, score, 0, SCREEN_HEIGHT - (float)offset);
			sprintf_s(session, 32, "Session: %i", (*it).session);
			renderer->drawText(m_fontType, session, 260, SCREEN_HEIGHT - (float)offset);
			offset += 60;
		}
		//Select icon / line

	}
	virtual void onExit()
	{
		m_newScore = m_scores.end(); //Reset pointers
	}
private:
	aie::Font * m_fontType;
	LinkedList<ScoreItem>::Iterator m_newScore;
	LinkedList<ScoreItem> m_scores;
};