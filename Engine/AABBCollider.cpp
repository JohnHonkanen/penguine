#include "AABBCollider.h"



AABBCollider::AABBCollider()
{
}


AABBCollider::~AABBCollider()
{
}

bool AABBCollider::checkCollision(Collider * other)
{
	AABBCollider *cOther = dynamic_cast<AABBCollider*>(other);
	if (cOther == nullptr) {
		return false;
	}

	vec3 box1Min = position - halfExtents;
	vec3 box1Max = position + halfExtents;

	vec3 box2Min = cOther->position - cOther->halfExtents;
	vec3 box2Max = cOther->position + cOther->halfExtents;

	return (box1Min.x <= box2Max.x && box1Max.x >= box2Min.x) &&
		(box1Min.y <= box2Max.y && box1Max.y >= box2Min.y) &&
		(box1Min.z <= box2Max.z && box1Max.z >= box2Min.z);

}
