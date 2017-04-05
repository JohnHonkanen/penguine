#include "CollisionManager.h"
#include "CollisionAABB.h"
#include "Utils.h"

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

void CollisionManager::addCollisionObjects(CollisionObjects * colObject)
{
	colObjects.push_back(colObject);
}

bool CollisionManager::checkCollision(CollisionObjects *a, CollisionObjects *b)
{
	bool collided = false;

	if (dynamic_cast<CollisionAABB*>(a) != nullptr && dynamic_cast<CollisionAABB*>(b) != nullptr) {
		collided = AABBCollision(dynamic_cast<CollisionAABB*>(a), dynamic_cast<CollisionAABB*>(b));
	}

	return collided;
}

void CollisionManager::handleCollision(CollisionObjects * a, CollisionObjects * b)
{
	if (dynamic_cast<CollisionAABB*>(a) != nullptr && dynamic_cast<CollisionAABB*>(b) != nullptr) {
		handleAABBCollision(dynamic_cast<CollisionAABB*>(a), dynamic_cast<CollisionAABB*>(b));
	}
	
}

void CollisionManager::handleAABBCollision(CollisionAABB * a, CollisionAABB * b)
{
	a->colliding = true;
	b->colliding = true;

	vec3 box1Min = a->position - a->halfExtents;
	vec3 box1Max = a->position + a->halfExtents;

	vec3 box2Min = b->position - b->halfExtents;
	vec3 box2Max = b->position + b->halfExtents;

	vec3 normal = Utils::getAABBFaceNormal(a->position, b);

	a->contactNormal = normal;
	b->contactNormal = -normal;
	vec3 norm = normal;
}

bool CollisionManager::AABBCollision(CollisionAABB *a, CollisionAABB *b)
{
	vec3 box1Min = a->position - a->halfExtents;
	vec3 box1Max = a->position + a->halfExtents;

	vec3 box2Min = b->position - b->halfExtents;
	vec3 box2Max = b->position + b->halfExtents;

	return (box1Min.x <= box2Max.x && box1Max.x >= box2Min.x) &&
		(box1Min.y <= box2Max.y && box1Max.y >= box2Min.y);
}

void CollisionManager::update()
{
	for (int i = 0; i < colObjects.size(); i++) {
		CollisionAABB *iObjs = colObjects.at(i);
		//GameObject *object = iObjs->gameObject;

		iObjs->colliding = false;
		//iObjs->position = vec3(object->transform.physics[3]) + iObjs->offset;

	}

	//To Be filled in
	for (int i = 0; i < colObjects.size(); i++) {
		CollisionAABB *iObjs = colObjects.at(i);
		for (int k = i + 1; k < colObjects.size(); k++) {
			CollisionAABB *kObjs = colObjects.at(k);

			if (checkCollision(*iObjs, *kObjs))
				handleCollision(iObjs, kObjs);
		}
	}
}


