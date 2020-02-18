#include "SDL.h"
#include "GameRenderer.h"
#include <iostream>

#undef main

int main(void) 
{
	GameRenderer* GameRender = new GameRenderer();

	if (GameRender) 
	{
		while (!GameRender->CheckEventManagerForWindowClose()) 
		{
			GameRender->Update();
		}
	}
	return 0;
}