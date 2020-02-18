#pragma once

#include <string>
#include <map>

struct SDL_Surface;
struct SDL_Texture;
struct SDL_Renderer;

class Bitmap
{
private:
	SDL_Surface* bitmapSurface;
	SDL_Texture* bitmapTexture;
	SDL_Renderer* renderer;

	int xPos;
	int yPos;

	std::map<std::string, std::string> textureList;
public:
	Bitmap(SDL_Renderer* Renderer,std::string fileName, int xpos, int ypos, bool useTransparency = false);
	~Bitmap();
	SDL_Surface* GetSurface();
	SDL_Texture* GetTexture();
	int GetxPos();
	int GetyPos();
};