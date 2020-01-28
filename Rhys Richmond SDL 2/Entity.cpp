#include "Entity.h"

Entity::Entity(std::string EntityName, int PositionX, int PositionY)
{
	NameOfEntity = EntityName;
	LocationX = PositionX;
	LocationY = PositionY;

}

Entity::~Entity()
{
	
}
