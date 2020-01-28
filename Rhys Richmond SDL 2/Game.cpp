#include "Game.h"
#include "Bitmap.h"
#include "World.h"

void Game::UpdateText(std::string msg, int x, int y, TTF_Font* font, SDL_Color colour)
{
	SDL_Surface* surface = nullptr;
	SDL_Texture* texture = nullptr;

	int texW = 0;
	int texH = 0;

	surface = TTF_RenderText_Solid(font, msg.c_str(), colour);
	if (!surface) 
	{
		printf("SURFACE for font not loaded!\n");
		printf("%s\n", SDL_GetError());
	}
	else 
	{
		texture = SDL_CreateTextureFromSurface(m_Renderer, surface);
		if (!texture) 
		{
			printf("SURFACE for font not loaded!\n");
			printf("%s\n", SDL_GetError());
		}
		else 
		{
			SDL_QueryTexture(texture, NULL, NULL, &texW, &texH);
			SDL_Rect textRect = { x,y,texW,texH };
			SDL_RenderCopy(m_Renderer, texture, NULL, &textRect);

		}
	}
	if (texture) SDL_DestroyTexture(texture);

	if (surface) SDL_FreeSurface(surface);
}

Game::Game()
{
	m_Window = nullptr;
	m_Renderer = nullptr;
	WorldEntity = nullptr;

	SDL_Init(SDL_INIT_VIDEO);
	TTF_Init();

	m_Window = SDL_CreateWindow(
		"Display Window",
		250,
		50,
		640,
		480,
		0
		);

	if (!m_Window) 
	{
		printf("Window Initialisation failed: %s\n", SDL_GetError());
		printf("Press any key to continue\n");
		getchar();
		return;
	}

	m_Renderer = SDL_CreateRenderer(
		m_Window,
		-1,
		0
	);

	if (!m_Renderer) 
	{
		printf("Window Initialisation failed : % s\n", SDL_GetError());
		printf("Press any key to continue\n");
		getchar();
		return;
	}

	m_mario = new Bitmap(m_Renderer, "Assets/mario.bmp",100,100);
	m_marioTrans = new Bitmap(m_Renderer, "Assets/marioTrans.bmp", 200, 100);
	m_marioTransKeyed = new Bitmap(m_Renderer, "Assets/marioTrans.bmp", 300, 100, true);

	m_pSmallFont = TTF_OpenFont("Assets/LemonMilk.otf", 15);
	m_pBigFont = TTF_OpenFont("Assets/LemonMilk.otf", 50);
}

Game::~Game()
{
	if (m_Renderer)
	{
		SDL_DestroyRenderer(m_Renderer);
	}

	if (m_Window)
	{
		SDL_DestroyWindow(m_Window);
	}

	if (WorldEntity) delete WorldEntity;

	if (m_marioTransKeyed) delete m_marioTransKeyed;

	if (m_marioTrans) delete m_marioTrans;

	if (m_mario) delete m_mario;

	TTF_CloseFont(m_pBigFont);
	TTF_CloseFont(m_pSmallFont);
}

void Game::Update(void)
{
	SDL_RenderClear(m_Renderer);

	//m_monster->draw(0, 0);
	//m_monsterTrans->draw(0, 0);
	m_marioTransKeyed->draw(m_posX,m_posY);
	
	UpdateText("Do the mario!", 50, 1, m_pSmallFont, { 255,255,255 });

	if (m_Renderer)
	{
		SDL_RenderPresent(m_Renderer);
	}
	SDL_Delay(16);
	
}

void Game::SetDrawPos(int posX, int posY) 
{
	m_posX = posX;
	m_posY = posY;
}

void Game::CreatePlayer(World* World, int x, int y)
{
	
}

void Game::SetDisplayColour(int r, int g, int b, int a)
{
	if (m_Renderer)
	{

		int result = SDL_SetRenderDrawColor(
			m_Renderer,
			r,
			g,
			b,
			a
		);

		SDL_RenderClear(m_Renderer);

		SDL_RenderPresent(m_Renderer);
		//SDL_Delay(16);
	}
}







