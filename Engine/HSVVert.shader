//Name: Lars Anthony Palm

//Student ID: B00294272

//I declare that the following code was produced by Lars Anthony Palm, John Christopher Arnon Honkanen as a group assignment for the GED module and that this is our own work.

//I am aware of the penalties incurred by submitting in full or in part work that is not our own and that was developed by third parties that are not appropriately acknowledged.


#version 330 core
layout(location = 0) in vec3 position;
layout(location = 1) in vec3 color;
layout(location = 2) in vec2 uv;



out vec2 UV;

uniform mat4 MVP;

void main()
{
	gl_Position = MVP * vec4(position, 1.0f);
	//ourColor = color;
	// We swap the y-axis by substracing our coordinates from 1. This is done because most images have the top y-axis inversed with OpenGL's top y-axis.
	UV = vec2(uv.x, 1.0 - uv.y);
}