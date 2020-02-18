#pragma once

#include <vector>
#include "Bitmap.h"
#include <utility>
#include <string>



class ResourceManager
{
public:
	ResourceManager();
	~ResourceManager();
	std::vector<std::pair<Bitmap*, std::string>> GetSpriteList();
	void AddBitmapToVector(std::pair<Bitmap*,std::string> NewElement);
private:
	std::vector<std::pair<Bitmap*, std::string>> SpriteList;  // Pair the bitmap with the file location.
	//Make more vectors for the other types of media.
};