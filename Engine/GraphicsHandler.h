#pragma once
#include <string>
#include "Transform.h"


class GraphicsHandler // Renderer
{
public:
	GraphicsHandler();
	virtual ~GraphicsHandler();
	virtual void init() = 0;
	virtual void start() = 0;
	virtual void end() = 0;
	virtual void destroy() = 0;
	virtual void draw() = 0;
};

