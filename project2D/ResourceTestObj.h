#pragma once
#include "Texture.h"
#include "Resource.h"

class ResourceTestObj
{
public:
	ResourceTestObj(std::shared_ptr<Resource<aie::Texture>> texture) : m_text(texture) {};
	~ResourceTestObj() {};

private:
	std::shared_ptr<Resource<aie::Texture>> m_text;

};