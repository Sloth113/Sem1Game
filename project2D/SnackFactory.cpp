#include "SnackFactory.h"

SnackFactory::SnackFactory() {}

SnackFactory::~SnackFactory() {} 

void SnackFactory::addPrototype(std::shared_ptr<IPrototype> prototype) 
{
	m_prototypes.push_back(prototype);
}

std::shared_ptr<IPrototype> SnackFactory::create(const char* name) 
{ 
	for (std::shared_ptr<IPrototype> proto : m_prototypes) 
	{ 
		if (proto->getName().compare(name) == 0) 
		{
			return proto->clone();
		}
	}
	return nullptr; 
}