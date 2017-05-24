#include "Rays.h"

Rays::Rays()
{
	bool3D = false;
	origin = Vector3();
	direction = Vector3();
	length = 0;
	

}

Rays::Rays(Vector3 ori, Vector3 dir, float len)
{
	bool3D = true;
	origin = ori;
	direction = dir;
	direction.normalise();
	length = len;
}

Rays::Rays(Vector3 ori, Vector3 to)
{
	bool3D = true;
	origin = ori;
	
	Vector3 between = to - ori;
	length = between.magnitude();
	
	between.normalise();
	direction = between;
	
}

Rays::Rays(Vector3 dir)
{
	bool3D = true;
	origin = Vector3();
	direction = dir;
	direction.normalise();
	length = dir.magnitude();
	
}


Rays::Rays(Vector2 ori, Vector2 dir, float len)
{
}

Rays::Rays(Vector2 ori, Vector2 to)
{

	bool3D = false;
	origin = ori;
	 
	Vector3 between = to - ori;
	length = between.magnitude();
	direction = between.getNormalised();
	/////////////////////////////

}

Rays::Rays(Vector2 dir)
{
	bool3D = false;
	origin = Vector2();
	direction = dir;

	length = dir.magnitude();
	direction.normalise();

}


bool Rays::collides(RoundThings thing)
{
	if (distFrom(Vector3(thing.x, thing.y, thing.z)) <= thing.radi) {
		return true;
	}else{
		return false;
	}
}

bool Rays::collides2D(AxisABBox thing)
{
	////THIS FIGURE THIS OUT >_> 

	return false;
}

bool Rays::collides(Vector3 point, float tol)
{
	RoundThings tmp = RoundThings(point, tol / 2);

	return collides(tmp);
}


Vector3 Rays::closestPoint(Vector3 p)
{
	Vector3 dist = p - origin;
	float fromOrig = dist.dot(direction); 
	//Clamp
	if (fromOrig <= 0) fromOrig = 0;
	if (fromOrig >= length) fromOrig = length;

	return origin + direction * fromOrig;
}

float Rays::distFrom(Vector3 p)
{
	Vector3 cp = closestPoint(p);
	cp = cp - p;
	return cp.magnitude();
}
