#pragma once

#include <map>
#include <string>

#include "TextureMananger.h"
#include "EntityManager.h"

class AssetManager
{
public:
	AssetManager(EntityManager* manager);
	~AssetManager();

	void clearData();
	void addTexture(std::string textureID, std::string fileName);
	SDL_Texture* getTexture(std::string textureID);

private:
	EntityManager* m_manager;
	std::map<std::string, SDL_Texture*> m_textures;
};

