#pragma once
#include "Entity.h"
#include "Transform.h"
#include "Rigidbody.h"
#include "AbstractRenderable.h"
class DynamicEntity :
	public Entity
{
public:
	DynamicEntity();
	virtual ~DynamicEntity();
	void render(Renderer *r);
	void update();
	Transform transform;
	Rigidbody rigidbody;
	AbstractRenderable *renderable;
};

