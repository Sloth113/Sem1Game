#pragma once
#include <vector>
#include <memory>
#include "IPrototype.h"
//Made to serve as factory design method, future implementation with object pooling
class FactoryPool
{
public:
	FactoryPool();
	~FactoryPool();

	void addPrototype(std::shared_ptr<IPrototype> prototype);

	std::shared_ptr<IPrototype> create(const char* name);

private:
	std::vector<std::shared_ptr<IPrototype>> m_prototypes;
	std::vector<std::shared_ptr<IPrototype>> m_pool;
};