#pragma once
#include <algorithm>

template<class T>
class DynArray
{
public:
	DynArray();

	DynArray(int size);
	~DynArray();
	DynArray(const DynArray &arr);

	T& operator = (const DynArray &other);
	T& operator[] (int index);

	void add(T item);
	void add(T item, int index); //Ordered
	void quickAdd(T item, int index);//Unordered
	void add(T  * items, int amount, int index);

	void pop();//Remove last
	void removeLast();
	void remove(int index);//Ordered
	void removeQuick(int index);//Unordered

	void changeSize(int newSize);

	void clear();

	void sort();//
//	void Sort(std::function<T(T, T)>);//send in sort condition

	int find(const T & item);

	void add(DynArray arr);//Add this array to 

	void shuffle();

	void rotate(int amount);
	void step();
	void backStep();
	int getSize();



private:
	T * m_array;
	int m_size;
	int m_used;
};


template<class T>
DynArray<T>::DynArray()
{
	m_array = new T[10];
	m_size = 10;
	m_used = 0;

}

template<typename T>
DynArray<T>::DynArray(int size)
{

	m_array = new T[size];
	m_size = size;
	m_used = 0;

}

template<typename T>
DynArray<T>::~DynArray()
{
	delete[] m_array;
}

template<typename T>
DynArray<T>::DynArray(const DynArray & arr)
{
	//Copy
	m_array = new T[arr.m_size];
	m_size = arr.m_size;
	m_used = arr.m_used;
	for (int i = 0; i < m_size; i++)
	{
		m_array[i] = arr.m_array[i];
	}
}

template<typename T>
T& DynArray<T>::operator=(const DynArray & arr)
{

	if (this == &arr) return *this;
	delete[] m_array;

	m_array = new T[arr.m_size];
	m_size = arr.m_size;
	m_used = arr.m_used;
	for (int i = 0; i < m_size; i++)
	{
		m_array[i] = arr.m_array[i];
	}
}

template<typename T>
T & DynArray<T>::operator[](int index)
{
	return m_array[index];
}

template<typename T>
void DynArray<T>::add(T item)
{
	if (m_used < m_size)
	{
		m_array[m_used] = item;
		m_used++;
	}
	else
	{
		this->changeSize(m_size * 2);//Make array bigger
		this->add(item);//Call add with this and new m_size
	}

}

template<typename T>
void DynArray<T>::add(T item, int index)
{
	//Check index >= 0 index < m_used
	if (m_used < m_size)
	{
		for (int i = m_used; i > index; i--)
		{
			m_array[i] = m_array[i - 1]; //Move everything over one
		}
		m_array[index] = item; //insert
		m_used++;
	}
	else
	{
		this->changeSize(m_size * 2);
		this->add(item);//Call add with this and new m_size
	}
}

template<class T>
inline void DynArray<T>::quickAdd(T item, int index)
{
	//Check index >= 0 index < m_used
	if (m_used < m_size)
	{
		m_array[m_used] = m_array[index];
		m_array[index] = item; //insert
		m_used++;
	}
	else
	{
		this->changeSize(m_size * 2);
		this->quickAdd(item);//Call add with this and new m_size
	}
}

template<typename T>
void DynArray<T>::add(T * items, int amount, int index)
{
	//Check index >= 0 index < m_used
	for (int i = index; i < (index + amount); i++)
	{
		this->add(items[i - index], i);
	}
}

template<typename T>
void DynArray<T>::pop()
{
	removeLast();
}

template<typename T>
void DynArray<T>::removeLast()
{
	m_used--;
	m_array[m_used] = NULL;
}

template<typename T>
void DynArray<T>::remove(int index)
{
	//Check index
	//Ordered
	for (int i = index; i < m_used; i++)
	{
		m_array[i] = m_array[i + 1];//Move everything
	}
	m_used--;
}

template<typename T>
void DynArray<T>::removeQuick(int index)
{
	m_used--;
	m_array[index] = m_array[m_used];
	m_array[m_used] = NULL;
}

template<typename T>
void DynArray<T>::changeSize(int newSize)
{
	m_size = newSize;
	T * newAr = new T[m_size];
	for (int i = 0; i < m_used; i++)
	{
		newAr[i] = m_array[i];
	}
	delete[] m_array;
	m_array = newAr;
}

template<typename T>
void DynArray<T>::clear()
{
	for (int i = 0; i < m_used; i++)
	{
		m_array[i] = NULL;
	}
	m_used = 0;
}

template<typename T>
void DynArray<T>::sort()
{
	for (int i = 0; i < m_used; i++)
	{
		for (int j = 0; j < m_used-1; j++)
		{
			if (m_array[j] > m_array[j + 1])
			{
				T tmp = m_array[j];
				m_array[j] = m_array[j + 1];
				m_array[j + 1] = tmp;
			}
		}
	}
}

//template<typename T>
//void myArray<T>::Sort(std::function<T(T, T)>)
//{
//}

template<typename T>
int DynArray<T>::find(const T & item)
{
	for(int i = 0; i < m_used; i++)
	{
		if(m_array[i] == item){
			return index;
		}
	}
	return -1;//Index cant be -1 so not found
}

template<typename T>
void DynArray<T>::add(DynArray arr)
{
	//Concatenating
	//not effeicent but works
	for (int i = 0; i < arr.m_used; i++)
	{
		this->Add(arr[i]);
	}
	
}

template<typename T>
void DynArray<T>::shuffle()
{
	std::random_shuffle(m_array, m_array+m_used);
}

template<typename T>
void DynArray<T>::rotate(int amount)
{
	if(amount < 0){
		for (int i = 0; i > amount; i--)
		{
			this->backStep();
		}
	}else{
		for (int i = 0; i < amount; i++)
		{
			this->step();
		}
	}
	
}

template<class T>
inline void DynArray<T>::step()
{
	T tmp = m_array[m_used - 1];
	for (int i = m_used-1; i > 0; i--)
	{
		m_array[i] = m_array[i-1];
	}
	m_array[0] = tmp;
}

template<class T>
inline void DynArray<T>::backStep()
{
	T tmp = m_array[0];
	for (int i = 0; i < m_used-1; i++)
	{
		m_array[i] = m_array[i + 1];
	}
	m_array[m_used-1] = tmp;
}

template<class T>
inline int DynArray<T>::getSize()
{
	return m_used;
}
