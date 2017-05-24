#pragma once
#include "SceneObject.h"
typedef MathDLL::Vector2 Vector2;
typedef MathDLL::Vector3 Vector3;

typedef MathDLL::Matrix2 Matrix2;
typedef MathDLL::Matrix3 Matrix3;

class SpriteObject :public SceneObject {
public:
	SpriteObject();
	SpriteObject(aie::Texture* texture);
	SpriteObject(aie::Texture * texture, Vector3 dis);
	virtual ~SpriteObject() {};
	virtual void update(float deltaTime);
	virtual void draw(aie::Renderer2D* renderer);



protected:
	aie::Texture* m_texture;
};