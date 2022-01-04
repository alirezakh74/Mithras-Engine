#pragma once

class Entity;

class Component
{
public:
	Entity* owner;

	virtual void init() = 0;
	virtual void update(float deltaTime) = 0;
	virtual void render() = 0;
};
