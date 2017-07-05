#include "SlowObj.h"
#include <Texture.h>
#include <Renderer2D.h>
#include "ResourceManager.h"
#include <iostream>
//Slow object
SlowObj::SlowObj(const std::string name, std::shared_ptr<ResourceBase> texture) : m_name(name), m_texture(texture), m_position(MathDLL::Vector2(0, 0)), m_velocity(MathDLL::Vector2(0, 0)),m_collider(0, 0, 75)
{
}

SlowObj::SlowObj(const std::string name, const char * filename) : m_name(name), m_position(MathDLL::Vector2(0, 0)), m_velocity(MathDLL::Vector2(0, 0)), m_collider(0, 0, 75)
{
	m_texture = ResourceManager::getInstance().get(filename, ResourceManager::TEXTURE);
}

SlowObj::SlowObj(const SlowObj & other)
{
	m_texture = other.m_texture;
	m_position = other.m_position;
	m_velocity = other.m_velocity;
	m_collider = other.m_collider;
	m_name = other.m_name;
}

SlowObj::~SlowObj()
{
}

SlowObj & SlowObj::operator=(const SlowObj & other)
{
	m_texture = other.m_texture;
	m_position = other.m_position;
	m_velocity = other.m_velocity;
	m_collider = other.m_collider;
	m_name = other.m_name;
	return *this;
}

std::shared_ptr<IPrototype> SlowObj::clone()
{
	return std::shared_ptr<IPrototype>(new SlowObj(*this));
}

void SlowObj::setDirection(float x, float y)
{
	m_velocity.x = x; m_velocity.y = y;
	m_velocity.normalise();
	m_velocity *= 100; //slower speed
}

void SlowObj::setPosition(float x, float y)
{
	m_position.x = x; m_position.y = y;
	m_collider.x = x; m_collider.y = y;
}
//Collision and logic for collision 
bool SlowObj::checkCollision(float x, float y)
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

void SlowObj::update(float dt)
{
	m_position.x += m_velocity.x * dt;
	m_position.y += m_velocity.y * dt;
	m_collider.x = m_position.x; m_collider.y = m_position.y;
	if (m_position.x < 0 || m_position.x > SCREEN_WIDTH || m_position.y < 0 || m_position.y > SCREEN_HEIGHT)
	{
		m_alive = false;//bounds
	}
}

void SlowObj::draw(aie::Renderer2D * renderer)
{
	renderer->drawSprite(m_texture->as<aie::Texture>(), m_position.x, m_position.y);
}
