#pragma once
#include "Game.h"
#include "TextureManager.h"
class GameObject {
public:
	GameObject(const char* texturesheet,int x,int y) {
		
		objTexture = TextureManager::LoadTexture(texturesheet);
		xpos = x;
		ypos = y;
		
	};
	~GameObject() {
	
	};
	void Update() {
		xpos++;
		ypos++;
		srcRect.h = 75;
		srcRect.w = 50;
		srcRect.x = 0;
		srcRect.y = 0;
		destRect.x = xpos;
		destRect.y = ypos;
		destRect.w = srcRect.w ;
		destRect.h = srcRect.h ;
	};
	void Render() {
		SDL_RenderCopy(Game::renderer, objTexture, &srcRect, &destRect);
	};
private:
	int xpos;
	int ypos;
	
	SDL_Texture* objTexture;
	SDL_Rect srcRect, destRect;
	

};