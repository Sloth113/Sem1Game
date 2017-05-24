#pragma once
#include <vector>
#include <algorithm>
#include "Renderer2D.h"
#include "Input.h"
#include "MathLibDLL.h"
typedef MathDLL::Vector2 Vector2;
typedef MathDLL::Vector3 Vector3;

typedef MathDLL::Matrix2 Matrix2;
typedef MathDLL::Matrix3 Matrix3;

class SceneObject {

	//2D game object, static sprite
public:
	SceneObject();
	virtual ~SceneObject();

	void addChild(SceneObject * child);
	void removeChild(int i);
	void removeChild(SceneObject * child);
	void removeChildren();


	virtual void update(float deltaTime);

	virtual void draw(aie::Renderer2D* renderer);


	void updateGlobalTransform();

	void setLocal(Matrix3);

	Matrix3 getLocalTransform();
	Matrix3 getGlobalTransform();

	int childCount();

	///////MAKE MOVE THINGS N STUFF 
	//CHANGE UP THE LOCAL THEN CALL UPDATE GLOBAL

	bool delFlag;
protected:
	Matrix3 m_globalTransform;
	Matrix3 m_localTransform;

	SceneObject * m_parent;
	std::vector<SceneObject*> m_children;
};