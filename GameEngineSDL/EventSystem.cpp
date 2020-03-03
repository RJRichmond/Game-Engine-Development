#include "EventSystem.h"
#include <string>
#include <iostream>

EventSystem::EventSystem()
{
	InputSystem = new Input();

	for (size_t i = 0; i < EventCount; i++)
	{
		IsEventActive[i] = false;
	}
}

EventSystem::~EventSystem()
{
	delete InputSystem;
	InputSystem = nullptr;
}

//Current the way of checking events by checking each event every frame but to run this every frame is demanding.
/*
for (size_t i = 0; i < EventCount; i++)
	{
		if (IsEventActive[i])
		{
			PerformEvent(i);
		}
	}
*/
void EventSystem::EventCheck()
{
	if (InputSystem)
	{
		InputSystem->Update();
		if (InputSystem->CheckIfAnyKeyPressed()) 
		{
			EventQueue.push(InputEvent);
		}
	}

	if (!EventQueue.empty()) 
	{
		if (EventQueue.front() == 0) 
		{
			PerformEvent(0);
			EventQueue.pop();
		}
		else if (EventQueue.front() == 1)
		{
			PerformEvent(1);
			EventQueue.pop();
		}
		else if (EventQueue.front() == 2)
		{
			PerformEvent(2);
			EventQueue.pop();
		}
	}
}

void EventSystem::PerformEvent(size_t EventNumber)
{
	
	if (EventNumber == 0) 
	{
		if (InputSystem)
		{
			if (InputSystem->CheckingIfKeyIsPressed(KEY_ESCAPE))
			{
				//Make the window close from this.
				WindowShouldClose = true;
				std::cout << "User has decided to close the window" << std::endl;
			}
			if (InputSystem->CheckingIfKeyIsPressed(KEY_W))
			{
				//Move stuff in each one of these.
				std::cout << "W" << std::endl;
			}
			if (InputSystem->CheckingIfKeyIsPressed(KEY_A))
			{
				PlayerPositionChange = -5;
				std::cout << "A" << std::endl;
			}
			if (InputSystem->CheckingIfKeyIsPressed(KEY_S))
			{
				std::cout << "S" << std::endl;
			}
			if (InputSystem->CheckingIfKeyIsPressed(KEY_D))
			{
				PlayerPositionChange = 5;
				std::cout << "D" << std::endl;
			}
		}
		else
		{
			std::cout << "Input system is not present, Massive failure" << std::endl;
		}
	}
	else if (EventNumber == 1) 
	{
		//This is where the Phyics and collision system update goes
		std::cout << "Physics and collision stuff is here" << std::endl;
	}
	else if(EventNumber == 2)
	{
		//Ai System update here
		std::cout << "AI Stuff goes here" << std::endl;
	}
}

bool EventSystem::CloseWindowCheck()
{
	if (WindowShouldClose) 
	{
		return true;
	}
	else 
	{
		return false;
	}
}

int EventSystem::GetPlayerPositionChange()
{
	return PlayerPositionChange;
}

void EventSystem::ResetPositionChange()
{
	PlayerPositionChange = 0;
}
