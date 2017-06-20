#pragma once
#include <vector>
#include <algorithm>
#include <functional>

#include <Texture.h>

template<class T>
class ObjectPool
{
	struct Data
	{
		bool active = false;
		T data;
	};
public:
	//ObjectPool(unsigned int size) :m_size(size), m_data(new Data[size]){	}
	ObjectPool(unsigned int size)
	{
		m_data.resize(size);
		for (int i = 0; i < size; i++)
		{
			m_data[i] = T();
		}
	}

	
	ObjectPool() {};

	~ObjectPool()
	{
		m_data.clear();
	}
	T * activate()
	{
		if (m_activeCount < m_data.size())
		{
			return m_data[m_activeCount++];
		}
		else
		{
			return nullptr;
		}
	}

	void deactivate(T * obj)
	{
		auto it = std::find(m_data.begin(), m_data.end(), obj);
		if (it != m_data.end())
		{
			auto index = std::distance(m_data.begin(), it);
			std::swap(m_data[index], m_data[m_activeCount - 1]);
			m_activeCount--;
		}
	}
	

	int activeCount()
	{
		return m_activeCount;
	}

	std::vector<T*> activeObjects()
	{
		return std::vector<T*>(m_data.begin(), m_data.begin() + m_activeCount);
		
	}
	typename std::vector<T*>::iterator begin()
	{
		return m_data.begin();
	}
	typename std::vector<T*>::iterator end()
	{
		return m_data.begin() + m_activeCount;
	}

	//CALLING FUNCTIONS WITH FUNCTINO POINTER 
	typedef void (T::*fn)();

	void callOnActive(fn func)
	{
		for(T* obj: *this)
		{
			object->*func();
		}
		//CALL USING 
		//POOL.callonactive(&obj::func);
	}

	
private:
	//unsigned int m_size = 0;
	//Data * m_data = nullptr;

	unsigned int m_activeCount = 0;
	std::vector<T*> m_data;

};