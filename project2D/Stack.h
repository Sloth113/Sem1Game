#pragma once
#include <assert.h>
//Stack using a implemented with dynamic array elements
template<class T>
class Stack
{
public:
	Stack()
	{
		m_ar = new T[10];//Small default size
		m_cap = 10;
		m_top = -1;
	}
	Stack(int cap)
	{
		m_ar = new T[cap];
		m_cap = cap;
		m_top = -1;
	}
	~Stack()
	{
		delete[] m_ar;
	}

	bool empty()
	{
		return this->isEmpty();
	}
	bool isEmpty()
	{
		return (m_top == -1);
	}
	int size()
	{
		return m_top + 1;
	}
	void push(T value)
	{
		m_top++;
		if (m_top == m_cap - 1)
		{
			this->resize(m_cap * 2);//double size
		}
		m_ar[m_top] = value;
	}
	T pop()
	{
		assert(m_top > 0 && "Stack is empty");
		T value = m_ar[m_top];
		m_top--;
		return value;
		
	}
	T top()
	{
		assert(m_top > 0 && "Stack is empty");
		return m_ar[m_top];
	}

	void resize(int newSize)
	{
		T * newAr = new T[newSize];
		for (int i = 0; i < m_cap; i++)
			newAr[i] = m_ar[i];//copy old;
		m_cap = newSize;
		delete[] m_ar;
		m_ar = newAr;
	}


private:
	T * m_ar;
	int m_cap;
	int m_top;
};