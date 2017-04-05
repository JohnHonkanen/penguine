#pragma once

#include <glm\glm.hpp>
#include <vector>

using namespace std;
using namespace glm;


class CollisionAABB;
class CollisionManager
{
private:
	vector<CollisionAABB*> colObjects;
	static CollisionManager *manager;
public:
	CollisionManager();
	~CollisionManager();

	static CollisionManager *getManager();
	void addCollisionObjects(CollisionAABB *colObject);
	bool checkCollision(CollisionAABB a, CollisionAABB b);
	void handleCollision(CollisionAABB *a, CollisionAABB *b);
	void update();
};

