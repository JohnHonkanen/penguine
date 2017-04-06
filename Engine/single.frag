//Name: Lars Anthony Palm

//Student ID: B00294272

//I declare that the following code was produced by Lars Anthony Palm, John Christopher Arnon Honkanen as a group assignment for the GED module and that this is our own work.

//I am aware of the penalties incurred by submitting in full or in part work that is not our own and that was developed by third parties that are not appropriately acknowledged.


#version 330 core
//in vec3 ourColor;
in vec2 TexCoord;

out vec4 color;

uniform sampler2D ourTexture;

void main()
{
    color = texture(ourTexture, TexCoord); // * vec4(ourColor, 1.0f);
	// color = vec4(1.0f,0.0f,0.0f, 1.0f);
}