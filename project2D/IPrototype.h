#pragma once
#include <string> 
#include <memory>
#include "defines.h"
//Prototype used for prototype design pattern
class IPrototype
{
public:
	virtual std::shared_ptr<IPrototype> clone() = 0;
	virtual std::string getName() = 0;
};