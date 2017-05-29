#include "Application2D.h"
#include "Texture.h"
#include "Font.h"
#include "Input.h"

Application2D::Application2D()
{

}

Application2D::~Application2D()
{

}

bool Application2D::startup()
{

	m_2dRenderer = new aie::Renderer2D();

	m_texture = new aie::Texture("./textures/numbered_grid.tga");
	m_shipTexture = new aie::Texture("./textures/ship.png");

	m_font = new aie::Font("./font/consolas.ttf", 32);

	m_audio = new aie::Audio("./audio/powerup.wav");

	m_cameraX = 0;
	m_cameraY = 0;
	m_timer = 0;

	v3 = MathDLL::Vector3(1, 2, 3);
	
	gameStateMan = GameStateManager((int)eGameState::STATE_COUNT);
	

	gameStateMan.registerState((int)eGameState::SPLASH, new SplashState(m_font, &gameStateMan));
	gameStateMan.registerState((int)eGameState::MENU, new MenuState(m_font, &gameStateMan));
	gameStateMan.registerState((int)eGameState::LEVELSEL, new LevelSelState(m_font, &gameStateMan));
	gameStateMan.registerState((int)eGameState::INGAME, new InGameState(m_font, &gameStateMan));
	gameStateMan.registerState((int)eGameState::PAUSE, new PauseState(m_font, &gameStateMan));



	gameStateMan.pushState((int)eGameState::SPLASH);
	std::cout << gameStateMan.activeStateCount();


	return true;
}

void Application2D::shutdown()
{

	delete m_audio;
	delete m_font;
	delete m_texture;
	delete m_shipTexture;
	delete m_2dRenderer;
}

void Application2D::update(float deltaTime)
{

	m_timer += deltaTime;

	// input example
	aie::Input* input = aie::Input::getInstance();

	//if (gameStateMan.activeStateCount() > 0)
	//{
		gameStateMan.update(deltaTime);
		//std::cout << "SOMETHING PLS";
	//}


}

void Application2D::draw()
{

	// wipe the screen to the background colour
	clearScreen();


	// set the camera position before we begin rendering
	m_2dRenderer->setCameraPos(m_cameraX, m_cameraY);

	// begin drawing sprites
	m_2dRenderer->begin();
	//if (gameStateMan.activeStateCount() > 0)
		gameStateMan.draw(m_2dRenderer);

	/*
	// demonstrate animation
	m_2dRenderer->setUVRect(int(m_timer) % 8 / 8.0f, 0, 1.f / 8, 1.f / 8);
	m_2dRenderer->drawSprite(m_texture, 200, 200, 100, 100);

	// demonstrate spinning sprite
	m_2dRenderer->setUVRect(0, 0, 1, 1);
	m_2dRenderer->drawSprite(m_shipTexture, 600, 400, 0, 0, m_timer, 1);

	// draw a thin line
	m_2dRenderer->drawLine(300, 300, 600, 400, 2, 1);

	// draw a moving purple circle
	m_2dRenderer->setRenderColour(1, 0, 1, 1);
	m_2dRenderer->drawCircle(sin(m_timer) * 100 + 600, 150, 50);

	// draw a rotating red box
	m_2dRenderer->setRenderColour(1, 0, 0, 1);
	m_2dRenderer->drawBox(600, 500, 60, 20, m_timer);

	// draw a slightly rotated sprite with no texture, coloured yellow
	m_2dRenderer->setRenderColour(1, 1, 0, 1);
	m_2dRenderer->drawSprite(nullptr, 400, 400, 50, 50, 3.14159f * 0.25f, 1);

	// output some text, uses the last used colour
	char fps[32];
	sprintf_s(fps, 32, "TEST: %f", v3.y);
	m_2dRenderer->drawText(m_font, fps, 0, 720 - 32);
	m_2dRenderer->drawText(m_font, "Press Space for sound!", 0, 720 - 64);
	*/
	// done drawing sprites
	m_2dRenderer->end();
}