#pragma once
class Entity;
class Spawn
{
public:
	Spawn();
	virtual ~Spawn();
	virtual void init() = 0;
	virtual void update(float ts) = 0;
	virtual void setEntity(Entity *entity) = 0;
};

