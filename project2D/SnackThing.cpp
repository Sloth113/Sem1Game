#include "SnackThing.h"
#include "Texture.h"
#include "Font.h"
#include "Input.h"

SnackThing::SnackThing()
{

}

SnackThing::~SnackThing()
{

}

bool SnackThing::startup()
{

	m_2dRenderer = new aie::Renderer2D();

	m_texture = new aie::Texture("./textures/numbered_grid.tga");
	m_shipTexture = new aie::Texture("./textures/ship.png");

	m_font = new aie::Font("./font/consolas.ttf", 32);

	m_audio = new aie::Audio("./audio/powerup.wav");

	m_cameraX = 0;
	m_cameraY = 0;
	m_timer = 0;

	srand(time(NULL));

	m_snackFactory = std::unique_ptr<SnackFactory>(new SnackFactory());

	std::shared_ptr<Snack> cake(new Snack("cake", "./textures/cake.png"));
	cake->setPosition(200, 100);

	std::shared_ptr<Snack> croissant(new Snack("croissant", "./textures/croissant.png"));
	croissant->setPosition(500, 400);

	m_snackFactory->addPrototype(cake);
	m_snackFactory->addPrototype(croissant);

	return true;
}

void SnackThing::shutdown()
{


	delete m_audio;
	delete m_font;
	delete m_texture;
	delete m_shipTexture;
	delete m_2dRenderer;


}

void SnackThing::update(float deltaTime)
{

	aie::Input* input = aie::Input::getInstance(); 
	static float timer = 0; 
	if (timer <= 0)
	{
		timer = 0.5f;

		std::shared_ptr<IPrototype> snackClone; 
		if (rand() % 2 == 0) 
			snackClone = m_snackFactory->create("cake");
		else 
			snackClone = m_snackFactory->create("croissant");
		// dynamically cast the shared pointer from IPrototype to Snack
		std::shared_ptr<Snack> snack = std::dynamic_pointer_cast<Snack>(snackClone);
		snack->setVelocity(50 - rand() % 100, 50 - rand() % 100);
		m_snacks.push_back(snack); 
	}
	timer -= deltaTime;
	
	for (auto it = m_snacks.begin(); it != m_snacks.end(); ) 
	{
		(*it)->update(deltaTime);
		MathDLL::Vector2 pos = (*it)->getPosition(); 
		if (pos.x < 0 || pos.y < 0 || pos.x > this->getWindowWidth() || pos.y > this->getWindowHeight()) 
		{
			it = m_snacks.erase(it);
		}
		else
		{
			++it;
		}
	}
	// exit the application 
	if (input->isKeyDown(aie::INPUT_KEY_ESCAPE)) quit();
}

void SnackThing::draw()
{

	clearScreen();
	// begin drawing sprites 
	m_2dRenderer->begin(); 
	// draw your stuff here! 
	for (std::shared_ptr<Snack> snack : m_snacks)
	{
		snack->draw(m_2dRenderer);
	} 
	// output some text 
	m_2dRenderer->drawText(m_font, "Press ESC to quit", 0, 0); 
	// done drawing sprites 
	m_2dRenderer->end();
}