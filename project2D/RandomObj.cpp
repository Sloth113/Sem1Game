#include "RandomObj.h"
#include <Texture.h>
#include <Renderer2D.h>
#include "ResourceManager.h"
#include <iostream>
//Random object
RandomObj::RandomObj(const std::string name, std::shared_ptr<ResourceBase> texture) : m_name(name), m_texture(texture), m_position(MathDLL::Vector2(0, 0)), m_velocity(MathDLL::Vector2(0, 0)), m_collider(0, 0, 15)
{
}

RandomObj::RandomObj(const std::string name, const char * filename) : m_name(name), m_position(MathDLL::Vector2(0, 0)), m_velocity(MathDLL::Vector2(0, 0)), m_collider(0, 0, 15)
{
	m_texture = ResourceManager::getInstance().get(filename, ResourceManager::TEXTURE);
}

RandomObj::RandomObj(const RandomObj & other)
{
	m_texture = other.m_texture;
	m_position = other.m_position;
	m_velocity = other.m_velocity;
	m_collider = other.m_collider;
	m_name = other.m_name;
}

RandomObj::~RandomObj()
{
}

RandomObj & RandomObj::operator=(const RandomObj & other)
{
	m_texture = other.m_texture;
	m_position = other.m_position;
	m_velocity = other.m_velocity;
	m_collider = other.m_collider;
	m_name = other.m_name;
	return *this;
}

std::shared_ptr<IPrototype> RandomObj::clone()
{
	return std::shared_ptr<IPrototype>(new RandomObj(*this));
}

void RandomObj::setDirection(float x, float y)
{
	m_velocity.x = x; m_velocity.y = y;
	m_velocity.normalise();
	m_velocity *= 200;
}

void RandomObj::setPosition(float x, float y)
{
	m_position.x = x; m_position.y = y;
	m_collider.x = x; m_collider.y = y;
}
//Collision check and logic
bool RandomObj::checkCollision(float x, float y)
{
	if (m_collider.collides(x, y))
	{
		return true;
	}
	else
	{
		return  false;
	}
}
//Randomly changes direction (uses random number 1/50 chance every frame)
void RandomObj::update(float dt)
{
	if (rand() % 50 == 0)
	{
		this->setDirection(50.0f - std::rand() % 100, 50.0f - std::rand() % 100);
	}
	m_position.x += m_velocity.x * dt;
	m_position.y += m_velocity.y * dt;
	m_collider.x = m_position.x; m_collider.y = m_position.y;
	if (m_position.x < 0 || m_position.x > SCREEN_WIDTH || m_position.y < 0 || m_position.y > SCREEN_HEIGHT)
	{
		m_alive = false;//bounds
	}
}

void RandomObj::draw(aie::Renderer2D * renderer)
{
	renderer->drawSprite(m_texture->as<aie::Texture>(), m_position.x, m_position.y);
}
