#pragma once

#include <string>

#include <SDL2/SDL.h>

class TextureMananger
{
public:
	static SDL_Texture* loadTexture(std::string fileName);
	static void draw(SDL_Texture* texture, SDL_Rect srcRect, SDL_Rect destRect, SDL_RendererFlip flip);
};

