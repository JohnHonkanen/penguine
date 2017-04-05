#include "CollisionManager.h"
#include "CollisionAABB.h"

CollisionManager *CollisionManager::manager = nullptr;

CollisionManager::CollisionManager()
{
}


CollisionManager::~CollisionManager()
{
}

CollisionManager * CollisionManager::getManager()
{
	if (CollisionManager::manager == nullptr) {
		CollisionManager::manager == new CollisionManager();
	}

	return CollisionManager::manager;
}

void CollisionManager::addCollisionObjects(CollisionAABB * colObject)
{
	colObjects.push_back(colObject);
}

bool CollisionManager::checkCollision(CollisionAABB a, CollisionAABB b)
{
	vec3 box1Min = a.position - a.halfExtents;
	vec3 box1Max = a.position + a.halfExtents;

	vec3 box2Min = b.position - b.halfExtents;
	vec3 box2Max = b.position + b.halfExtents;

	return (box1Min.x <= box2Max.x && box1Max.x >= box2Min.x) &&
		(box1Min.y <= box2Max.y && box1Max.y >= box2Min.y);
}

void CollisionManager::handleCollision(CollisionAABB * a, CollisionAABB * b)
{
}

void CollisionManager::update()
{
}


