/*

Name: Lars Anthony Palm

Student ID: B00294272

I declare that the following code was produced by Lars Anthony Palm, John Christopher Arnon Honkanen as a group assignment for the GED module and that this is our own work.

I am aware of the penalties incurred by submitting in full or in part work that is not our own and that was developed by third parties that are not appropriately acknowledged.

*/

#include "AABBCollider.h"



AABBCollider::AABBCollider(vec3 in_halfExtents)
{
	halfExtents = in_halfExtents;
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

Collider * AABBCollider::instantiate()
{
	return new AABBCollider(halfExtents);
}
