/*

Name: Lars Anthony Palm

Student ID: B00294272

I declare that the following code was produced by Lars Anthony Palm, John Christopher Arnon Honkanen as a group assignment for the GED module and that this is our own work.

I am aware of the penalties incurred by submitting in full or in part work that is not our own and that was developed by third parties that are not appropriately acknowledged.

*/

#pragma once

#include <GL\glew.h>
#include <IL\il.h>
#include <iostream>
#include "GraphicsHandler.h"
#include "Window.h"
#include "Transform.h"

using namespace std;
class openGLHandler: public GraphicsHandler
{
private:
	Window *window;
	Transform view;
	Transform projection;
public:
	openGLHandler(Window *window);
	virtual ~openGLHandler();

	void init();
	void start();
	void end();
	void destroy();

};

