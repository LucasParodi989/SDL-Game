#include "Game.h"
#include "TextureManager.h"
#include "GameObject.h"
#include "Map.h"
#include "Player.h"

Player* player;
GameObject* enemy;
Map* map;
int cont = 0;







SDL_Renderer* Game::renderer = nullptr;
SDL_Event Game::event;
/*SDL_Texture *playerTex;
SDL_Rect src, destR;*/
Game::Game()
{}

Game::~Game()
{}

void Game::init(const char* title, int width, int height, bool fullscreen)
{
	int flags = 0;
	
	if (fullscreen)
	{
		flags = SDL_WINDOW_FULLSCREEN;
	}

	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, flags);
		renderer = SDL_CreateRenderer(window, -1, 0);
		if (renderer)
		{
			SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
		}

		isRunning = true;
	}
	player = new Player("media/player.png",0,0);
	enemy = new GameObject("media/enemy.png", 50, 50);
	map = new Map();
	/*SDL_Surface * tmpSurface = IMG_Load("media/player.png");
	playerTex = SDL_CreateTextureFromSurface(renderer, tmpSurface);
	SDL_FreeSurface(tmpSurface);
	playerTex = TextureManager::LoadTexture("media/player.png",renderer);*/
}

void Game::handleEvents()
{
	

	SDL_PollEvent(&event);

	switch (event.type)
	{
	case SDL_QUIT :
		isRunning = false;
		break;
	default:
		break;
	}
}

void Game::update()
{


	if (Game::event.key.keysym.sym == SDLK_c) {

		std::ifstream mapafile("mapa.txt");
		char cuadrados[900];
		char cuadrado;
		int i = 0;
		while (!mapafile.eof()) {
			mapafile >> cuadrado;
			cuadrados[i] = cuadrado;
			i++;
		}


		/*int sig = 0;
		for (int row = 0; row < 20; row++) {
			for (int columm = 0; columm < 25; columm++) {
				map[row][columm] = cuadrados[i];
				sig++;

			}
		}
		*/
		map->LoadMap(cuadrados);

	}


	cont++;
	
	
	player->Move(cont);
	player->Update();
	enemy->Update();
}

void Game::render()
{
	SDL_RenderClear(renderer);
	map->DrawMap();
	map->saveMap();
	map->LoadMapFile();
	player->Render();

	enemy->Render();
	SDL_RenderPresent(renderer);
}

void Game::clean()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
}