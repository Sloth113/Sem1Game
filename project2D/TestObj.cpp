#include "TestObj.h"

TestObj::TestObj(aie::Texture * texture, FiniteStateMachine * fsm):GameObject(texture,fsm)
{
	
}

void TestObj::update(float deltaTime)
{
	GameObject::update(deltaTime);
}

void TestObj::draw(aie::Renderer2D * renderer)
{
	GameObject::draw(renderer);
}
