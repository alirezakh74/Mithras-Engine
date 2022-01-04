#pragma once

#include <vector>

#include "Entity.h"

class EntityManager
{
public:

	void cleanData();
	Entity& addEntity(std::string entityName);
	std::vector<Entity*> getEntities() const { return m_entities; }

	void update(float deltaTime);
	void render();

	bool hasNoEntites() const { return m_entities.size() == 0; }
	unsigned int getEntityCount() const { return m_entities.size(); }
	
private:
	std::vector<Entity*> m_entities;
};

