#pragma once

#include "Component.h"

#include <SDL2/SDL.h>

class SpriteComponent : public Component
{
public:

	SDL_Rect srcRect = { 0, 0, 0, 0 };
	SDL_Rect destRect = { 0, 0, 0, 0 };

	SpriteComponent()
	{

	}

	~SpriteComponent()
	{

	}

	virtual void init() override
	{
		srcRect = { 0, 0, 0, 0 };
		destRect = { 0, 0, 0, 0 };
	}

	virtual void update(float deltaTime) override
	{
	}

	virtual void render() override
	{
	}

};
