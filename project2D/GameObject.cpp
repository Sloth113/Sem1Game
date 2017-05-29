#include "GameObject.h"

GameObject::GameObject(aie::Texture * texture, FiniteStateMachine * fsm) :m_texture(texture)
{
	m_vel = Vector3(1, 2, 3);
	m_fsm = fsm;
}

void GameObject::update(float deltaTime)
{
	if(m_fsm != nullptr)
		m_fsm->update(this, deltaTime);
	SceneObject::update(deltaTime);
}

void GameObject::draw(aie::Renderer2D * renderer)
{
	renderer->drawSpriteTransformed3x3(m_texture, (float*)m_globalTransform);
	SceneObject::draw(renderer);
}
