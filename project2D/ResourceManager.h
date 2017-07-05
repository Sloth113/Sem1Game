#pragma once
#include "Resource.h"
#include "Texture.h"
#include "Font.h"
#include "Audio.h"
#include <vector>
//Resource manager singleton class
class ResourceManager
{
private:

	std::vector<std::shared_ptr<ResourceBase>>m_resources;

	ResourceManager() {};
	ResourceManager(const ResourceManager&) {};
	ResourceManager& operator=(const ResourceManager&) {};

public:
	enum ResourceType
	{
		TEXTURE = 0,
		FONT,
		AUDIO
	};
	static ResourceManager& getInstance();
	~ResourceManager() {};
	std::shared_ptr<ResourceBase> get(const std::string filename, ResourceType type);
	void collectGarbage();
	int getCount();
};


/*  //pre-singlton tute
template<class T>
class ResourceManager
{
public:
	
	ResourceManager() {}
	~ResourceManager() {}

	std::shared_ptr<Resource<T>> get(const std::string filename) 
	{
		std::vector<std::shared_ptr<Resource<T>>>::iterator it;
		for(it = m_resources.begin(); it != m_resources.end(); it++)
		{
			if (filename.compare((*it)->getFileName()) == 0)
			{
				return (*it);
			}
		}
		std::shared_ptr<Resource<T>> resource(new Resource<T>(filename));
		m_resources.push_back(resource);

		return resource;
	}
	int getCount() 
	{
		return m_resources.size();
	}

	void collectGarbage()
	{
		for (std::vector<std::shared_ptr<Resource<T>>>::iterator it = m_resources.begin(); it != m_resources.end();)
		{
			if ((*it).use_count() == 1)
				it = m_resources.erase(it);
			else
				++it;
		}
	}

private:
	std::vector<std::shared_ptr<Resource<T>>> m_resources;

	ResourceManager(const ResourceManager &) {};
	ResourceManager& operator=(const ResourceManager&) {};

};
*/