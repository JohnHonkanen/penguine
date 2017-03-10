#pragma once
class RenderingStrategy
{
public:
	RenderingStrategy();
	virtual ~RenderingStrategy();

	virtual void renderObject();

};

