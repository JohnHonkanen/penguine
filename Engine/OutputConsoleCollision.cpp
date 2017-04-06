#include "OutputConsoleCollision.h"
#include "Entity.h"


OutputConsoleCollision::OutputConsoleCollision()
{
}


OutputConsoleCollision::~OutputConsoleCollision()
{
}

void OutputConsoleCollision::handleCollision(Entity *entity)
{
	printf("We have collided \n");
	entity->getCollider()->collided = false;
}

CollisionStrategy * OutputConsoleCollision::instantiate()
{
	return new OutputConsoleCollision();
}
