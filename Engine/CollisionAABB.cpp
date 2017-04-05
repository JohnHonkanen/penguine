#include "CollisionAABB.h"



CollisionAABB::CollisionAABB()
{
}

CollisionAABB::CollisionAABB(vec3 halfExtents, bool isStatic, vec3 offset)
{
	CollisionManager *manager = CollisionManager::getManager();
	CollisionAABB::halfExtents = halfExtents;
	CollisionAABB::isStatic = isStatic;
	CollisionAABB::offset = offset;
	position = vec3(0);

	manager->addCollisionObjects(this);
}


CollisionAABB::~CollisionAABB()
{
}
