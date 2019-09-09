#ifndef Game_HPP
#define Game_HPP
#include "SDL.h"
#include <stdio.h>
#include <iostream>
#include "SDL_image.h"

class Game {
public:
	Game();
	~Game();

	void init(
		const char *title,
		int xpos,
		int ypos,
		int width,
		int height,
		bool fullscreen
	);
	void handlerEvents();
	void update();
	void render();
	void clean();
	bool running();

private:
	int cnt = 0;
	bool isRunning = false;
	SDL_Window *window;
	SDL_Renderer *renderer;

};

#endif


