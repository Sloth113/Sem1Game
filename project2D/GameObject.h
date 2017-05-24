#pragma once
#include "SpriteObject.h"
class FiniteStateMachine;

class GameObject :public SpriteObject
{
public:
	GameObject(aie::Texture * texture, FiniteStateMachine * fsm);
	virtual ~GameObject() {};
	virtual void update(float deltaTime);
	virtual void draw(aie::Renderer2D * renderer);

protected:
	aie::Texture * m_texture;
private:
	float m_var;
	Vector3 m_vel;
	FiniteStateMachine * m_fsm;
};