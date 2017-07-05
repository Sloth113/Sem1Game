#pragma once
#include "Application.h"
#include "Renderer2D.h"
#include "Audio.h"
//My files
//Math lib
#include "MathLibDLL.h"
// Global vars
#include "defines.h"
//States
#include "GameStateManager.h"
#include "InGameState.h"
#include "MenuState.h"
#include "SplashState.h"
#include "PauseState.h"
#include "ScoresState.h"
//Resource stuff
#include "ResourceManager.h"


class Application2D : public aie::Application {
public:

	Application2D();
	virtual ~Application2D();

	virtual bool startup();
	virtual void shutdown();

	virtual void update(float deltaTime);
	virtual void draw();

protected:

	aie::Renderer2D*	m_2dRenderer;
	aie::Font*			m_font;

	float m_cameraX, m_cameraY;
	float m_timer;

	GameStateManager gameStateMan;

	std::shared_ptr<ResourceBase> m_textureTest;
};