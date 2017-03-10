#pragma once

class Window
{
public:
	Window();
	virtual ~Window();
	virtual void init() = 0;
	virtual void swapBuffers() = 0;
	virtual void destroy() = 0;
};

