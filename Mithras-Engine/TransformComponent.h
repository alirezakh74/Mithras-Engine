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

	TransformComponent()
	{
		rotation = 0;
		scale = 0;
		position = Vector2D(0.0f, 0.0f);
		velocity = Vector2D(0.0f, 0.0f);
		acceleration = Vector2D(0.0f, 0.0f);
	}

	~TransformComponent()
	{

	}

	virtual void update(float deltaTime) override
	{
		velocity += acceleration * deltaTime;
		position += velocity * deltaTime;
	}

	virtual void render() override
	{

	}

};
