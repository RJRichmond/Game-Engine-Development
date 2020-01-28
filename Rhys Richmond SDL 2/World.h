#pragma once

#include "Entity.h"

class World 
{
public:
	int EntityNumber = 0;
	std::list<Entity> EntityList;
	World();
	~World();
};
