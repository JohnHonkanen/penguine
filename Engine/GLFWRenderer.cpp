#include "GLFWRenderer.h"

// Window dimensions
const GLuint WIDTH = 800, HEIGHT = 600;

GLFWRenderer::GLFWRenderer()
{

}

GLFWRenderer::~GLFWRenderer()
{

}


void GLFWRenderer::init() {

	glfwInit();

	//Set OpenGL version to (Major, Minor). 
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);

	//Explicitly tell OpenGL not to use Legacy Functionality.
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	//Resize Window Option
	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

	//Create Window
	window = glfwCreateWindow(800, 600, "Penguine", nullptr, nullptr);
	glfwMakeContextCurrent(window);

	// Set this to true so GLEW knows to use a modern approach to retrieving function pointers and extensions
	glewExperimental = GL_TRUE;

	if (window == nullptr) {
		cout << "Failed to create GLFW window" << endl;
		glfwTerminate();
	}

	// Initialize GLEW to setup the OpenGL Function pointers
	glewInit();

	//Initialize il & ilu
	ilInit();
	iluInit();
	ilutRenderer(ILUT_OPENGL);

	// Define the viewport dimensions
	glViewport(0, 0, WIDTH, HEIGHT);

	
	

}

//Draw Buffers using Vertecies
void GLFWRenderer::drawVerts() {

	// Build and compile our shader program
	Shader program("minimal.vert", "minimal.frag");
	program.Use();

	GLfloat vertices[] = {
		// Positions          // Colors           // Texture Coords
		0.5f,  0.5f, 0.0f,   1.0f, 0.0f, 0.0f,   1.0f, 1.0f,   // Top Right
		0.5f, -0.5f, 0.0f,   0.0f, 1.0f, 0.0f,   1.0f, 0.0f,   // Bottom Right
		-0.5f, -0.5f, 0.0f,   0.0f, 0.0f, 1.0f,   0.0f, 0.0f,   // Bottom Left
		-0.5f,  0.5f, 0.0f,   1.0f, 1.0f, 0.0f,   0.0f, 1.0f    // Top Left 
	};

	GLuint indices[] = {  // Note that we start from 0!
		0, 1, 3, // First Triangle
		1, 2, 3  // Second Triangle
	};
	//VBO = Vertex Buffer Object
	//VAO = Vertex Array Object
	//EBO = Element Buffer Object - EBO is a buffer, just like the vertex buffer object, that stores indices that OpenGL uses to
	//decide what vertices to draw. This is done by storing only the unique vertices and then 
	//specify the order at which we want to draw these vertices in. 
	//Example: Use 4 vertices to draw a square using 2 triangles instead of 6. 

	GLuint VBO, VAO, EBO;
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);
	glGenBuffers(1, &EBO);

	glBindVertexArray(VAO);

	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

	// Position attribute
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)0);
	glEnableVertexAttribArray(0);
	// Color attribute
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)(3 * sizeof(GLfloat)));
	glEnableVertexAttribArray(1);
	// TexCoord attribute
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)(6 * sizeof(GLfloat)));
	glEnableVertexAttribArray(2);

	glBindVertexArray(0); // Unbind VAO

	//Properly de-allocate all resources once they've outlived their purpose
	//A VAO stores the glBindBuffer calls when the target is GL_ELEMENT_ARRAY_BUFFER. This means it stores its unbind calls
	//so make sure you don't unbind the element array buffer before unbinding your VAO, otherwise it doesn't have an EBO
	//configured. 
	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &VBO);
	glDeleteBuffers(1, &EBO);

}

//Create Texture

void GLFWRenderer::loadTextures() {

	ILuint width;
	ILuint height;

	// Load image, create texture and generate mipmaps

	// ====================
	// Texture 1
	// ====================
	
	ILuint container;
	ilGenImages(1, &container);
	ilBindImage(container);
	if (ilLoadImage((const ILstring)"container.jpg")) {
		//cout << "Container loaded! " << endl;
	}
	else {
		cout << ilGetError() << endl;
		//cout << "Failed Load Image 1" << endl;
	}
	width = ilGetInteger(IL_IMAGE_WIDTH);
	height = ilGetInteger(IL_IMAGE_HEIGHT);

	//See http://www-f9.ijs.si/~matevz/docs/DevIL/il/f00059.htm
	ilTexImage(width, height, 0, 3, IL_RGB, IL_UNSIGNED_BYTE, NULL);

	// Load and create a texture 
	GLuint texture1;
	//glGenTextures() takes as input how many textures we want to generate and stores them in a
	//GLuint array given as its second argument (in our case just a single GLuint)*/
	glGenTextures(1, &texture1);

	//We need to bind it so any subsequent texture commands will configure the currently bound texture:
	glBindTexture(GL_TEXTURE_2D, texture1);
	//Generates and binds texture via glGenTextures and glBindTexture
	//texture1 = ilutGLBindTexImage();
	// All upcoming GL_TEXTURE_2D operations now have effect on this texture object
	// Set the texture wrapping parameters
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);	// Set texture wrapping to GL_REPEAT (usually basic wrapping method)
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	// Set texture filtering parameters
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	//ilutGLTexImage();

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, ilGetData());
	//Put mipmap here
	glGenerateMipmap(GL_TEXTURE_2D);
	ilDeleteImages(1, &container); // Deletes image
	glBindTexture(GL_TEXTURE_2D, 0); // Unbind texture when done (set second parameter to 0), so we won't accidentily mess up our texture.

	// ===================
	// Texture 2
	// ===================
	ILuint awesomeFace;
	ilGenImages(1, &awesomeFace);
	ilBindImage(awesomeFace);
	if (ilLoadImage((const ILstring)"awesomeFace.png")) {
		//cout << "AwesomeFace loaded! " << endl;
	}
	else {
		cout << ilGetError() << endl;
		//cout << "Failed Load Image 2" << endl;
	}

	width = ilGetInteger(IL_IMAGE_WIDTH);
	height = ilGetInteger(IL_IMAGE_HEIGHT);

	// Load and create a texture 
	ilTexImage(width, height, 0, 3, IL_RGB, IL_UNSIGNED_BYTE, NULL);

	GLuint texture2;
	texture2 = ilutGLBindTexImage();
	
	// All upcoming GL_TEXTURE_2D operations now have effect on this texture object
	// Set the texture wrapping parameters
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);	// Set texture wrapping to GL_REPEAT (usually basic wrapping method)
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	// Set texture filtering parameters
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	/*
	// Set our texture parameters
	iluImageParameter(GL_TEXTURE_WRAP_S, GL_REPEAT);
	iluImageParameter(GL_TEXTURE_WRAP_T, GL_REPEAT);
	// Set texture filtering
	iluImageParameter(GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	iluImageParameter(GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	*/
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, ilGetData());
	//Put mipmap here
	glGenerateMipmap(GL_TEXTURE_2D);
	ilDeleteImages(1, &awesomeFace); //Deletes Image
	glBindTexture(GL_TEXTURE_2D, 0); //Unbinds Texture
}

void GLFWRenderer::start() {

	//Rendering commands go here
	glClearColor(0.2f, 0.3f, 0.3f, 1.0f); //Color to clear with
	glClear(GL_COLOR_BUFFER_BIT); //Clears the screen
	glLoadIdentity();
	glOrtho(-1000, 1000, -1000, 1000, 0.0f, 1.0f); // Reference system of our simulation

}

void GLFWRenderer::end() {
	//Swap the buffers
	glfwSwapBuffers(window);
}

void GLFWRenderer::destroy() {
	//Terminate & Clean up resources before application exit
	glfwTerminate();
}

void GLFWRenderer::renderSprite(std::string spriteLocation, Transform transform) {

}
