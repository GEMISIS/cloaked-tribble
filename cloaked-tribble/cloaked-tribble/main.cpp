#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "Wall.h"

Wall wall;

void initObjects()
{
	wall.Init();
}

void updateObjects()
{
	wall.Update();
}

void drawObjects()
{
	wall.Draw();
}

int main()
{
	GLFWwindow* window;
	if(!glfwInit())
	{
		return -1;
	}

	window = glfwCreateWindow(640, 480, "cloaked-tribble", NULL, NULL);
	if(!window)
	{
		glfwTerminate();
		return -1;
	}

	glfwMakeContextCurrent(window);

	if(glewInit() != GLEW_OK)
	{
		glfwTerminate();
		return -1;
	}

	initObjects();

	while(!glfwWindowShouldClose(window))
	{
		updateObjects();
		drawObjects();

		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glfwTerminate();

	return 0;
}