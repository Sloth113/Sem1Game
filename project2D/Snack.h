#pragma once
#include "IPrototype.h"
#include "ResourceManager.h"
#include "MathLibDLL.h"

namespace aie
{
	class Texture;
	class Renderer2D;
}

class Snack : public IPrototype
{
public:
	Snack(const std::string name, std::shared_ptr<ResourceBase> texture);
	Snack(const std::string name, const char* filename);
	Snack(const Snack& other);
	~Snack();

	Snack& operator= (const Snack& other);

	virtual std::shared_ptr<IPrototype> clone();
	virtual std::string getName() { return m_name; }

	bool isAlive() { return m_bAlive; }
	MathDLL::Vector2 getPosition() { return m_position; }

	void setAlive(bool state) { m_bAlive = state; };
	void setVelocity(float x, float y);
	void setPosition(float x, float y);

	void update(float dt);
	void draw(aie::Renderer2D* renderer);


private:
	std::shared_ptr<ResourceBase> m_texture;
	MathDLL::Vector2 m_position;
	MathDLL::Vector2 m_velocity;
	bool m_bAlive;
	std::string m_name;
};