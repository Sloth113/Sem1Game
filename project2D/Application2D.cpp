#include "Application2D.h"
#include "Texture.h"
#include "Font.h"
#include "Input.h"
//Code design and datastructures game. 
//Simple game to show custom templated data structures
//And game design patterns
//
// Made by Scott Hart 
// AIE S171463
// 25/06/2017

Application2D::Application2D(){}

Application2D::~Application2D(){}

bool Application2D::startup()
{

	m_2dRenderer = new aie::Renderer2D();

	m_font = new aie::Font("./font/consolas.ttf", 32);
	
	m_cameraX = 0;
	m_cameraY = 0;
	m_timer = 0;
	//STATES
	gameStateMan = GameStateManager((int)eGameState::STATE_COUNT);
	
	gameStateMan.registerState((int)eGameState::SPLASH, new SplashState(m_font, &gameStateMan));
	gameStateMan.registerState((int)eGameState::MENU, new MenuState(m_font, &gameStateMan));
	ScoresState * scores = new ScoresState(m_font, &gameStateMan); 
	gameStateMan.registerState((int)eGameState::INGAME, new InGameState(m_font, &gameStateMan, scores));
	gameStateMan.registerState((int)eGameState::SCORES, scores);
	gameStateMan.registerState((int)eGameState::PAUSE, new PauseState(m_font, &gameStateMan));

	gameStateMan.pushState((int)eGameState::SPLASH);
			
	gameStateMan.update(0); //set up manager

	return true;
}

void Application2D::shutdown()
{
	ResourceManager::getInstance().collectGarbage();

	delete m_font;
	delete m_2dRenderer;
}

void Application2D::update(float deltaTime)
{
	m_timer += deltaTime;
	aie::Input* input = aie::Input::getInstance();

	if (gameStateMan.activeStateCount() > 0)
		gameStateMan.update(deltaTime);
	else
		quit(); //quit when not states

}

void Application2D::draw()
{
	// wipe the screen to the background colour
	clearScreen();

	// set the camera position before we begin rendering
	m_2dRenderer->setCameraPos(m_cameraX, m_cameraY);

	// begin drawing sprites
	m_2dRenderer->begin();
	gameStateMan.draw(m_2dRenderer);
	m_2dRenderer->end();
}