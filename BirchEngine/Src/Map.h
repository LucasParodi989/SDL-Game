#pragma once

#include "Game.h"
#include "TextureManager.h"
#include <cstdlib>
#include <ctime>
#include <fstream>

class Map
{
public:
	
	
	void generateMap() {
		for (int row = 0; row < 20; row++) {
			for (int columm = 0; columm < 25; columm++) {
				
				map[row][columm] = rand() % 3+48;
				
			}
		}

	}
	Map() {
		srand(time(NULL));
		dirt = TextureManager::LoadTexture("media/dirt.png");
		grass = TextureManager::LoadTexture("media/grass.png");
		water = TextureManager::LoadTexture("media/water.png");
		//LoadMap(lvl1);
		generateMap();
		src.x = src.y = 0;
		src.w = dest.w = 32;
		src.h = dest.h= 32;
		dest.x = dest.y = 0;
	};
	~Map() {};
	void LoadMap(char cuadrados[]) {
		int i=0;
		for (int row = 0; row < 20; row++) {
			for (int columm = 0; columm < 25; columm++) {
				map[row][columm] = cuadrados[i];
				i++;
			}
		}
	}
	void LoadMapFile() {
	
	}
	void DrawMap() {
		int type = 0;

		for (int row = 0; row < 20; row++) {
			for (int columm = 0; columm < 25; columm++) {
				type = map[row][columm];
				dest.x = columm * 32;
				dest.y = row * 32;
				switch (type) {
				case '0':
					TextureManager::Draw(water, src, dest);
					break;
				case '1':
					TextureManager::Draw(grass, src, dest);
					break;
				case '2':
					TextureManager::Draw(dirt, src, dest);
					break;
				}
			}
		}
	}
	void saveMap() {
		if (Game::event.key.keysym.sym == SDLK_s) {
		std::ofstream  mapa("mapa.txt");

		for (int row = 0; row < 20; row++) {
			for (int columm = 0; columm < 25; columm++) {
				mapa << map[row][columm];
			}
		}
	}
		num++;
	}
	;

private:
	SDL_Rect src, dest;
	SDL_Texture* dirt;
	SDL_Texture* grass;
	SDL_Texture* water;
	char map[20][25];
	int num = 1;

};