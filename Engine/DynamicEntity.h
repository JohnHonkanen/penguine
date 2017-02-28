#pragma once
#include "Entity.h"
#include "Transform.h"
#include "Rigidbody.h"
#include "Renderable.h"
class DynamicEntity :
	public Entity
{
public:
	DynamicEntity();
	DynamicEntity(Renderable *r);
	virtual ~DynamicEntity();
	void render(Renderer *r);
	void update();
	Transform transform;
	Rigidbody rigidbody;
	Renderable *renderable;
};

