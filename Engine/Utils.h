// Marco Gilardi UWS
#pragma once

#include <glm\glm.hpp>

class CollisionAABB;

using namespace glm;
class Utils
{
public:
	Utils();
	~Utils();

	static const vec3 up;
	static const vec3 down;
	static const vec3 left;
	static const vec3 right;

	static char computePointMask(const vec3& P, const CollisionAABB* const aabb);
	static bool pointIsAbovePlane(const vec3& P, const vec3& n, float c);
	static vec3 getAABBFaceNormal(const vec3& P, const CollisionAABB* const aabb);
};

