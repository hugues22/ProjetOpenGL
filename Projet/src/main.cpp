//Includes necessaires
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <signal.h>

//Glew
#include <GL/glew.h>

//GLFW
#include <GLFW/glfw3.h>

//GLM
#include <glm/glm.hpp>
#include <glm\gtc\matrix_transform.hpp>

//.h
#include "Cube.h"
#include "Renderer.h"
#include "VertexBuffer.h"
#include "IndexBuffer.h"
#include "VertexArray.h"
#include "Shader.h"
#include "VertexBufferLayout.h"
#include "Texture.h"

using namespace glm;

#define WIDTH 960 
#define HEIGHT 540

int main(void){
	if(!glfwInit())
		return -1;
	
	GLFWwindow* window;
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	// Create a wubdower mode window and its OpenGL context 
	window = glfwCreateWindow(WIDTH, HEIGHT, "Hello World", NULL, NULL);
	if(!window){
		glfwTerminate();
		return -1;
	}

	// Make the window's context current
	glfwMakeContextCurrent(window);

	glfwSwapInterval(1);

	if (glewInit() != GLEW_OK)
		return -1;
		//std::cout << "Error!" << std::endl;

	std::cout << glGetString(GL_VERSION) << std::endl;
	{
		/*float positions[] = {
			-0.5f, -0.5f, 0.0f, 0.0f, 0.0f, // 0
			 0.5f, -0.5f, 0.0f, 1.0f, 0.0f, // 1
			 0.5f,  0.5f, 0.0f, 1.0f, 1.0f, // 2
			-0.5f,  0.5f, 0.0f, 0.0f, 1.0f  // 3
		};*/


		float positions[] = {
			-1.0f,-1.0f,-1.0f, //0.0f, 0.0f,  // 0
			-1.0f,-1.0f, 1.0f, //1.0f, 0.0f,  // 1 
			-1.0f, 1.0f, 1.0f, //1.0f, 1.0f,  // 2
			 1.0f, 1.0f,-1.0f, //0.0f, 1.0f,  // 3
			-1.0f, 1.0f,-1.0f, //0.0f, 0.0f,  // 4
			 1.0f,-1.0f, 1.0f, //1.0f, 0.0f,  // 5
			 1.0f,-1.0f,-1.0f, //1.0f, 1.0f,  // 6
			 1.0f, 1.0f, 1.0f, //0.0f, 1.0f   // 7
		};		

		float positions2[] = {
			-5.0f,-5.0f,-5.0f, //0.0f, 0.0f,  // 0
			-5.0f,-5.0f,-3.0f, //1.0f, 0.0f,  // 1 
			-5.0f,-3.0f,-3.0f, //1.0f, 1.0f,  // 2
			-3.0f,-3.0f,-5.0f, //0.0f, 1.0f,  // 3
			-5.0f,-3.0f,-5.0f, //0.0f, 0.0f,  // 4
			-3.0f,-5.0f,-3.0f, //1.0f, 0.0f,  // 5
			-3.0f,-5.0f,-5.0f, //1.0f, 1.0f,  // 6
			-3.0f,-3.0f,-3.0f, //0.0f, 1.0f   // 7
		};

		unsigned int indices[] = {
			0, 1, 2,
			3, 0, 4,
			5, 0, 6,
			3, 6, 0,
			0, 2, 4,
			5, 1, 0,
			2, 1, 5,
			7, 6, 3,
			6, 7, 5,
			7, 3, 4,
			7, 4, 2,
			7, 2, 5
		};


		GLCall(glEnable(GL_BLEND));
		GLCall(glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA));



		Cube cube(positions, indices, "res/shaders/Basic.shader");
		Cube cube2(positions2, indices, "res/shaders/Basic.shader");
		
		Renderer renderer(*window, WIDTH, HEIGHT);
		
		glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
		
		while (glfwGetKey(window, GLFW_KEY_ESCAPE) != GLFW_PRESS && glfwWindowShouldClose(window) == 0)
		{
			
			/* Render here */
			renderer.Clear();

			renderer.Draw(cube);
			renderer.Draw(cube2);

			/* Swap frint and back buffers */
			glfwSwapBuffers(window);

			/* Poll for and process envents */
			glfwPollEvents();
		}
	}


	glfwTerminate();
	return 0;
}

