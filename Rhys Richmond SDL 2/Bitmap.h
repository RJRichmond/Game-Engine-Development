#pragma once

#include <string>
#include <map>

struct SDL_Surface;
struct SDL_Texture;
struct SDL_Renderer;

class Bitmap
{
private:
	SDL_Surface* m_pbitmapSurface;
	SDL_Texture* m_pbitmapTexture;
	SDL_Renderer* m_pRenderer;

	int m_x, m_y;
	std::map<std::string, std::string> m_textureList;


public:
	Bitmap(SDL_Renderer* renderer, std::string fileName, int xpos, int ypos, bool useTransparency = false);
	~Bitmap();
	

	void draw(int posX,int posY);
};