#pragma once
#include <glm\glm.hpp>

#include <vector>
#include "CollisionManager.h"

using namespace std;
using namespace glm;

struct ContactManifold {
	vector<vec3> contacts;
};

class CollisionObjects
{
public:
	CollisionObjects();
	virtual ~CollisionObjects();


};

