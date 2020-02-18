#include "ResourceManager.h"

ResourceManager::ResourceManager()
{
	/*
	Create all of the sprites needed. Might want to get all of the locations before loading anything.
	That way when it takes the scene and it loads it, can go through take all of the sprites needed and load them accordingly.
	*/
	//To test to make sure it can draw the sprite I am going to be loading one sprite into the vector.
	//AddBitmap();
}

ResourceManager::~ResourceManager()
{
	for (int i = 0; i < SpriteList.size(); i++) 
	{
		SpriteList.back().first->~Bitmap();
		SpriteList.back().second.clear();
		SpriteList.pop_back();
	}
}

std::vector<std::pair<Bitmap*, std::string>> ResourceManager::GetSpriteList()
{
	return SpriteList;
}

void ResourceManager::AddBitmapToVector(std::pair<Bitmap*, std::string> NewElement)
{
	SpriteList.push_back(NewElement);
}


