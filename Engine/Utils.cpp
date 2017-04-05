// (c) Marco Gilardi, 2017
//Converted implementation to fit our CollisionAABB

#include <limits>

#include "Utils.h"
#include "CollisionAABB.h"


const vec3 Utils::up = vec3(0, 1, 0);
const vec3 Utils::down = vec3(0, -1, 0);
const vec3 Utils::right = vec3(1, 0, 0);
const vec3 Utils::left = vec3(-1, 0, 0);

Utils::Utils()
{
}


Utils::~Utils()
{
}
//Taking in CollisionAABB instead of AABB object
char Utils::computePointMask(const vec3 & P, const CollisionAABB * const aabb)
{
	vec3 center = aabb->position;
	vec3 radii = aabb->halfExtents;

	char mask = 0;
	if (pointIsAbovePlane(P, Utils::right, -center.x - radii.x))
	{
		//cout << "X" << endl;
		mask |= 1;// +x
	}
	if (pointIsAbovePlane(P, Utils::left, center.x - radii.x))
	{
		//cout << "-X" << endl;
		mask |= 2;	// -x
	}
	if (pointIsAbovePlane(P, Utils::up, -center.y - radii.y))
	{
		//cout << "Y" << endl;
		mask |= 4;	// +y
	}
	if (pointIsAbovePlane(P, Utils::down, center.y - radii.y))
	{
		//cout << "-Y" << endl;
		mask |= 8;	// -y
	}

	return mask;
}

bool Utils::pointIsAbovePlane(const vec3 & P, const vec3 & n, float c)
{
	return dot(n, P) + c > FLT_EPSILON;
}
//Taking in CollisionAABB instead of AABB object
vec3 Utils::getAABBFaceNormal(const vec3 & P, const CollisionAABB * const aabb)
{
	char mask = Utils::computePointMask(P, aabb);
	vec3 normal = vec3(0);
	if ((mask & 1) == 1)	// +x
	{
		normal += Utils::right;
	}
	if ((mask & 2) == 2)	// -x
	{
		normal += Utils::left;
	}
	if ((mask & 4) == 4)	// +y
	{
		normal += Utils::up;
	}
	if ((mask & 8) == 8)	// -y
	{
		normal += Utils::down;
	}

	return normalize(normal);
}
