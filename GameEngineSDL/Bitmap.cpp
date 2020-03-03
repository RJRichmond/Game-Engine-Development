#include "Bitmap.h"
#include <string>
#include "SDL.h"
#include "SDL_render.h"


Bitmap::Bitmap(SDL_Renderer* Renderer,std::string fileName, int xpos, int ypos, bool useTransparency)
{
	tag = "";

	renderer = Renderer;
	if (textureList.count(fileName)) {}
	
	bitmapSurface = SDL_LoadBMP(fileName.c_str());

	if (!bitmapSurface) 
	{
		printf("Surface for bitmap '%s' not loaded \n", fileName.c_str());
		printf("%s\n", SDL_GetError());

	}
	else
	{
		if (useTransparency) 
		{
			Uint32 colourKey = SDL_MapRGB(bitmapSurface->format, 255, 0, 255);
			SDL_SetColorKey(bitmapSurface, SDL_TRUE, colourKey);
		}
		bitmapTexture = SDL_CreateTextureFromSurface(renderer, bitmapSurface);

		//textureList.insert(bitmapTexture, fileName);

		if (!bitmapTexture) 
		{
			printf("Texture for bitmap '%s' not loaded ! \n", fileName.c_str());
			printf("%s\n", SDL_GetError());
		}
	}
}

Bitmap::~Bitmap()
{
	if (bitmapTexture) 
		SDL_DestroyTexture(bitmapTexture);

	if (bitmapSurface)
		SDL_FreeSurface(bitmapSurface);
}

SDL_Surface* Bitmap::GetSurface()
{
	return bitmapSurface;
}

SDL_Texture* Bitmap::GetTexture()
{
	return bitmapTexture;
}

int Bitmap::GetxPos()
{
	return xPos;
}

int Bitmap::GetyPos()
{
	return yPos;
}
