#include "Game.h"

Game::Game()
{
	eventSystem = new EventSystem();
}

Game::~Game()
{
	delete eventSystem;
	eventSystem = NULL;
}

void Game::UpdatePlayerPosition()
{
	PlayerXPos += eventSystem->GetPlayerPositionChange();
	eventSystem->ResetPositionChange();
}

void Game::MakeCharacterJump()
{
}

int Game::GetPlayerXPos()
{
	return PlayerXPos;
}

int Game::GetPlayerYPos()
{
	return PlayerYPos;
}
