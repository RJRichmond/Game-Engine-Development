#pragma once
#include <SDL.h>
#include <stdio.h>
#include <string>
#include <vector>
#include <utility>
#include "Game.h"
//#include "EventSystem.h"
#include "ResourceManager.h"

struct SDL_Window;
struct SDL_Renderer;

class GameRenderer 
{
private:
	SDL_Window* GameWindow;
	SDL_Renderer* Renderer;
	//EventSystem* EventManager;
	Game* GameControl;
	ResourceManager* ResourceSystem;
public:
	GameRenderer();
	~GameRenderer();
	void Update(void);
	void Draw(std::vector<std::pair<Bitmap*,std::string>>);
	bool CheckEventManagerForWindowClose();
	void AddSpriteToResourceManager();
};