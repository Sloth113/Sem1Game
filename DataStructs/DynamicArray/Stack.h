#pragma once
template<class T>
class Stack
{
public:
	Stack()
	{
		m_ar = new T[10];//Small default size
		m_cap = 10;
		m_top = -1;

		clearArray(m_ar, m_cap);
	}
	Stack(int cap)
	{
		m_ar = new T[cap];
		m_cap = cap;
		m_top = -1;
		clearArray(m_ar, m_cap);
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
		if (m_top >= 0)
		{
			T value = m_ar[m_top];
			m_ar[m_top] = NULL;
			m_top--;
			return value;
		}
		else
		{
			return 0;
		}
	}
	T top()
	{
		if (m_top < 0) return NULL;
		return m_ar[m_top];
	}

	void resize(int newSize)
	{
		T * newAr = new T[newSize];
		clearArray(newAr, newSize);
		for (int i = 0; i < m_cap; i++)
			newAr[i] = m_ar[i];//copy old;
		m_cap = newSize;
		delete[] m_ar;
		m_ar = newAr;
	}
	void clearArray(T * ar, int size)
	{
		for(int i =0; i < size; i ++)
		{
			ar[i] = NULL;
		}
	}

private:
	T * m_ar;
	int m_cap;
	int m_top;
};