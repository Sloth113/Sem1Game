#include "FactoryPool.h"
FactoryPool::FactoryPool() {}

FactoryPool::~FactoryPool() {}
//Adds a prototype we can grab from later, when implementing into object pool create the pool when prototype is added
void FactoryPool::addPrototype(std::shared_ptr<IPrototype> prototype)
{
	m_prototypes.push_back(prototype);
}
//Makes a clone from the prototype
std::shared_ptr<IPrototype> FactoryPool::create(const char* name)
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