#pragma once

class Entity;

class Component
{
public:
	virtual ~Component() {}

	Entity* owner = NULL;

	virtual void init() = 0;
	virtual void update(float deltaTime) = 0;
	virtual void render() = 0;
};
