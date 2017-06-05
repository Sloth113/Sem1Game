#pragma once
#include "Texture.h"
#include "Resource.h"

class ResourceTestObj
{
public:
	ResourceTestObj(aie::Texture * texture) : m_text(texture) {};
	~ResourceTestObj() {};

private:
	aie::Texture *  m_text;

};