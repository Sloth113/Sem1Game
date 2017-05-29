#pragma once
#include "GameObject.h"

class TestObj :public GameObject
{
public:
	TestObj(aie::Texture * texture, FiniteStateMachine * fsm);
	virtual void update(float deltaTime);
	virtual void draw(aie::Renderer2D * renderer);

protected:
	

private:


};
