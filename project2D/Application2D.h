#pragma once

#include "Application.h"
#include "Renderer2D.h"
#include "Audio.h"
//My files
#include "MathLibDLL.h"
#include "GameStateManager.h"
#include "InGameState.h"
#include "LevelSelState.h"
#include "MenuState.h"
#include "SplashState.h"
#include "PauseState.h"
#include "defines.h"


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
	aie::Texture*		m_texture;
	aie::Texture*		m_shipTexture;
	aie::Font*			m_font;
	aie::Audio*			m_audio;

	float m_cameraX, m_cameraY;
	float m_timer;

	MathDLL::Vector3 v3;

	GameStateManager gameStateMan;


};