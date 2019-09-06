/*
Game.cpp
Author: "Let's Make Games"
Source: Youtube
user:Yanchun Wang

Description:
	Creates a game blank window.
*/

#include "Game.hpp"
Game::Game(){

}

Game::~Game(){

}

void Game::init(
	const char *title,
	int xpos,
	int ypos,
	int width,
	int height,
	bool fullscreen
){
	//Determine the window is fullscreen
	int flag = 0;
	if (fullscreen) flag = SDL_WINDOW_FULLSCREEN;

	//initialize SDL
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
		std::cout << "Subsystem Initialized..." << std::endl;

		//Create a window
		window = SDL_CreateWindow(
			title,
			xpos,
			ypos,
			width,
			height,
			flag
		);

		//check errors
		if (window) {
			std::cout << "Window is created..." << std::endl;
		}

		//render the window
		renderer = SDL_CreateRenderer(window, -1, 0);

		//Set the default colo for rendering
		if (renderer) {
			SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
			std::cout << "Renderer is created..." << std::endl;
		}

		isRunning = true;
	}else {
		isRunning = false;
	}
}

void Game::handlerEvents() {
	//create event handler
	SDL_Event event;
	SDL_PollEvent(&event);

	//Enable quit if user close the window
	switch (event.type) {
		case SDL_QUIT:
			isRunning = false;
		default:
			break;
	}
}

void Game::update() {

}

void Game::render() {
	//clear render buffer
	SDL_RenderClear(renderer);
	//display renderer
	SDL_RenderPresent(renderer);
}

void Game::clean() {
	//Clear all SDL objects
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	std::cout << "Game Cleaned..." << std::endl;
}

bool Game::running() {
	return isRunning;
}