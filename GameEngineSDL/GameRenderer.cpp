#include "GameRenderer.h"


GameRenderer::GameRenderer()
{
	GameWindow = nullptr;
	Renderer = nullptr;

	SDL_Init(SDL_INIT_VIDEO);

	GameWindow = SDL_CreateWindow("Display Window", 250, 50, 800, 600, 0);

	Renderer = SDL_CreateRenderer(GameWindow, -1, 0);

	//EventManager = new EventSystem();
	GameControl = new Game();

	ResourceSystem = new ResourceManager();

	AddSpriteToResourceManager();

}

GameRenderer::~GameRenderer()
{
	if (ResourceSystem) 
	{
		delete ResourceSystem;
		ResourceSystem = nullptr;
	}

	if (GameControl)
	{
		delete GameControl;
		GameControl = nullptr;
	}

	if (Renderer) 
	{
		SDL_DestroyRenderer(Renderer);
	}

	if (GameWindow) 
	{
		SDL_DestroyWindow(GameWindow);
	}

}

void GameRenderer::Update(void)
{
	SDL_RenderClear(Renderer);

	GameControl->UpdatePlayerPosition();

	Draw(ResourceSystem->GetSpriteList());

	if (Renderer) 
	{
		SDL_RenderPresent(Renderer);
	}
	
	GameControl->eventSystem->EventCheck();
	//EventManager->EventCheck();
	SDL_Delay(16); //60 frames;
}

void GameRenderer::Draw(std::vector<std::pair<Bitmap*, std::string>> SpriteList)
{
	for (int i = 0; i < SpriteList.size(); i++) 
	{
		if (SpriteList[i].first->GetTexture()) 
		{
			//std::cout << SpriteList[i].first->tag << std::endl;
			if (SpriteList[i].first->tag != "player") 
			{
				//std::cout << "Not getting the player" << std::endl;
				SDL_Rect destRect = { SpriteList[i].first->GetxPos(),SpriteList[i].first->GetyPos(),SpriteList[i].first->GetSurface()->w,SpriteList[i].first->GetSurface()->h };
				SDL_RenderCopy(Renderer, SpriteList[i].first->GetTexture(), NULL, &destRect);
			}
			else 
			{
				//std::cout << "This is getting the player object" << std::endl;
				SDL_Rect destRect = { GameControl->GetPlayerXPos(),GameControl->GetPlayerYPos(),SpriteList[i].first->GetSurface()->w,SpriteList[i].first->GetSurface()->h };
				SDL_RenderCopy(Renderer, SpriteList[i].first->GetTexture(), NULL, &destRect);
			}
			
		}
	}
}

bool GameRenderer::CheckEventManagerForWindowClose()
{
	return GameControl->eventSystem->CloseWindowCheck();
}

void GameRenderer::AddSpriteToResourceManager()
{
	Bitmap* TempSprite = new Bitmap(Renderer,"Assets/mario.bmp", 100, 100);
	TempSprite->tag = "player";
	std::string SpriteLocation = "Assets/mario.bmp";
	ResourceSystem->AddBitmapToVector(std::make_pair(TempSprite, SpriteLocation));
}
