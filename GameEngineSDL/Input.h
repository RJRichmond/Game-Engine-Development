#pragma once

#include "SDL.h"
enum AvaliableKeys 
{
	KEY_ESCAPE, KEY_W, KEY_A, KEY_S, KEY_D, SizeOfKeyEnum
};

class Input 
{
public:
	void Update();
	bool CheckingIfKeyIsPressed(AvaliableKeys key);
	bool CheckIfAnyKeyPressed();
	size_t GetAvaliableKeySize();

	Input();
	~Input();

	
private:
	SDL_Event Event;
	bool IsKeyPressed[SizeOfKeyEnum];
};