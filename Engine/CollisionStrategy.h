#pragma once
class Entity;
class CollisionStrategy
{
public:
	CollisionStrategy();
	virtual ~CollisionStrategy();
	virtual CollisionStrategy *instantiate() = 0;
	virtual void handleCollision(Entity *entity) = 0;
};

