#pragma once

#include <vector>
#include <map>
#include <string>
#include <typeinfo>

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
	T& addComponent(TArgs&&... args)
	{
		T* newComponent(new T(std::forward<TArgs>(args)...));
		newComponent->owner = this;
		m_components.emplace_back(newComponent);
		mapComponentType[&typeid(*newComponent)] = newComponent;
		newComponent->init();
		return *newComponent;
	}

	template<typename T>
	T* getComponent()
	{
		return static_cast<T*>(mapComponentType[&typeid(T)]);
	}

	template<typename T>
	bool hasComponent()
	{
		for (auto map : mapComponentType)
		{
			//std::string mapFirst = map.first->name();
			//std::string typeID = typeid(T).name();
			if (map.first->name() == typeid(T).name())
			{
				return true;
			}
		}

		return false;
	}

	void update(float deltaTime);
	void render();
	void clean();
	bool isActive() const { return m_bIsActive; }

	std::vector<Component*> getComponents() const { return m_components; }
	std::map<const std::type_info*, Component*> mapComponentType;
	std::string  getName() const { return m_name; }

private:
	std::vector<Component*> m_components;
	EntityManager& m_manager;
	std::string m_name;
	bool m_bIsActive;
};
