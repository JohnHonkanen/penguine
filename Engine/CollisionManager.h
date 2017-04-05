#pragma once

#include <glm\glm.hpp>
#include <vector>

using namespace std;
using namespace glm;


class CollisionAABB;
class CollisionManager
{
private:
	vector<CollisionObjects*> colObjects;
	static CollisionManager *manager;
public:
	CollisionManager();
	~CollisionManager();

	static CollisionManager *getManager();
	void addCollisionObjects(CollisionObjects *colObject);
	bool checkCollision(CollisionObjects *a, CollisionObjects *b);
	bool AABBCollision(CollisionAABB *a, CollisionAABB *b);
	void handleCollision(CollisionObjects *a, CollisionObjects *b);
	void handleAABBCollision(CollisionAABB *a, CollisionAABB *b);
	void update();
};

