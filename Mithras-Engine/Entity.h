#pragma once

#include <vector>
#include <string>

#include "Component.h"
#include "EntityManager.h"

class EntityManager;

class Entity
{
public:
	Entity(EntityManager& manager);
	Entity(EntityManager& manager, std::string name);
	~Entity();

	template<typename T, typename... TArgs>
	T& addComponent(TArgs&& ... args);

	void update(float deltaTime);
	void render();
	void clean();
	bool isActive() const { return m_bIsActive; }

private:
	std::vector<Component*> m_components;
	EntityManager& m_manager;
	std::string m_name;
	bool m_bIsActive;
};
