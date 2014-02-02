// Check if the header has been defined already.
#ifndef _GAME_STATE_H_
// If not, define it.
#define _GAME_STATE_H_

/**
  * The base game state class.  Game states should extend this class
  * to help transition between menus, gameplay, etc.
  */
class Gamestate
{
public:
	/**
	  * A boolean indicating whether the current state is paused or not. 
	  */
	bool paused;
	/**
	  * The default constructor.
	  */
	Gamestate()
	{
	};
	/**
	  * The initialize method.  Calls the other initialize methods for logic, graphics
	  * and sound.
	  */
	virtual void Init()
	{
		this->initializeLogic();
		this->initializeGraphics();
		this->initializeSound();
	};
	/**
	 * Update all of the game states properties.
	 */
	virtual void Update()
	{
		this->updateLogic();
		this->updateSound();
		this->updateGraphics();
	};
	/**
	  * The default deconstructor for the class.
	  */
	virtual ~Gamestate()
	{
	};
protected:
	/**
	  * Initializes the logic for the game.  Needs to be
	  * overridden.
	  */
	virtual void initializeLogic()
	{
	};
	/**
	  * Initializes the graphics for the game.  Needs to be
	  * overridden.
	  */
	virtual void initializeGraphics()
	{
	};
	/**
	  * Initializes the sound for the game.  Needs to be
	  * overridden.
	  */
	virtual void initializeSound()
	{
	};
	/**
	  * The logic update method.  Updates the game's logic.
	  * Needs to be overridden!
	  */
	virtual bool updateLogic()
	{
		return false;
	};
	/**
	  * The graphics update method.  Updates the game's graphcs.
	  * Needs to be overridden!
	  */
	virtual bool updateGraphics()
	{
		return false;
	}
	/**
	  * The sound update method.  Updates the game's sounds.
	  * Needs to be overridden!
	  */
	virtual bool updateSound()
	{
		return false;
	}
};

/**
 * The current game state.
 */
extern Gamestate* current_state;

#endif