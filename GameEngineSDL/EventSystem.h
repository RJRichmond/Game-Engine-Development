#pragma once
#include <iostream>
#include "Input.h"
#include <Queue>

enum Events //Order in this is the prio 
{
	InputEvent, CollisionEvent, AIUpdateEvent, CloseWindow, EventCount
};

class EventSystem
{
public:
	EventSystem();
	~EventSystem();
	void EventCheck();
	void PerformEvent(size_t EventNumber);
	bool CloseWindowCheck();
	int GetPlayerPositionChange();
	void ResetPositionChange();


private:
	bool IsEventActive[EventCount];
	bool WindowShouldClose;
	int PlayerPositionChange;
	Input* InputSystem;
	std::queue<int> EventQueue;
	
};