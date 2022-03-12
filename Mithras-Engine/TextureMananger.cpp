#include "TextureMananger.h"

#include <SDL2/SDL_image.h>

#include "Game.h"

SDL_Texture* TextureMananger::loadTexture(std::string fileName)
{
	SDL_Surface* surface = IMG_Load(fileName.c_str());
	SDL_Texture* texture = SDL_CreateTextureFromSurface(Game::renderer, surface);
	SDL_FreeSurface(surface);
	return texture;
}

void TextureMananger::draw(SDL_Texture* texture, SDL_Rect srcRect, SDL_Rect destRect, SDL_RendererFlip flip)
{
	SDL_RenderCopyEx(Game::renderer, texture, &srcRect, &destRect, 0.0, NULL, flip);
}
