#pragma once
#include <iostream>
#include "CollisionStrategy.h"

using namespace std;
class OutputConsoleCollision :
	public CollisionStrategy
{
public:
	OutputConsoleCollision();
	~OutputConsoleCollision();
	void handleCollision(Entity *entity);
};

