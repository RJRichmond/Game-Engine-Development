#pragma once

enum Events 
{
	InputEvent, CollisionEvent, AIUpdateEvent
};

class EventSystem 
{
public:
	EventSystem();
	~EventSystem();
	void EventCheck();
};