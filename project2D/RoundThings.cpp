#include "RoundThings.h"
//Round things used in maths demonstration, used in click detection 
RoundThings::RoundThings()
{
	x = 0; y = 0; z = 0; radi = 0;
}

RoundThings::RoundThings(float xPos, float yPos, float zPos, float radius)
{
	x = xPos; y = yPos; z = zPos; radi = radius;
}

RoundThings::RoundThings(float xPos, float yPos, float radius)
{
	x = xPos; y = yPos; z = 0; radi = radius;
}

RoundThings::RoundThings(Vector3 v3, float radius)
{
	x = v3.x; y = v3.y; z = v3.z; radi = radius;
}

RoundThings::RoundThings(Vector2 v2, float radius)
{
	x = v2.x; y = v2.y; z = 0; radi = radius;
}

RoundThings::RoundThings(Vector2 * points, int size)
{
	x = points[0].x; y = points[0].y; z = 0; radi = 0;
	for (int i = 1; i < size; i++)
	{
		if (!collides(points[i]))
		{
			this->expand(points[i]);
		}
	}
}

RoundThings::RoundThings(Vector3 * points, int size)
{
	x = points[0].x; y = points[0].y; z = points[0].z; radi = 0;
	for (int i = 1; i < size; i++)
	{
		if (!collides(points[i]))
		{
			this->expand(points[i]);
		}
	}
}

RoundThings::RoundThings(RoundThings * things, int size)
{
	x = things[0].x; y = things[0].y; z = things[0].z; radi = things[0].radi;
	for (int i = 1; i < size; i++)
	{
		if (!(this->collides(things[i])))
		{
			this->expand(things[i]);
		}
	}
}

void RoundThings::expand(Vector2 * points, int size)
{
	for (int i = 0; i < size; i++)
	{
		this->expand(points[i]);
	}
}

void RoundThings::expand(Vector2 point)
{
	expand(point.x, point.y);

}

void RoundThings::expand(Vector3 * points, int size)
{
	for (int i = 0; i < size; i++)
	{
		this->expand(points[i]);
	}
}

void RoundThings::expand(Vector3 point)
{
	if (!(this->collides(point)))
	{
		Vector3 dis = Vector3(x, y, z) - point;
		radi = dis.magnitude();
	}
}

void RoundThings::expand(float xPos, float yPos)
{
	if (!(this->collides(xPos, yPos)))
	{
		Vector2 dis = Vector2(x, y) - Vector2(xPos, yPos);
		radi = dis.magnitude();
	}
}

void RoundThings::expand(RoundThings * things, int size)
{
	for (int i = 0; i < size; i++)
	{
		this->expand(things[i]);
	}
}

void RoundThings::expand(RoundThings thing)
{
	if (!(this->collides(thing)))
	{
		Vector3 dis = Vector3(x, y, z) - Vector3(thing.x, thing.y, thing.z);
		radi = dis.magnitude() + thing.radi;
	}
}

bool RoundThings::collides(float xPos, float yPos)
{
	float test = xPos;

	return this->collides(Vector2(xPos, yPos));

}

bool RoundThings::collides(float xPos, float yPos, float zPos)
{
	return this->collides(Vector3(xPos, yPos, zPos));
}

bool RoundThings::collides(Vector2 v)
{
	Vector2 dis = Vector2(x, y) - v;
	if (dis.getMagSquare() < radi*radi)
	{
		return true;
	}
	return false;
}

bool RoundThings::collides(Vector3 v)
{
	Vector3 dis = Vector3(x, y, z) - v;
	if (dis.getMagSquare() < radi *radi)
	{
		return true;
	}
	return false;
}

bool RoundThings::collides(RoundThings r)
{
	Vector3 dis = Vector3(x, y, z) - Vector3(r.x, r.y, r.z);
	if (dis.getMagSquare() < (radi + r.radi)*(radi*r.radi))
	{
		return true;
	}
	return false;
}

bool RoundThings::collides2D(AxisABBox a)
{
	Vector2 point = Vector2(x, y);
	//Clamp
	if (x > a.xMax)
		point.x = a.xMax;
	if (x < a.xMin)
		point.x = a.xMin;
	if (y > a.yMax)
		point.y = a.yMax;
	if (y < a.yMin)
		point.y = a.yMin;

	return this->collides(point);

}


