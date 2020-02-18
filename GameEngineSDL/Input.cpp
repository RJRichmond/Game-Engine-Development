#include "Input.h"
Input::Input()
{
	for (size_t i = 0; i < SizeOfKeyEnum; i++) 
	{
		IsKeyPressed[i] = false;
	}
}

Input::~Input()
{
}

void Input::Update()
{
	while (SDL_PollEvent(&Event) != NULL) 
	{
		if (Event.type == SDL_KEYDOWN) 
		{
			SDL_Keycode KeyPressed = Event.key.keysym.sym;

			switch (KeyPressed) 
			{
			case SDLK_ESCAPE:
				IsKeyPressed[KEY_ESCAPE] = true;
				break;
			case SDLK_w:
				IsKeyPressed[KEY_W] = true;
				break;
			case SDLK_a:
				IsKeyPressed[KEY_A] = true;
				break;
			case SDLK_s:
				IsKeyPressed[KEY_S] = true;
				break;
			case SDLK_d:
				IsKeyPressed[KEY_D] = true;
				break;
			}
		}
		else if (Event.type == SDL_KEYUP)
		{
			SDL_Keycode KeyPressed = Event.key.keysym.sym;

			switch (KeyPressed) 
			{
			case SDLK_w:
				IsKeyPressed[KEY_W] = false;
				break;
			case SDLK_a:
				IsKeyPressed[KEY_A] = false;
				break;
			case SDLK_s:
				IsKeyPressed[KEY_S] = false;
				break;
			case SDLK_d:
				IsKeyPressed[KEY_D] = false;
				break;
			}
		}
	}
}

bool Input::CheckingIfKeyIsPressed(AvaliableKeys key)
{
	if (key == KEY_ESCAPE)
		return IsKeyPressed[KEY_ESCAPE];
	if (key == KEY_W)
		return IsKeyPressed[KEY_W];
	if (key == KEY_A)
		return IsKeyPressed[KEY_A];
	if (key == KEY_S)
		return IsKeyPressed[KEY_S];
	if (key == KEY_D)
		return IsKeyPressed[KEY_D];
	return false;
}

bool Input::CheckIfAnyKeyPressed()
{
	for (size_t i = 0; i < SizeOfKeyEnum; i++)
	{
		if (IsKeyPressed[i])
		{
			return true;
		}
	}
	return false;
}

size_t Input::GetAvaliableKeySize()
{
	return SizeOfKeyEnum;
}


