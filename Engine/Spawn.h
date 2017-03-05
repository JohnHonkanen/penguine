#pragma once
class Spawn
{
public:
	Spawn();
	virtual ~Spawn();
	virtual void init() = 0;
	virtual void update(float ts) = 0;
};

