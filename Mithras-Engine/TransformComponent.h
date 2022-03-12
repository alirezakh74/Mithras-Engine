#pragma once

#include "Component.h"
#include "Vector2D.h"

class TransformComponent : public Component
{
public:

	Vector2D position;
	Vector2D velocity;
	Vector2D acceleration;
	float rotation;
	float scale;
	int width;
	int height;
	SDL_Renderer* m_renderer = NULL;

	void setRenderer(SDL_Renderer* renderer) { m_renderer = renderer; }

	TransformComponent()
	{
		rotation = 0;
		scale = 0;
		position = Vector2D(0.0f, 0.0f);
		velocity = Vector2D(0.0f, 0.0f);
		acceleration = Vector2D(0.0f, 0.0f);
		width = 0;
		height = 0;
	}

	TransformComponent(Vector2D pos, Vector2D velocity, Vector2D acceleration, int width, int height, float rotation, float scale)
	{
		this->position = pos;
		this->velocity = velocity;
		this->acceleration = acceleration;
		this->width = width;
		this->height = height;
		this->rotation = rotation;
		this->scale = scale;
	}


	~TransformComponent()
	{

	}

	virtual void init() override
	{

	}

	virtual void update(float deltaTime) override
	{
		velocity += acceleration * deltaTime;
		position += velocity * deltaTime;
	}

	virtual void render() override
	{
		SDL_SetRenderDrawColor(m_renderer, 100, 0, 0, 255);
		SDL_Rect rect = { (int)position.getX(), (int)position.getY(), width, height };
		SDL_RenderFillRect(Game::renderer, &rect);
	}

};
