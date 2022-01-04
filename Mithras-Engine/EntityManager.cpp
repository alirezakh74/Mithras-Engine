#include "EntityManager.h"

void EntityManager::cleanData()
{
	for (auto& entity : m_entities)
	{
		entity->clean();
	}
}

Entity& EntityManager::addEntity(std::string entityName)
{
	Entity* entity = new Entity(*this, entityName);
	m_entities.emplace_back(entity);
	return *entity;
}

void EntityManager::update(float deltaTime)
{
	for (auto& entity : m_entities)
	{
		entity->update(deltaTime);
	}
}

void EntityManager::render()
{
	for (auto& entity : m_entities)
	{
		entity->render();
	}
}
