#pragma once
/*pre-definition*/
class Renderer;
/*End of pre-definition*/
class Entity
{
public:
	Entity();
	virtual ~Entity();
	virtual void render(Renderer *r) = 0;
	virtual void update() = 0;
};

