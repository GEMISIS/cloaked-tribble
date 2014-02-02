#include <GL/glew.h>
#include <vector>

using namespace std;

#include "Gamestate.h"
#include "Object.h"

class MainGame : public Gamestate
{
public:
	MainGame();
	void AddWall();
	~MainGame();
protected:
	void initializeLogic();
	void initializeGraphics();
	bool updateLogic();
	bool updateGraphics();
private:
	float rotation;
	vector<Object> objects;
};

