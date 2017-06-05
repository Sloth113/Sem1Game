#include "Snack.h"
#include <Texture.h>
#include <Renderer2D.h>
#include "ResourceManager.h"
#include <iostream>


Snack::Snack(const std::string name, std::shared_ptr<ResourceBase> texture) : m_name(name), m_texture(texture), m_position(MathDLL::Vector2(0, 0)), m_velocity(MathDLL::Vector2(0, 0))
{
}

Snack::Snack(const std::string name, const char * filename) : m_name(name), m_position(MathDLL::Vector2(0, 0)), m_velocity(MathDLL::Vector2(0, 0))
{
	m_texture = ResourceManager::getInstance().get(filename, ResourceManager::TEXTURE);
}

Snack::Snack(const Snack& other)
{
	m_texture = other.m_texture;
	m_position = other.m_position;
	m_velocity = other.m_velocity;
	m_name = other.m_name;
}

Snack::~Snack()
{
	std::cout << m_name << " -1 SNACK" << std::endl;
}

Snack& Snack::operator=(const Snack& other)
{
	m_texture = other.m_texture; 
	m_position = other.m_position; 
	m_velocity = other.m_velocity;
	m_name = other.m_name; 
	return *this; 
} 

std::shared_ptr<IPrototype> Snack::clone() 
{ 
	return std::shared_ptr<IPrototype>(new Snack(*this));
}

void Snack::setPosition(float x, float y) 
{
	m_position.x = x; m_position.y = y; 
}

void Snack::setVelocity(float x, float y) 
{
	m_velocity.x = x; m_velocity.y = y; 
}

void Snack::update(float dt) 
{
	m_position.x += m_velocity.x * dt;
	m_position.y += m_velocity.y * dt;
}

void Snack::draw(aie::Renderer2D* renderer) 
{
	renderer->drawSprite(m_texture->as<aie::Texture>(), m_position.x, m_position.y); 
}

