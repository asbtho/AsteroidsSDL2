
#ifndef Game_hpp
#define Game_hpp

#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include "Player.h"
#include "DebugText.h"
#include <iostream>

class Game {
public:
	enum action { 
		UP = 0, 
		LEFT = 1, 
		RIGHT = 2, 
		FIRE = 3,
		ALIVE = 4
	};

	Game();
	~Game();

	void init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);

	void updateShip(const int& action, bool down);
	void handleEvents();
	void update(double delta_time);
	void render();
	void clean();
	void setCurrentFPS(float fps);

	bool running() { return isRunning; }
	
private:
	bool isRunning;
	SDL_Event event;
	SDL_Window* window;
	SDL_Renderer* renderer;
	Player player;
	DebugText debugtext;
	uint32_t current_fps;
};

#endif /* Game_hpp */
