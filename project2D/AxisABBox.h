#pragma once
#include "MathLibDLL.h"

typedef MathDLL::Vector2 Vector2;
typedef MathDLL::Vector3 Vector3;

typedef MathDLL::Matrix2 Matrix2;
typedef MathDLL::Matrix3 Matrix3;

class AxisABBox {

public:
	float xMin, xMax, yMin, yMax, zMin, zMax;

	AxisABBox();
	AxisABBox(float x1, float x2, float y1, float y2);
	AxisABBox(float x1, float x2, float y1, float y2, float z1, float z2);	
	
	void expand(float x, float y);
	void expand(float x, float y, float z);
	void expand(Vector2 v);
	void expand(Vector3 v);
	
	void expand(AxisABBox aabb);
	
	bool collides(float x, float y);
	bool collides(float x, float y, float z);
	bool collides(Vector2 v);
	bool collides(Vector3 v);
	bool collides(AxisABBox aabb);
};