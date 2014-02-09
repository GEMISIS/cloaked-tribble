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
	const GLFWvidmode * mode = glfwGetVideoMode(glfwGetPrimaryMonitor());

	window = glfwCreateWindow(mode->width, mode->height, "cloaked-tribble", glfwGetPrimaryMonitor(), NULL);
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

	printf("Version: %s\n\n", (char*)glGetString(GL_VERSION));

	while(!glfwWindowShouldClose(window))
	{
		glfwGetFramebufferSize(window, &width, &height);

		if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		{
			glfwDestroyWindow(window);
			break;
		}

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