#pragma once
#include <memory>
#include <string>
#include "ResourceBase.h"
//Resource manager resource
template<class T>
class Resource: public ResourceBase
{
public:
	template<typename ...Args>
	Resource(const std::string & filename, Args... args) :ResourceBase(filename)
	{
		m_data = std::unique_ptr<T>(new T(filename.c_str(), args...));
	}
	~Resource() {};

	void* getData()
	{
		return m_data.get();
	}

private:
	std::unique_ptr<T> m_data;
};