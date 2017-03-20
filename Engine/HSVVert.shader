#version 330 core
layout(location = 0) in vec3 position;
layout(location = 1) in vec3 color;
layout(location = 2) in vec2 uv;

//out vec3 ourColor;
out vec2 UV;

uniform mat4 MVP;

void main()
{
	gl_Position = MVP * vec4(position, 1.0f);
	//ourColor = color;
	// We swap the y-axis by substracing our coordinates from 1. This is done because most images have the top y-axis inversed with OpenGL's top y-axis.
	UV = vec2(uv.x, 1.0 - uv.y);
}