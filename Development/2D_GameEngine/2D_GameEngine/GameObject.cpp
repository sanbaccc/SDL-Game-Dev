#include "GameObject.hpp"
#include "TextureManager.hpp"

GameObject::GameObject(const char *textureSheet, SDL_Renderer *ren, int x, int y) {
	renderer = ren;
	objTexture = TextureManager::loadTexture(textureSheet, renderer);

	xpos = x;
	ypos = y;
}

void GameObject::Update() {
	xpos++;
	ypos++;

	srcR.h = 64;
	srcR.w = 64;
	srcR.x = 0;
	srcR.y = 0;

	desR.x = xpos;
	desR.y = ypos;
	desR.h = srcR.h * 2;
	desR.w = srcR.w * 2;
}

void GameObject::Render() {
	SDL_RenderCopy(renderer, objTexture, &srcR, &desR);
}