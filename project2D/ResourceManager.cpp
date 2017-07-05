#include "ResourceManager.h"
//Singleton class
ResourceManager& ResourceManager::getInstance()
{
	static ResourceManager instance;
	return instance;
}
//How to get resource, checks if name exists otherwise makes the object
std::shared_ptr<ResourceBase> ResourceManager::get(const std::string filename, ResourceType type)
{
	unsigned int index = 0;
	std::vector<std::shared_ptr<ResourceBase>>::iterator it;
	for(it = m_resources.begin(); it != m_resources.end();it++)
	{
		if (filename.compare((*it)->getFilename()) == 0)
		{
			return *it;
		}
	}
	switch (type)
	{
	case ResourceType::TEXTURE:
	{
		std::shared_ptr<ResourceBase> resource(new Resource<aie::Texture>(filename));
		m_resources.push_back(resource);
		return resource;
	}
	break;
	case ResourceType::FONT:
	{
		std::shared_ptr<ResourceBase> resource(new Resource<aie::Font>(filename,32));
		m_resources.push_back(resource);
		return resource;
	}
	break;
	case ResourceType::AUDIO:
	{
		std::shared_ptr<ResourceBase> resource(new Resource<aie::Audio>(filename));
		m_resources.push_back(resource);
		return resource;
	}
	break;
	default:
		return nullptr;
	}
}
//Cleans up shared pointer use
void ResourceManager::collectGarbage()
{
	for (std::vector<std::shared_ptr<ResourceBase>>::iterator it = m_resources.begin(); it != m_resources.end();)
	{
		if ((*it).use_count() >= 1)
			it = m_resources.erase(it);
		else
			++it;
	}
}

int ResourceManager::getCount()
{
	return m_resources.size();
}

