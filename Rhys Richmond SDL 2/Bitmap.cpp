#include "Bitmap.h"
#include <string>
#include "SDL.h"
#include "SDL_render.h"



Bitmap::Bitmap(SDL_Renderer* renderer, std::string fileName, int xpos, int ypos, bool useTransparency)
{
	m_pRenderer = renderer;
	if (m_textureList.count(fileName)) 
	{
	
	}

	m_pbitmapSurface = SDL_LoadBMP(fileName.c_str());
	if (!m_pbitmapSurface) 
	{
		printf("Surface for bitmap '%s' not loaded \n", fileName.c_str());
		printf("%s\n", SDL_GetError());
	}
	else
	{
		if (useTransparency)
		{
			Uint32 colourKey = SDL_MapRGB(m_pbitmapSurface->format, 255, 0, 255);
			SDL_SetColorKey(m_pbitmapSurface, SDL_TRUE, colourKey);
		}
		m_pbitmapTexture = SDL_CreateTextureFromSurface(m_pRenderer, m_pbitmapSurface);
		if (!m_pbitmapTexture) 
		{
			printf("Texture for bitmap '%s' not loaded! \n", fileName.c_str());
			printf("%s\n", SDL_GetError());
		}
	}

	m_x = xpos;
	m_y = ypos;

}

Bitmap::~Bitmap()
{
	if (m_pbitmapTexture) 
	{
		SDL_DestroyTexture(m_pbitmapTexture);
	}
	if (m_pbitmapSurface) 
	{
		SDL_FreeSurface(m_pbitmapSurface);
	}
}

void Bitmap::draw(int posX,int posY)
{
	if (m_pbitmapTexture) 
	{
		SDL_Rect destRect = { posX,posY,m_pbitmapSurface->w,m_pbitmapSurface->h };
		SDL_RenderCopy(m_pRenderer, m_pbitmapTexture, NULL, &destRect);
	}
}
