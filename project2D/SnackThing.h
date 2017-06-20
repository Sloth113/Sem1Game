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
#include "LevelSelState.h"
#include "MenuState.h"
#include "SplashState.h"
#include "PauseState.h"
//Resource stuff
#include "ResourceManager.h"
#include "ResourceTestObj.h"
//SNACKFACT
#include "SnackFactory.h"
#include "Snack.h"
#include <list>
#include <time.h>
//OBJECT POOL
#include "ObjectPool.h"

class SnackThing : public aie::Application
{
public:

	SnackThing();
	virtual ~SnackThing();

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

	std::unique_ptr<SnackFactory> m_snackFactory;
	std::list < std::shared_ptr<Snack>> m_snacks;

	ObjectPool<std::shared_ptr<Snack>> m_pool;


};