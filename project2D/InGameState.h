#pragma once
#include "GameState.h"
#include "Stack.h"
#include "FactoryPool.h"
#include <list>
#include <random>
#include <time.h>
//GameObjs
#include "FastObj.h"
#include "SlowObj.h"
#include "SmallObj.h"
#include "RandomObj.h"
//State for scoreboard
#include "ScoresState.h"
//
#include "DynArray.h"
#include "Stack.h"


class InGameState : public GameState
{
public:
	InGameState(aie::Font * font, GameStateManager * manager, ScoresState * scoreBoard)
	{
		m_fontType = font;
		m_timer = 0;
		m_gameTimer = 0;
		m_session = 0;
		m_score = 0;
		m_manager = manager;
		m_scoreBoard = scoreBoard;
		//Set up factory with prototypes
		m_factoryPool = std::unique_ptr<FactoryPool>(new FactoryPool());

		std::shared_ptr<FastObj> fast(new FastObj("fast", "./textures/FastObj.png"));
		fast->setPosition(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2);

		std::shared_ptr<SlowObj> slow(new SlowObj("slow", "./textures/SlowObj.png"));
		slow->setPosition(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2);

		std::shared_ptr<SmallObj> small(new SmallObj("small", "./textures/SmallObj.png"));
		small->setPosition(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2);

		std::shared_ptr<RandomObj> random(new RandomObj("random", "./textures/RandomObj.png"));
		random->setPosition(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2);

		m_factoryPool->addPrototype(fast);
		m_factoryPool->addPrototype(slow);
		m_factoryPool->addPrototype(small);
		m_factoryPool->addPrototype(random);

		srand((unsigned int)time(NULL));

	}
protected:
	virtual void onUpdate(float deltaTime)
	{
		aie::Input* input = aie::Input::getInstance();
		//GAME LOGIC
		m_timer += deltaTime;
		m_gameTimer += deltaTime;
		//Spanwer
		if (m_timer > 1)
		{
			//Prototype 
			//
			std::shared_ptr<IPrototype> spawn;
			int rand = std::rand() % 4;
			if (rand == 0)
			{
				spawn = m_factoryPool->create("fast");
				std::shared_ptr<FastObj> fast = std::dynamic_pointer_cast<FastObj>(spawn);
				fast->setDirection(50.0f - std::rand() % 100, 50.0f - std::rand() % 100);
				m_objects.add(fast);
			}
			else if (rand == 1)
			{
				spawn = m_factoryPool->create("slow");
				std::shared_ptr<SlowObj> slow = std::dynamic_pointer_cast<SlowObj>(spawn);
				slow->setDirection(50.0f - std::rand() % 100, 50.0f - std::rand() % 100);
				m_objects.add(slow);
			}
			else if (rand == 2)
			{
				spawn = m_factoryPool->create("small");
				std::shared_ptr<SmallObj> small = std::dynamic_pointer_cast<SmallObj>(spawn);
				small->setDirection(50.0f - std::rand() % 100, 50.0f - std::rand() % 100);
				m_objects.add(small);
			}
			else if (rand == 3)
			{
				spawn = m_factoryPool->create("random");
				std::shared_ptr<RandomObj> random = std::dynamic_pointer_cast<RandomObj>(spawn);
				random->setDirection(50.0f - std::rand() % 100, 50.0f - std::rand() % 100);
				m_objects.add(random);

			}
			m_timer = 0;
		}
		//UPDATE Objects
		for (int i = 0; i < m_objects.getSize(); i++)
		{
			m_objects[i]->update(deltaTime);
			if (m_objects[i]->isAlive() && input->isMouseButtonDown(aie::INPUT_MOUSE_BUTTON_LEFT) && (m_objects[i])->checkCollision((float)input->getMouseX(), (float)input->getMouseY()))
			{
				m_objects[i]->setAlive(false);
				m_score += m_objects[i]->getScore();
				i--;
			}
		}
		for (int i = 0; i < m_objects.getSize(); i++)
		{
			if (!(m_objects[i])->isAlive())
			{
				m_objects.remove(i);
				i--;
			}
		}

		if (input->wasKeyPressed(aie::INPUT_KEY_ESCAPE))
		{
			//Pause menu
			m_manager->pushState((int)eGameState::PAUSE);
			m_active = false;
		}

		if (m_gameTimer >= GAMETIME)
		{
			m_manager->pushState((int)eGameState::SCORES);
			m_manager->popState();
			ScoreItem score;
			score.session = m_session;
			score.score = m_score;
			m_scoreBoard->addScore(score);
		}

	}

	virtual void onDraw(aie::Renderer2D * renderer)
	{
		//Draw
		for (int i = 0; i < m_objects.getSize(); i++)
		{
			m_objects[i]->draw(renderer);
		}
		char score[32];
		sprintf_s(score, 32, "SCORE: %i", m_score);
		renderer->drawText(m_fontType, score, 0, SCREEN_HEIGHT - 60);
		char time[32];
		sprintf_s(time, 32, "Time left: %f", GAMETIME - m_gameTimer);
		renderer->drawText(m_fontType, time, SCREEN_WIDTH - 280, SCREEN_HEIGHT - 60);

	}

	virtual void onPushed()
	{
		m_session++;
	}
	virtual void onPopped()
	{
		//reset things
		m_gameTimer = 0;
		m_score = 0;
		m_objects.clear();
	}

private:
	int m_level = 0;
	aie::Font * m_fontType;
	float m_timer;
	float m_gameTimer;
	int m_score;
	int m_session;
	ScoresState * m_scoreBoard;

	//Temp
	std::unique_ptr<FactoryPool> m_factoryPool;
	//Custom dynamic array
	DynArray<std::shared_ptr < Object >> m_objects;
};