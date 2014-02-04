#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "MainGame.h"

Gamestate* current_state;

int main()
{
	GLFWwindow* window;
	if(!glfwInit())
	{
		return -1;
	}

	glfwWindowHint(GLFW_SAMPLES, 4);
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

	current_state = new MainGame(window);
	current_state->Init();

	int width, height;

	while(!glfwWindowShouldClose(window))
	{
		glfwGetFramebufferSize(window, &width, &height);

		glViewport(0, 0, width, height);
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		gluPerspective(60, float(width) / height, 0.1f, 100);
		glMatrixMode(GL_MODELVIEW);

		current_state->Update();

		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glfwTerminate();

	return 0;
}