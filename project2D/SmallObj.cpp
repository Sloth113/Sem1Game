#include "SmallObj.h"
#include <Texture.h>
#include <Renderer2D.h>
#include "ResourceManager.h"
#include <iostream>
//Small object designed to had small hit box
SmallObj::SmallObj(const std::string name, std::shared_ptr<ResourceBase> texture) : m_name(name), m_texture(texture), m_position(MathDLL::Vector2(0, 0)), m_velocity(MathDLL::Vector2(0, 0)), m_collider(0,0,5)
{

}

SmallObj::SmallObj(const std::string name, const char * filename) : m_name(name), m_position(MathDLL::Vector2(0, 0)), m_velocity(MathDLL::Vector2(0, 0)), m_collider(0, 0, 5)
{
	m_texture = ResourceManager::getInstance().get(filename, ResourceManager::TEXTURE);
}

SmallObj::SmallObj(const SmallObj & other)
{
	m_texture = other.m_texture;
	m_position = other.m_position;
	m_velocity = other.m_velocity;
	m_collider = other.m_collider;
	m_name = other.m_name;
}

SmallObj::~SmallObj()
{
}

SmallObj & SmallObj::operator=(const SmallObj & other)
{
	m_texture = other.m_texture;
	m_position = other.m_position;
	m_velocity = other.m_velocity;
	m_collider = other.m_collider;
	m_name = other.m_name;
	return *this;
}

std::shared_ptr<IPrototype> SmallObj::clone()
{
	return std::shared_ptr<IPrototype>(new SmallObj(*this));
}

void SmallObj::setDirection(float x, float y)
{
	m_velocity.x = x; m_velocity.y = y;
	m_velocity.normalise();
	m_velocity *= 150;
}

void SmallObj::setPosition(float x, float y)
{
	m_position.x = x; m_position.y = y;
	m_collider.x = x; m_collider.y = y;
}

bool SmallObj::checkCollision(float x, float y)
{
	if (m_collider.collides(x, y))
	{
		m_alive = false;
		return true;
	}
	else
	{
		return  false;
	}
}

void SmallObj::update(float dt)
{
	m_position.x += m_velocity.x * dt;
	m_position.y += m_velocity.y * dt;
	m_collider.x = m_position.x; m_collider.y = m_position.y;
	if (m_position.x < 0 || m_position.x > SCREEN_WIDTH || m_position.y < 0 || m_position.y > SCREEN_HEIGHT)
	{
		m_alive = false;//bounds
	}
}

void SmallObj::draw(aie::Renderer2D * renderer)
{
	renderer->drawSprite(m_texture->as<aie::Texture>(), m_position.x, m_position.y);
}
