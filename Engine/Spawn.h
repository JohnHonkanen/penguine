#pragma once
class Entity;
class Spawn
{
protected:
	Entity *entity;
public:
	Spawn();
	virtual ~Spawn();
	virtual void init() = 0;
	virtual void update(float ts) = 0;
	virtual void setEntity(Entity *entity);
};

