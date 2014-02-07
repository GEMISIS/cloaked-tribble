#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <vector>

using namespace std;

#include "Gamestate.h"
#include "ObjectManager.h"

#include "Wall.h"
#include "camera.h"

class MainGame : public Gamestate
{
public:
	MainGame(GLFWwindow* window);
	void AddWall();
	~MainGame();
protected:
	void initializeLogic();
	void initializeGraphics();
	bool updateLogic();
	bool updateGraphics();
private:
	Camera camera;
	ObjectManager objectManager;
};

