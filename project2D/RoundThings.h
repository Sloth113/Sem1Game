#pragma once
#include "AxisABBox.h"
typedef MathDLL::Vector2 Vector2;
typedef MathDLL::Vector3 Vector3;

typedef MathDLL::Matrix2 Matrix2;
typedef MathDLL::Matrix3 Matrix3;
//Collision stuff for spheres and circles
class RoundThings {
public:
	float x, y, z;
	float radi;
	RoundThings();
	RoundThings(float xPos, float yPos, float zPos, float radius);
	RoundThings(float xPos, float yPos, float radius);
	RoundThings(Vector3 v3, float radius);
	RoundThings(Vector2 v2, float radius);
	RoundThings(Vector2 * points, int size);
	RoundThings(Vector3 * points, int size);
	RoundThings(RoundThings * things, int size);
	

	void expand(Vector2 * points, int size);
	void expand(Vector2 point);
	void expand(Vector3 * points, int size);
	void expand(Vector3 point);
	void expand(float xPos, float yPos);
	void expand(RoundThings * things, int size);
	void expand(RoundThings things);

	//Points
	bool collides(float xPos, float yPos);
	bool collides(float xPos, float yPos, float zPos);
	bool collides(Vector2 v);
	bool collides(Vector3 v);
	bool collides(RoundThings r);
	bool collides2D(AxisABBox a);

};