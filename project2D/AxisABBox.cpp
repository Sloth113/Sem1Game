#include "AxisABBox.h"
#include <limits>

AxisABBox::AxisABBox()
{
	
	xMin = std::numeric_limits<float>::max(); xMax = std::numeric_limits<float>::min(); 
	yMin = std::numeric_limits<float>::max(); yMax = std::numeric_limits<float>::min(); 
	zMin = std::numeric_limits<float>::max(); zMax = std::numeric_limits<float>::min();
}

AxisABBox::AxisABBox(float x1, float x2, float y1, float y2)
{
	xMin = x1; xMax = x2; 
	yMin = y1; yMax = y2; 
	zMin = std::numeric_limits<float>::max(); zMax = std::numeric_limits<float>::min();
}

AxisABBox::AxisABBox(float x1, float x2, float y1, float y2, float z1, float z2)
{
	xMin = x1; xMax = x2;
	yMin = y1; yMax = y2; 
	zMin = z1; zMax = z2;
}

void AxisABBox::expand(float x, float y)
{
	if (x < xMin) xMin = x;
	if (x > xMax) xMax = x;
	if (y < yMin) yMin = y;
	if (y > yMax) yMax = y;

}

void AxisABBox::expand(float x, float y, float z)
{
	if (x < xMin) xMin = x;
	if (x > xMax) xMax = x;
	if (y < yMin) yMin = y;
	if (y > yMax) yMax = y;
	if (z < zMin) zMin = z;
	if (z > zMax) zMax = z;
}

void AxisABBox::expand(Vector2 v)
{
	if (v.x < xMin) xMin = v.x;
	if (v.x > xMax) xMax = v.x;
	if (v.y < yMin) yMin = v.y;
	if (v.y > yMax) yMax = v.y;
}

void AxisABBox::expand(Vector3 v)
{
	if (v.x < xMin) xMin = v.x;
	if (v.x > xMax) xMax = v.x;
	if (v.y < yMin) yMin = v.y;
	if (v.y > yMax) yMax = v.y;
	if (v.y < zMin) zMin = v.z;
	if (v.y > zMax) zMax = v.z;
}

void AxisABBox::expand(AxisABBox aabb)
{
	if (aabb.xMin < xMin) xMin = aabb.xMin;
	if (aabb.xMax > xMax) xMax = aabb.xMax;
	if (aabb.yMin < yMin) yMin = aabb.yMin;
	if (aabb.yMax > yMax) yMax = aabb.yMax;
	if (aabb.zMin < zMin) zMin = aabb.zMin;
	if (aabb.zMax > zMax) zMax = aabb.zMax;
}

bool AxisABBox::collides(float x, float y)
{
	if (x > xMin && x < xMax)
		if (y > yMin && y < yMax)
			return true;
	return false;
}

bool AxisABBox::collides(float x, float y, float z)
{
	if (x > xMin && x < xMax)
		if (y > yMin && y < yMax)
			if(z > zMin && z < zMax)
				return true;
	return false;
}

bool AxisABBox::collides(Vector2 v)
{
	if (v.x > xMin && v.x < xMax)
		if (v.y > yMin && v.y < yMax)
			return true;
	return false;
}

bool AxisABBox::collides(Vector3 v)
{
	if (v.x > xMin && v.x < xMax)
		if (v.y > yMin && v.y < yMax)
				if (v.z > zMin && v.z < zMax)
					return true;
	return false;
}

bool AxisABBox::collides(AxisABBox aabb)
{
	if (aabb.xMax > xMin && aabb.xMin < xMax)
		if (aabb.yMax > yMin && aabb.yMin < yMax)
			if (zMin == std::numeric_limits<float>::max())
				return true;
			else
				if (aabb.zMax > zMin && aabb.zMin < zMax)
					return true;
				
	return false;
}

//bool AxisABBox::collies(RoundThings r){return false;}


