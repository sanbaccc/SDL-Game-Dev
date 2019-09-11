#pragma once
#include "Game.hpp"

class GameObject {
public:
	GameObject(const char* textureSheet, SDL_Renderer *ren, int x, int y);
	void Update();
	void Render();
	~GameObject();

private:
	int xpos;
	int ypos;
	SDL_Texture *objTexture;
	SDL_Rect srcR, desR;
	SDL_Renderer *renderer;
};