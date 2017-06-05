#pragma once
#include <string> 
#include <memory>

class IPrototype
{
public:
	virtual std::shared_ptr<IPrototype> clone() = 0;
	virtual std::string getName() = 0;
};