#ifndef GAME_H
#define GAME_H
#include <SDL.h>
#include <stdio.h>
#include <string>
#include <SDL_ttf.h>
#include "World.h"

struct SDL_Window;
struct SDL_Renderer;
class Bitmap;

class Game 
{
private:
	SDL_Window* m_Window;
	SDL_Renderer *m_Renderer;

	Bitmap* m_mario;
	Bitmap* m_marioTrans;
	Bitmap* m_marioTransKeyed;

	TTF_Font* m_pSmallFont;
	TTF_Font* m_pBigFont;

	World* WorldEntity;

	void UpdateText(std::string msg, int x, int y, TTF_Font* font, SDL_Color colour);
public:
	Game();
	~Game();
	void Update(void);
	void SetDisplayColour(int r, int g, int b, int a);
	void SetDrawPos(int Posx, int PosY);
	void CreatePlayer(World* World, int x, int y);
	int m_posX = 0;
	int m_posY = 0;
};
#endif