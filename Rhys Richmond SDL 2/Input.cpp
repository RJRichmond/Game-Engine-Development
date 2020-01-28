#include "Input.h"
#include <Iostream>
Input::Input()
{
	for (size_t i = 0; i < SIZE_OF_KEYS_PRESSED_ENUM; i++)
	{
		m_keysPressed[i] = false;	
	}

}

Input::~Input()
{

}

void Input::Update(void)
{
	while (SDL_PollEvent(&m_event) != NULL) //change to forloop for 10 events.
	{
		if (m_event.type == SDL_KEYDOWN) 
		{
			SDL_Keycode keyPressed = m_event.key.keysym.sym;

			switch (keyPressed) 
			{
			case SDLK_ESCAPE:
				m_keysPressed[KEY_ESCAPE] = true;
				break;
			case SDLK_r:
				m_keysPressed[KEY_R] = true;
				break;
			case SDLK_g:
				m_keysPressed[KEY_G] = true;
				break;
			case SDLK_b:
				m_keysPressed[KEY_B] = true;
				break;
			case SDLK_d:
				m_keysPressed[KEY_D] = true;
				break;
			case SDLK_a:
				m_keysPressed[KEY_A] = true;
				break;
			case SDLK_s:
				m_keysPressed[KEY_S] = true;
				break;
			case SDLK_w:
				m_keysPressed[KEY_W] = true;
				break;
			}
		}
		else if (m_event.type == SDL_KEYUP) 
		{
			SDL_Keycode keyPressed = m_event.key.keysym.sym;

			switch (keyPressed) 
			{
			case SDLK_r:
				m_keysPressed[KEY_R] = false;
				break;
			case SDLK_g:
				m_keysPressed[KEY_G] = false;
				break;
			case SDLK_b:
				m_keysPressed[KEY_B] = false;
				break;
			case SDLK_d:
				m_keysPressed[KEY_D] = false;
				break;
			case SDLK_a:
				m_keysPressed[KEY_A] = false;
				break;
			case SDLK_s:
				m_keysPressed[KEY_S] = false;
				break;
			case SDLK_w:
				m_keysPressed[KEY_W] = false;
				break;
			}
		}
		
	}
}

bool Input::KeyIsPressed(KEYS_PRESSED_LIST key)
{
	if (key == KEY_ESCAPE)
	{
		return m_keysPressed[KEY_ESCAPE];
	}
	else if (key == KEY_R)
	{
		return m_keysPressed[KEY_R];
		
	}
	else if (key == KEY_G)
	{
		return m_keysPressed[KEY_G];
	}
	else if (key == KEY_B)
	{
		return m_keysPressed[KEY_B];
	}
	else if (key == KEY_D)
	{
		return m_keysPressed[KEY_D];
	}
	else if (key == KEY_A)
	{
		return m_keysPressed[KEY_A];
	}
	else if (key == KEY_S) 
	{
		return m_keysPressed[KEY_S];
	}
	else if (key == KEY_W)
	{
		return m_keysPressed[KEY_W];
	}
	return false;
}
