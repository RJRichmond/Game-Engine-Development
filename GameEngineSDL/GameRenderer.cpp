#include "GameRenderer.h"


GameRenderer::GameRenderer()
{
	GameWindow = nullptr;
	Renderer = nullptr;

	SDL_Init(SDL_INIT_VIDEO);

	GameWindow = SDL_CreateWindow("Display Window", 250, 50, 640, 480, 0);

	Renderer = SDL_CreateRenderer(GameWindow, -1, 0);

	EventManager = new EventSystem();

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

	if (EventManager)
	{
		delete EventManager;
		EventManager = nullptr;
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

	Draw(ResourceSystem->GetSpriteList());

	if (Renderer) 
	{
		SDL_RenderPresent(Renderer);
	}
	
	EventManager->EventCheck();
	SDL_Delay(16); //60 frames;
}

void GameRenderer::Draw(std::vector<std::pair<Bitmap*, std::string>> SpriteList)
{
	for (int i = 0; i < SpriteList.size(); i++) 
	{
		if (SpriteList[i].first->GetTexture()) 
		{
			SDL_Rect destRect = { SpriteList[i].first->GetxPos(),SpriteList[i].first->GetyPos(),SpriteList[i].first->GetSurface()->w,SpriteList[i].first->GetSurface()->h };
			SDL_RenderCopy(Renderer, SpriteList[i].first->GetTexture(), NULL, &destRect);
		}
	}
}

bool GameRenderer::CheckEventManagerForWindowClose()
{
	return EventManager->CloseWindowCheck();
}

void GameRenderer::AddSpriteToResourceManager()
{
	Bitmap* TempSprite = new Bitmap(Renderer,"Assets/mario.bmp", 100, 100);
	std::string SpriteLocation = "Assets/mario.bmp";
	ResourceSystem->AddBitmapToVector(std::make_pair(TempSprite, SpriteLocation));
}
