#include "Entity.h"

Entity::Entity(EntityManager& manager) : m_manager(manager)
{
	m_bIsActive = true;
}

Entity::Entity(EntityManager& manager, std::string name) : m_manager(manager), m_name(name)
{
	m_bIsActive = true;
}

Entity::~Entity()
{
}

void Entity::update(float deltaTime)
{
	for (auto& component : m_components)
	{
		component->update(deltaTime);
	}
}

void Entity::render()
{
	for (auto& component : m_components)
	{
		component->render();
	}
}

void Entity::clean()
{
	m_bIsActive = false;
}

template<typename T, typename ...TArgs>
inline T& Entity::addComponent(TArgs&& ...args)
{
	T* newComponent(new T(std::forward<TArgs>(args)));
	newComponent->owner = this;
	components.emplace_back(newComponent);
	newComponent.init();
	return *newComponent;
}
