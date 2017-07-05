#pragma once
#include "IPrototype.h"
#include "ResourceManager.h"
#include "MathLibDLL.h"
#include "RoundThings.h"
//Abstract class used for storing prototypes
namespace aie
{
	class Texture;
	class Renderer2D;
}

class Object : public IPrototype
{
public:
	Object() {}

	~Object() {}
	
	virtual std::shared_ptr<IPrototype> clone() = 0;
	virtual std::string getName() { return ""; }

	virtual bool isAlive() { return false; }
	virtual void setAlive(bool state) = 0;
	virtual int getScore() { return 0; }
	virtual void setDirection(float x, float y) = 0;
	virtual void setPosition(float x, float y) = 0;
	virtual bool checkCollision(float x, float y) = 0;

	virtual void update(float dt) = 0;
	virtual void draw(aie::Renderer2D* renderer) = 0;

};