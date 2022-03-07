#pragma once

#include <vector>
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
		newComponent->init();
		return *newComponent;
	}

	template<typename T>
	T& getComponent()
	{
		for (auto& component : m_components)
		{
			//std::cout << "component type is: " << typeid(dynamic_cast<T*>(component)).name() << "\n";
			//std::cout << "component type is: " << typeid(T*).name() << "\n";
			if (typeid(dynamic_cast<T*>(component)) == typeid(T*))
			{
				return dynamic_cast<T&>(*component);
				//return (T&)(*component);
			}
		}

		//return NullComponent;
	}

	void update(float deltaTime);
	void render();
	void clean();
	bool isActive() const { return m_bIsActive; }

	std::vector<Component*> getComponents() const { return m_components; }
	std::string  getName() const { return m_name; }

private:
	std::vector<Component*> m_components;
	EntityManager& m_manager;
	std::string m_name;
	bool m_bIsActive;
};
