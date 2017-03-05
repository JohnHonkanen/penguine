#pragma once
class Movement
{
public:
	Movement();
	virtual ~Movement();
	virtual void init() = 0;
	virtual void update(float ts) = 0;
};

