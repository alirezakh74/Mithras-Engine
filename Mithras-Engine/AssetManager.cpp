#include "AssetManager.h"

AssetManager::AssetManager(EntityManager* manager) : m_manager(manager)
{
}

AssetManager::~AssetManager()
{
}

void AssetManager::clearData()
{
	m_textures.clear();
}

void AssetManager::addTexture(std::string textureID, std::string fileName)
{
	//m_textures[textureID] = TextureMananger::loadTexture(fileName);
	m_textures.emplace(textureID, TextureMananger::loadTexture(fileName));
}

SDL_Texture* AssetManager::getTexture(std::string textureID)
{
	return m_textures[textureID];
}
