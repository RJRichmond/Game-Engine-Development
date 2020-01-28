#include "Input.h"
#include "Game.h"
#include <Iostream>

#undef main



int main(int argc, char* argv[]) 
{
	Game* game = new Game();
	Input* input = new Input();
	

	if (game && input) 
	{
		
		int posX = 100;
		int posY = 100;
		bool Upper = true;
		Uint8 r = 0, g = 0, b = 0, a = 255;
		while (!input->KeyIsPressed(KEY_ESCAPE))
		{
			input->Update();
			
			if (input->KeyIsPressed(KEY_R)) 
			{
				if (++r > 255) r = 0;
			}
			if (input->KeyIsPressed(KEY_G))
			{
				if (++g > 255) g = 0;
			}
			if (input->KeyIsPressed(KEY_B))
			{
				if (++b > 255) b = 0;
			}
			if (input->KeyIsPressed(KEY_D))	posX++;

			if (input->KeyIsPressed(KEY_A)) posX--;

			if (input->KeyIsPressed(KEY_S)) posY++;

			if (input->KeyIsPressed(KEY_W)) posY--;
			
			game->SetDrawPos(posX, posY);
			//game->SetDisplayColour(r, g, b, a);
			game->Update();
			
		}
		
		delete input;
		input = nullptr;
		delete game;
		game = nullptr;
	}
	return 0;
	SDL_Quit();
	
}