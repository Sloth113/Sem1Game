#include "SceneObject.h"

SceneObject::SceneObject()
{
	m_parent = nullptr;
	delFlag = false;
}

SceneObject::~SceneObject()
{
	for (SceneObject* child : m_children) {
		delete child;
	}
}

void SceneObject::addChild(SceneObject * child)
{
	if (child->m_parent == nullptr) {
		child->m_parent = this;
		m_children.push_back(child);
	}
}

void SceneObject::update(float deltaTime)
{
	std::vector<SceneObject *> copy = m_children;
	for (SceneObject* child : copy) {
		child->update(deltaTime);
	}
	if(m_children.size() > 0)
		m_children.erase(std::remove_if(m_children.begin(), m_children.end(), [](const SceneObject * s) {return s->delFlag; }),m_children.end());
	
}

void SceneObject::draw(aie::Renderer2D * renderer)
{
	for (SceneObject* child : m_children) {
		child->draw(renderer);
	}
}

void SceneObject::updateGlobalTransform()
{
	if (m_parent != nullptr) {
		m_globalTransform = m_parent->m_globalTransform * m_localTransform;
	}
	else {
		m_globalTransform = m_localTransform;
	}
	for (SceneObject* child : m_children) {
		child->updateGlobalTransform();
	}
}

void SceneObject::setLocal(Matrix3 m3)
{
	m_localTransform = m3;
	updateGlobalTransform();
}

Matrix3 SceneObject::getLocalTransform()
{
	return m_localTransform;
}

Matrix3 SceneObject::getGlobalTransform()
{
	return m_globalTransform;
}

int SceneObject::childCount()
{
	int count = m_children.size();
	for each(auto child in m_children) {
		count += child->childCount();
	}
	return count;
}
