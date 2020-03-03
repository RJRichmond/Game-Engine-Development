#pragma once

#include "EventSystem.h"

//Once box 2d is implemented this will go here, jump will not be touched for now as I need to use gravity for it.
//Collision checks will be coming from event system so game needs to inherit from it.


class Game 
{
public:
	Game();
	~Game();
	
	void UpdatePlayerPosition();
	void MakeCharacterJump();
	
	int GetPlayerXPos();
	int GetPlayerYPos();

	EventSystem* eventSystem;
private:

	int PlayerXPos;
	int PlayerYPos;
};
