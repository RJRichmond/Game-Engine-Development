#pragma once
#include <string>
class Entity
{
private:
	std::string NameOfEntity;
	int LocationX = 0;
	int LocationY = 0;
public:
	Entity(std::string EntityName, int PositionX, int PositionY);
	~Entity();
};

