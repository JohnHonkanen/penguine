#include "CollisionObjects.h"



CollisionObjects::CollisionObjects()
{
}

CollisionObjects::CollisionObjects(vec3 halfExtents, bool isStatic, vec3 offset)
{
	CollisionManager *manager = CollisionManager::getManager();
	CollisionObjects::halfExtents = halfExtents;
	CollisionObjects::isStatic = isStatic;
	CollisionObjects::offset = offset;
	position = vec3(0);

	manager->addCollisionObjects(this);
}


CollisionObjects::~CollisionObjects()
{
}
